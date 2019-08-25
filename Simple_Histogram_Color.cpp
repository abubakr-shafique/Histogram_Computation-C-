//This Program is written by Abubakr Shafique (abubakr.shafique@gmail.com)
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){

	Mat Input_Image = imread("Test_Image.png"); // Read a 3 channel Color Image
	int Image_Height = Input_Image.size().height; // Get the Height of the Input Image
	int Image_Width = Input_Image.size().width; // Get the Width of the Input Image

	int Histogram_Blue[256] = { 0 }; //Initialize a Histogram array with zeros
	int Histogram_Green[256] = { 0 }; //Initialize a Histogram array with zeros
	int Histogram_Red[256] = { 0 }; //Initialize a Histogram array with zeros

	for (int x = 0; x < Image_Width; x++)//looping to scan all pixels in our image
	{
		for (int y = 0; y < Image_Height; y++)
		{
				int Intensity_Value_Blue = Input_Image.at<Vec3b>(y, x)[0]; // get the intensity value of each picel
				int Intensity_Value_Green = Input_Image.at<Vec3b>(y, x)[1]; // get the intensity value of each picel
				int Intensity_Value_Red = Input_Image.at<Vec3b>(y, x)[2]; // get the intensity value of each picel
				Histogram_Blue[Intensity_Value_Blue]++; //Add 1 to the frequency of each pixel intensity value
				Histogram_Green[Intensity_Value_Green]++; //Add 1 to the frequency of each pixel intensity value
				Histogram_Red[Intensity_Value_Red]++; //Add 1 to the frequency of each pixel intensity value
		}
	}

	for (int i = 0; i < 256; i++)
	{
		cout << "Histogram_Blue[" << i << "]: " << Histogram_Blue[i] << endl; // print out the Histogram
	}

	for (int i = 0; i < 256; i++)
	{
		cout << "Histogram_Green[" << i << "]: " << Histogram_Green[i] << endl; // print out the Histogram
	}

	for (int i = 0; i < 256; i++)
	{
		cout << "Histogram_Red[" << i << "]: " << Histogram_Red[i] << endl; // print out the Histogram
	}


	system("Pause");
	return 0;
}