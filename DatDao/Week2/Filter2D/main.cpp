#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main()
{

	Mat a = imread("dang.jpg");
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
