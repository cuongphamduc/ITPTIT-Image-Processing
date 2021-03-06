// image.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	//Mat a = imread("1.jpg");
	/*Mat b;
	cvtColor(a,b, CV_RGB2GRAY);
	imshow("2.jpg",b);
	waitKey(0);*/
	/*Mat a = imread("img.jpg");
	Mat b;
	cvtColor(a, b, CV_RGB2GRAY);
	imshow("3.jpg", b);
	waitKey(0);
	return 0;*/
    //std::cout << "Hello World!\n"; 
	Mat a = imread("u.jpg");
	Mat b;
	//int m;
	blur(a, b, Size(3,3));
	imshow("y.jpg", b);
	Sobel(a, b, CV_32F, 1,1,3);
	imshow("v.jpg", b);
	Laplacian(a, b,CV_64F);
	imshow("j.jpg", b);

	//cin >> m;
	Mat my_kernel = Mat_<double>(Size(3,3),CV_64F);
	filter2D(a, b, 3, my_kernel, Point(0, 0), 0);
	imshow("i.jpg", b);
	waitKey(0);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
