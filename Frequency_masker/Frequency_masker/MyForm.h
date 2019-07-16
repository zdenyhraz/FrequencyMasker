#pragma once
#include "functions.h"

//<globals>
mainData* dataa = new mainData;
//</globals>

namespace Template {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace cv;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button6;
	protected:

protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(368, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"LOAD";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Engravers MT", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label1->Location = System::Drawing::Point(4, 207);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(442, 34);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Frequency Masker";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(15, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"FFT log limit";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Location = System::Drawing::Point(84, 39);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1661992960, 1808227885, 5, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(80, 20);
			this->numericUpDown1->TabIndex = 7;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(7, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"FFT filter type";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"binary (ellipse)", L"binary (ellipse) inverted",
					L"gaussian (ellipse) inverted", L"gaussian (ellipse)", L"unit (no filter)", L"binary (line)", L"binary (line) inverted", L"gaussian (bandpass)",
					L"gaussian (bandpass) inverted", L"gaussian (line)", L"gaussian (line) inverted"
			});
			this->comboBox1->Location = System::Drawing::Point(84, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(183, 21);
			this->comboBox1->TabIndex = 10;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(368, 90);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"DEBUG";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(368, 65);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 13;
			this->button5->Text = L"CLOSE ALL";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(84, 65);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &MyForm::checkBox1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(25, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"heatmaps";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(192, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"TEST";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(60, 118);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 45);
			this->trackBar1->TabIndex = 17;
			this->trackBar1->Value = 50;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar1_ValueChanged);
			this->trackBar1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::trackBar1_MouseUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(13, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"radius1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(170, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"10";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(170, 168);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(19, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"30";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(13, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"radius2";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(60, 159);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(104, 45);
			this->trackBar2->TabIndex = 20;
			this->trackBar2->Value = 50;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar2_ValueChanged);
			this->trackBar2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::trackBar2_MouseUp);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(364, 168);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 13);
			this->label9->TabIndex = 28;
			this->label9->Text = L"123";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(207, 168);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(45, 13);
			this->label10->TabIndex = 27;
			this->label10->Text = L"center.y";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(254, 159);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(104, 45);
			this->trackBar3->TabIndex = 26;
			this->trackBar3->Value = 50;
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar3_ValueChanged);
			this->trackBar3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::trackBar3_MouseUp);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(364, 127);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"123";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(207, 127);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(45, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"center.x";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(254, 118);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(104, 45);
			this->trackBar4->TabIndex = 23;
			this->trackBar4->Value = 50;
			this->trackBar4->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar4_ValueChanged);
			this->trackBar4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::trackBar4_MouseUp);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label13->ForeColor = System::Drawing::Color::Transparent;
			this->label13->Location = System::Drawing::Point(134, 97);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(153, 18);
			this->label13->TabIndex = 29;
			this->label13->Text = L"Subpixel refinements";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(25, 78);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(60, 13);
			this->label14->TabIndex = 31;
			this->label14->Text = L"heatmapsP";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(84, 78);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(80, 17);
			this->checkBox2->TabIndex = 30;
			this->checkBox2->Text = L"checkBox2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Click += gcnew System::EventHandler(this, &MyForm::checkBox2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(368, 36);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 32;
			this->button3->Text = L"SAVE";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(192, 65);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 33;
			this->button6->Text = L"RECALC";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(454, 250);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//<custom #defines>
#define Floglimit stod(msclr::interop::marshal_as<std::string>(numericUpDown1->Text))
#define Ffiltertype comboBox1->SelectedIndex
#define Fheatmaps checkBox1->Checked
#define FheatmapsP checkBox2->Checked
#define FradInner trackBar1->Value
#define FradOuter trackBar2->Value
#define FcenterX trackBar4->Value
#define FcenterY trackBar3->Value

//<\custom #defines>

void refreshData(mainData& data, bool refresh)
{
	data.loglimit = Floglimit;
	data.filterType = Ffiltertype;
	data.heatmaps = Fheatmaps;
	data.heatmapsP = FheatmapsP;
	data.radius1 += ((double)FradInner - 50.) / 50.;
	data.radius2 += ((double)FradOuter - 50.) / 50.;
	data.center.x += ((double)FcenterX - 50.) / 50.;
	data.center.y += ((double)FcenterY - 50.) / 50.;

	if (refresh) compute(*dataa);
	if (refresh) show(*dataa);
	data.logConsole();
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ pathsys = openFileDialog1->FileName;
		bool succload;
		std::string path = msclr::interop::marshal_as<std::string>(pathsys);
		cout << "> File " << path << " loaded." << endl;

		Mat temp = imread(path, IMREAD_ANYDEPTH);

		temp.convertTo(temp, CV_64F);
		normalize(temp, temp, 0, 1, CV_MINMAX);
		dataa->master = temp;
		dataa->Rows = temp.rows;
		dataa->Cols = temp.cols;
		dataa->maskFFT = Mat::ones(dataa->Rows, dataa->Cols, CV_64F);
		refreshData(*dataa,0);
		namedWindow("masterFFT magn", WINDOW_NORMAL);
		setMouseCallback("masterFFT magn", CallBackFunc, dataa);
		compute(*dataa);
		show(*dataa, 1);
	}
}
	
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Mat crop = roicrop(dataa->master, dataa->Cols*0.85, dataa->Rows*0.75, dataa->Cols *0.3, dataa->Rows*0.5).clone();
	if (0)
	{
		Mat hann;
		createHanningWindow(hann, cv::Size(crop.cols, crop.rows), CV_64F);
		crop = crop.mul(hann);
	}
	Mat cropExt;
	int borderX = (dataa->Cols - crop.cols) / 2;
	int borderY = (dataa->Rows - crop.rows) / 2;

	copyMakeBorder(crop, cropExt, borderY, borderY+1, borderX, borderX, BORDER_CONSTANT, 0);
	cout << "Master size: " << dataa->master.size() << endl;
	cout << "CropExt size: " << cropExt.size() << endl;
	dataa->master = cropExt;
	dataa->Rows = cropExt.rows;
	dataa->Cols = cropExt.cols;
	dataa->maskFFT = Mat::ones(dataa->Rows, dataa->Cols, CV_64F);
	refreshData(*dataa, 0);
	namedWindow("masterFFT magn", WINDOW_NORMAL);
	setMouseCallback("masterFFT magn", CallBackFunc, dataa);
	compute(*dataa);
	show(*dataa, 1);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
{
	destroyAllWindows();
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa,1);
}

private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa,1);
}
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa,1);
}
private: System::Void checkBox1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa,1);
}
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) 
{
	Mat temp = imread("sample.jpg", IMREAD_ANYDEPTH);
	temp.convertTo(temp, CV_64F);
	normalize(temp, temp, 0, 1, CV_MINMAX);
	dataa->master = temp;
	dataa->Rows = temp.rows;
	dataa->Cols = temp.cols;
	dataa->maskFFT = Mat::ones(dataa->Rows, dataa->Cols, CV_64F);
	refreshData(*dataa,0);
	namedWindow("masterFFT magn", WINDOW_NORMAL);
	setMouseCallback("masterFFT magn", CallBackFunc, dataa);
	compute(*dataa);
	show(*dataa, 1);
}

private: System::Void numericUpDown2_ValueChanged_1(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa,1);
}
private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	label6->Text = (((double)FradInner - 50.) / 50.).ToString();
}
private: System::Void trackBar1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	refreshData(*dataa,1);
	trackBar1->Value = 50;
	label6->Text = dataa->radius1.ToString();
}
private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	label7->Text = (((double)FradOuter - 50.) / 50.).ToString();
}
private: System::Void trackBar2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	refreshData(*dataa,1);
	trackBar2->Value = 50;
	label7->Text = dataa->radius2.ToString();
}
private: System::Void trackBar4_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	label11->Text = (((double)FcenterX - 50.) / 50.).ToString();
}
private: System::Void trackBar4_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	refreshData(*dataa, 1);
	trackBar4->Value = 50;
	label11->Text = (dataa->center.x - dataa->Cols / 2).ToString();
}
private: System::Void trackBar3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	refreshData(*dataa, 1);
	trackBar3->Value = 50;
	label9->Text = (dataa->center.y - dataa->Rows / 2).ToString();
}
private: System::Void trackBar3_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	label9->Text = (((double)FcenterY - 50.) / 50.).ToString();
}
private: System::Void checkBox2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa, 1);
}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) 
{
	saveFileDialog1->Filter = "png (*.png)|*.png|tif (*.tif)|*.tif";
	saveFileDialog1->Title = "Save the filtered image";
	saveFileDialog1->FilterIndex = 0;
	saveFileDialog1->RestoreDirectory = true;
	saveFileDialog1->ShowDialog();

	{
		if (saveFileDialog1->FileName != "")
		{
			System::String^ pathsys = saveFileDialog1->FileName;
			std::string path = msclr::interop::marshal_as<std::string>(pathsys);
			Mat filteredToSave = dataa->filtered.clone();
			normalize(filteredToSave, filteredToSave, 0, 65535, CV_MINMAX);
			filteredToSave.convertTo(filteredToSave, CV_16U);
			//showimg(filteredToSave, "image to be saved:", 0, 0, 1, 0, 1);
			imwrite(path, filteredToSave);
			cout << ">> Filtered image saved - " << path << endl;
		}
	}
}

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
{
	refreshData(*dataa, 1);
}
};
}
