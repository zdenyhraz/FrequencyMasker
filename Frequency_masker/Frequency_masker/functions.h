#pragma once
#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <stdint.h>
#include <chrono>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <filesystem>
#include <msclr\marshal_cppstd.h>

using namespace cv;
using namespace std;

struct mainData
{
	Mat master;
	int Rows = 123;
	int Cols = 123;
	Mat maskFFT;
	Point2d center = Point2d(123., 123.);
	Mat masterFFTmagn;
	Mat masterFFTphase;
	Mat filtered;
	double radius1 = 10;
	double radius2 = 30;
	double thickness = 5;
	bool heatmaps = 1;
	bool heatmapsP = 0;
	int filterType = 0;
	double loglimit = 10000;

	void logConsole()
	{
		cout << "FFT filter parameters: radius1: " << radius1 << ", radius2: " << radius2 << ", thickness: " << thickness << ", centerX: " << center.x << ", centerY: " << center.y << endl;
	}
};

Mat fourier(const Mat& sourceimg)
{
	Mat sourceimgcomplex[2] = { sourceimg, Mat::zeros(sourceimg.size(), CV_64F) };
	Mat sourceimgcomplexmerged;
	merge(sourceimgcomplex, 2, sourceimgcomplexmerged);
	dft(sourceimgcomplexmerged, sourceimgcomplexmerged);
	return sourceimgcomplexmerged;
}

inline double clamp(double x, double clampMin = 0, double clampMax = 255)
{
	return min(max(x, clampMin), clampMax);
}

Mat applyColorMapZdeny(const Mat& src, double quantileB = 0, double quantileT = 1)
{
	Mat sourceimg = src.clone();
	//input is grayscale, output is colored
	double caxisMin = 0, caxisMax = 255;
	Mat sourceimgOut(sourceimg.rows, sourceimg.cols, CV_8UC3);

	normalize(sourceimg, sourceimg, 0, 255, CV_MINMAX);
	sourceimg.convertTo(sourceimg, CV_8U);
	//fill picvalues vector
	if ((quantileB > 0) || (quantileT < 1))
	{
		vector<int> picvalues(sourceimg.rows*sourceimg.cols, 0);
		//#pragma omp parallel for
		for (int r = 0; r < sourceimg.rows; r++)
		{
			for (int c = 0; c < sourceimg.cols; c++)
			{
				picvalues[r*sourceimg.cols + c] = sourceimg.at<uchar>(r, c);
			}
		}

		//sort the vector
		sort(picvalues.begin(), picvalues.end());

		//calculate the alpha and 1-alpha quantiles
		int alpha1Quantile = picvalues[round(quantileB*(picvalues.size() - 1))];
		int alpha2Quantile = picvalues[round(quantileT*(picvalues.size() - 1))];
		caxisMin = (double)alpha1Quantile;
		caxisMax = (double)alpha2Quantile;
	}

	//calculate colormap RGB values
	double sh = 0.125 * (caxisMax - caxisMin);
	double start = caxisMin;
	double mid = caxisMin + 0.5*(caxisMax - caxisMin);
	double end = caxisMax;

	#pragma omp parallel for
	for (int r = 0; r < sourceimgOut.rows; r++)
	{
		for (int c = 0; c < sourceimgOut.cols; c++)
		{
			double x = sourceimg.at<uchar>(r, c);
			double B = 0, G = 0, R = 0;

			B = (x > (start + sh)) ? clamp(-127.5 / sh * x + 127.5 / sh * (mid + sh)) : (x < start ? 127.5 : clamp(127.5 / sh * x + 127.5 - 127.5 / sh * start));
			G = (x < mid) ? clamp(127.5 / sh * x - 127.5 / sh * (start + sh)) : clamp(-127.5 / sh * x + 127.5 / sh * (end - sh));
			R = (x < (end - sh)) ? clamp(127.5 / sh * x - 127.5 / sh * (mid - sh)) : (x > end ? 127.5 : clamp(-127.5 / sh * x + 127.5 + 127.5 / sh * end));

			sourceimgOut.at<Vec3b>(r, c)[0] = round(B);
			sourceimgOut.at<Vec3b>(r, c)[1] = round(G);
			sourceimgOut.at<Vec3b>(r, c)[2] = round(R);
		}
	}
	return sourceimgOut;
}

void showimg(const Mat& src, std::string windowname, bool color = false, double quantileB = 0, double quantileT = 1, bool stretch = false, bool createWindow = false)
{
	Mat sourceimg = src.clone();
	double RowColRatio = (double)sourceimg.rows / (double)sourceimg.cols;
	int namedWindowRows = 600;
	int namedWindowCols = (double)namedWindowRows / RowColRatio;
	if (createWindow) namedWindow(windowname, WINDOW_NORMAL);
	if (createWindow) resizeWindow(windowname, stretch ? 600 : namedWindowCols, namedWindowRows);
	sourceimg.convertTo(sourceimg, CV_64F);
	normalize(sourceimg, sourceimg, 0, 1, CV_MINMAX);
	if (color)
	{
		sourceimg = applyColorMapZdeny(sourceimg, quantileB, quantileT);
	}
	imshow(windowname, sourceimg);
	waitKey(1);
}

Mat quadrantswap(Mat& sourceimgDFT)
{
	Mat centeredDFT;
	sourceimgDFT.copyTo(centeredDFT);
	int centerX = sourceimgDFT.cols / 2;
	int centerY = sourceimgDFT.rows / 2;
	Mat q1(centeredDFT, Rect(0, 0, centerX, centerY));
	Mat q2(centeredDFT, Rect(centerX, 0, centerX, centerY));
	Mat q3(centeredDFT, Rect(0, centerY, centerX, centerY));
	Mat q4(centeredDFT, Rect(centerX, centerY, centerX, centerY));
	Mat temp;

	q1.copyTo(temp);
	q4.copyTo(q1);
	temp.copyTo(q4);

	q2.copyTo(temp);
	q3.copyTo(q2);
	temp.copyTo(q3);
	return centeredDFT;
}

Mat roicrop(Mat sourceimg, int x, int y, int w, int h)//x,y souradnice stredu, rows, cols
{
	Rect roi = Rect(x - std::floor((double)w / 2.), y - std::floor((double)h / 2.), w, h);
	Mat crop = sourceimg(roi);
	return crop;
}

Mat binarianInverted(int rows, int cols, Point2d center, double radius1, double radius2)
{
	Mat binarian = Mat::zeros(rows, cols, CV_64F);
	ellipse(binarian, center, cv::Size(radius1, radius2), 0, 0, 360, Scalar(1), -1);
	binarian = Scalar::all(1.) - binarian;
	Mat binarian2 = binarian.clone();
	Point2f pt = Point2f(binarian.cols / 2, binarian.rows / 2);
	Mat r = getRotationMatrix2D(pt, 180, 1);
	warpAffine(binarian2, binarian2, r, binarian2.size());
	Mat result = binarian.mul(binarian2);
	return result;
}

Mat binarian(int rows, int cols, Point2d center, double radius1, double radius2)
{
	return Scalar::all(1.) - binarianInverted(rows, cols, center, radius1, radius2);
}

Mat linian(int rows, int cols, Point2d center, double thickness)
{
	Mat linian = Mat::zeros(2 * rows, 2 * cols, CV_64F);
	double angle = atan2(center.y - rows / 2, center.x - cols / 2);
	angle *= (360. / 2. / 3.14159265359);
	int thc = thickness;
	rectangle(linian, Point2d(cols - thc, 2 * rows), Point2d(cols + thc, 0), Scalar(1), -1);
	Point2f pt = Point2f(linian.cols / 2, linian.rows / 2);
	Mat r = getRotationMatrix2D(pt, -angle + 90, 1);
	warpAffine(linian, linian, r, linian.size());
	normalize(linian, linian, 0, 1, CV_MINMAX);
	return roicrop(linian, linian.cols / 2, linian.rows / 2, cols, rows);
}

Mat linianInverted(int rows, int cols, Point2d center, double radius1, double radius2, double thickness)
{
	Mat liniann = linian(rows, cols, center, thickness);
	liniann = Scalar::all(1) - liniann;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (sqrt(pow(x - cols/2, 2) + pow(y - rows/2, 2)) < radius1)
			{
				liniann.at<double>(y, x) = 1;
			}	
			if (sqrt(pow(x - cols / 2, 2) + pow(y - rows / 2, 2)) > radius2)
			{
				liniann.at<double>(y, x) = 1;
			}	
		}
	}
	return liniann;
}

Mat laplacian(int rows, int cols, Point2d center, double stdevY, double stdevX)
{
	Mat gaussian = Mat::zeros(rows, cols, CV_64F);
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			gaussian.at<double>(y, x) = 1. - (std::exp(-(std::pow(x - center.x, 2) / 2 / std::pow(stdevX, 2) + std::pow(y - center.y, 2) / 2 / std::pow(stdevY, 2))));
		}
	}
	normalize(gaussian, gaussian, 0, 1, CV_MINMAX);
	Mat gaussian2 = gaussian.clone();
	Point2f pt = Point2f(gaussian.cols / 2, gaussian.rows / 2);
	Mat r = getRotationMatrix2D(pt, 180, 1);
	warpAffine(gaussian2, gaussian2, r, gaussian2.size());
	Mat result = gaussian.mul(gaussian2);
	return result;
}

Mat gaussian(int rows, int cols, Point2d center, double stdevY, double stdevX)
{
	Mat gaussian = Mat::zeros(rows, cols, CV_64F);
	gaussian = Scalar::all(1) - laplacian(rows, cols, center, stdevY, stdevX);
	return gaussian;
}

Mat bandpassian(int rows, int cols, Point2d center, double stddev)
{
	Mat bandpassian = Mat::zeros(rows, cols, CV_64F);
	Point2d mid = Point2d(cols / 2, rows / 2);
	double radiusCenter = sqrt(pow(center.x - mid.x, 2) + pow(center.y - mid.y, 2));

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			double radiusTemp = sqrt(pow(x - mid.x, 2) + pow(y - mid.y, 2));
			bandpassian.at<double>(y, x) = std::exp(-(std::pow(radiusTemp - radiusCenter, 2) / 2 / std::pow(stddev, 2)));
		}
	}
	return bandpassian;
}

Mat bandpassianInverted(int rows, int cols, Point2d center, double stddev)
{
	return Scalar::all(1.) - bandpassian(rows, cols, center, stddev);
}

Mat linianGauss(int rows, int cols, Point2d center, double stddev, double thickness)
{
	Mat bandpassiaN = bandpassian(rows, cols, center, stddev);
	Mat liniaN = linian(rows, cols, center, thickness);
	return liniaN.mul(bandpassiaN);
}

Mat linianLaplace(int rows, int cols, Point2d center, double stddev, double thickness)
{
	Mat liniaNGauss = linianGauss(rows, cols, center, stddev, thickness);
	return Scalar::all(1.) - liniaNGauss;
}

void compute(mainData& data)
{
	if (data.filterType == 0)
		data.maskFFT = binarian(data.Rows, data.Cols, data.center, data.radius1, data.radius2);
	if (data.filterType == 1)
		data.maskFFT = binarianInverted(data.Rows, data.Cols, data.center, data.radius1, data.radius2);
	if (data.filterType == 2)
		data.maskFFT = laplacian(data.Rows, data.Cols, data.center, data.radius1, data.radius2);
	if (data.filterType == 3)
		data.maskFFT = gaussian(data.Rows, data.Cols, data.center, data.radius1, data.radius2);
	if (data.filterType == 4)
		data.maskFFT = Mat::ones(data.Rows, data.Cols, CV_64F);
	if (data.filterType == 5)
		data.maskFFT = linian(data.Rows, data.Cols, data.center, data.thickness);
	if (data.filterType == 6)
		data.maskFFT = linianInverted(data.Rows, data.Cols, data.center, data.radius1, data.radius2, data.thickness);
	if (data.filterType == 7)
		data.maskFFT = bandpassian(data.Rows, data.Cols, data.center, data.radius1);
	if (data.filterType == 8)
		data.maskFFT = bandpassianInverted(data.Rows, data.Cols, data.center, data.radius1);
	if (data.filterType == 9)
		data.maskFFT = linianGauss(data.Rows, data.Cols, data.center, data.radius1, data.thickness);
	if (data.filterType == 10)
		data.maskFFT = linianLaplace(data.Rows, data.Cols, data.center, data.radius1, data.thickness);
	if (data.filterType == -1)
		data.maskFFT = Mat::ones(data.Rows, data.Cols, CV_64F);

	Mat masterFFT = fourier(data.master);
	Mat planes[2];
	split(masterFFT, planes);
	cartToPolar(planes[0], planes[1], data.masterFFTmagn, data.masterFFTphase);
	Mat filteredFFTmagn = data.masterFFTmagn.mul(quadrantswap(data.maskFFT));
	polarToCart(filteredFFTmagn, data.masterFFTphase, planes[0], planes[1]);
	Mat filteredFFT;
	merge(planes, 2, filteredFFT);
	dft(filteredFFT, data.filtered, DFT_INVERSE + DFT_SCALE + DFT_REAL_OUTPUT);
	normalize(data.filtered, data.filtered, 0, 1, CV_MINMAX);
	cout << "> Frequency filtering performed." << endl;
}

void show(mainData& data, bool createWin = false)
{
	showimg(data.master, "master", data.heatmapsP, 0.01, 0.99, 0, createWin);
	showimg(data.filtered, "master filtered", data.heatmapsP, 0.01, 0.99, 0, createWin);
	showimg(abs(data.master - data.filtered), "diff", data.heatmaps, 0, 1, 0, createWin);
	showimg(data.maskFFT, "FFT mask", data.heatmaps, 0, 1, 0, createWin);
	showimg(quadrantswap(data.masterFFTphase), "masterFFT phase", data.heatmaps, 0, 1, 0, createWin);

	Mat tempMagn = data.masterFFTmagn;
	tempMagn = quadrantswap(tempMagn);
	tempMagn = tempMagn.mul(data.maskFFT);
	normalize(tempMagn, tempMagn, 1, data.loglimit + 1, CV_MINMAX);
	log(tempMagn, tempMagn);
	showimg(tempMagn, "masterFFT magn", data.heatmaps, 0, 1, 0, createWin);
}


void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	mainData* data = (mainData*)userdata;
	if (event == EVENT_LBUTTONDOWN)
	{
		data->center.x = x;
		data->center.y = y;

		compute(*data);
		show(*data);
		data->logConsole();
	}
	if (event == EVENT_MOUSEWHEEL)
	{
		int mwd = getMouseWheelDelta(flags);

		if (flags & EVENT_FLAG_SHIFTKEY)
		{
			if (mwd > 0)
				data->radius2 += 1;
			else
				data->radius2 -= 1;

			if (data->radius2 < 0)
				data->radius2 = 0;
		}
		else if (flags & EVENT_FLAG_CTRLKEY)
		{
			if (mwd > 0)
				data->thickness += 1;
			else
				data->thickness -= 1;

			if (data->thickness < 0)
				data->thickness = 0;
		}
		else
		{
			if (mwd > 0)
				data->radius1 += 1;
			else
				data->radius1 -= 1;

			if (data->radius1 < 0)
				data->radius1 = 0;
		}
		data->logConsole();
	}
}