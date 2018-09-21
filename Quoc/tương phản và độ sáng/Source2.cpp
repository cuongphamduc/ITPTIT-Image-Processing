#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("image.jpg");
	Mat blur_img, sobel_img1, sobel_img2, gauss_img, mykernel_img;
	double I[3][3] = { -1,-1,-1,-1,8,-1,-1,-1,-1 };
	Mat M(3, 3, CV_64F, I);

	blur(src, blur_img, Size(3, 3));

	Sobel(src, sobel_img1, src.depth(), 1, 0, 3);
	Sobel(src, sobel_img2, src.depth(), 0, 2, 3);

	Laplacian(src, gauss_img, src.depth());
	filter2D(src, mykernel_img, src.depth(), M);

	imshow("Sobel Image dx=1, dy=0 ", sobel_img1);
	imshow("Sobel Image dx=0, dy=2 ", sobel_img2);
	imshow("Blur", blur_img);
	imshow("Laplace Image ", gauss_img);
	imshow("My Kernel Image ", mykernel_img);
	waitKey(0);
	return 0;
}

