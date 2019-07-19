###########################################################################
### Frequency masker - subpixel fourier domain image filtering software ###
###########################################################################

Zdenek Hrazdira, summer 2019

The executable will probably need the following version of .NET framework to be installed on the machine:
.NET framework for Win8/10(v4.6.1):  https://dotnet.microsoft.com/download/dotnet-framework/net461

========================== < Buttons > ==========================
> LOAD
	- loads a master (source) image and displays all windows
> SAVE
	- saves the frequency filtered image (*.png or *.tif)
> CLOSE ALL
	- closes all windows
> RECALC
	- recalculates and refreshes all windows

========================= < Variables > =========================
FFT filter type (all filters have their "inverted" versions,
in the sense of x and 1-x
	- binary (ellipse), parameters center, radius1, radius2 
	- gaussian (ellipse), parameters center, radius1, radius2
	- unit (no filter)
	- binary (line), parameters center, radius1, radius2, thickness
	- gaussian (bandpass), parameters center, radius1
	- gaussian (line), parameters center, radius1, thickness

FFT log limit
	- variable used to visualize FT magnitude spectrum

heatmaps-F
	- applies "jet" colormap to the fourier domain (magn+phase)
	and absolute difference images

heatmaps-I
	- applies "jet" colormap to master and filtered images

radius1, radius2, thickness, center.x, center.y
	- filtering variables, see "FFT filter type" description

================== < How to change variables > ==================
Variables are changed either by clicking / mousewheel scrolling 
in the "masterFFT magn" window, or by the one of the four 
"Subpixel refinements" sliders +-(0-1). Each time a variable 
is changed by the user, an update is made and all filtering 
variable values are logged to the console.

radius1
	- mousewheel up and down while in the "masterFFT magn" window
	increases/decreases the value of radius1 parameter
	- for more precision, value can also be changed via the radius1 slider

radius2
	- shift key + mousewheel up and down while in the "masterFFT magn" 
	window increases/decreases the value of radius2 parameter
	- for more precision, value can also be changed via the radius2 slider
thickness
	- control key + mousewheel up and down while in the "masterFFT magn" 
	window increases/decreases the value of thickness parameter

center.x, center.y
	- clicking anywhere in the "masterFFT magn" window changes 
	the center.x and center.y values accordingly
	- for more precision, value can also be changed via the center.x/y slider
