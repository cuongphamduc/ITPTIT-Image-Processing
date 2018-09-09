#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
int main() {
	Mat src = imread("C:/Users/ThinKPad/Downloads/2.jpg");
	Mat gray, hsv, ycrcb;
	cvtColor(src, gray, CV_BGR2GRAY);
	cvtColor(src, hsv, CV_BGR2HSV);
	cvtColor(src, ycrcb, CV_BGR2YCrCb);
	imshow("src", src);
	imshow("gray", gray);
	imshow("hsv", hsv);
	imshow("ycrcb", ycrcb);
	waitKey(0);
	return 0;
}

