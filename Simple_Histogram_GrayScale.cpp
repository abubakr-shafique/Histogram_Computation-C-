//This Program is written by Abubakr Shafique (abubakr.shafique@gmail.com)
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){

	Mat Input_Image = imread("Test_Image.png",0); // Read an Image in GrayScale
	int Image_Height = Input_Image.size().height; // Get the Height of the Input Image
	int Image_Width = Input_Image.size().width; // Get the Width of the Input Image

	int Histogram_GrayScale[256] = { 0 }; //Initialize a Histogram array with zeros

	for (int x = 0; x < Image_Width; x++)//looping to scan all pixels in our image
	{
		for (int y = 0; y < Image_Height; y++)
		{
			int Intensity_Value = Input_Image.at<uchar>(y,x); // get the intensity value of each picel
			Histogram_GrayScale[Intensity_Value]++; //Add 1 to the frequency of each pixel intensity value
		}
	}

	for (int i = 0; i < 256; i++)
	{
		cout << "Histogram_GrayScale[" << i << "]: " << Histogram_GrayScale[i] << endl; // print out the Histogram
	}

	system("Pause");
	return 0;
}