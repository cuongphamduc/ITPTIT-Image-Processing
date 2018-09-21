#include<iostream>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

int M[9][9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };

void AverageFilter(Mat src) {
	int col = src.cols, row = src.rows;
	for (int i = 1; i <= row - 2; i++) {
		for (int j = 1; j <= col - 2; j++) {
			for (int k = 0; k <= 2; k++) {
				src.at<Vec3b>(i, j)[k] = (int)(src.at<Vec3b>(i - 1, j - 1)[k] + src.at<Vec3b>(i - 1, j)[k] + src.at<Vec3b>(i - 1, j + 1)[k] -
					src.at<Vec3b>(i + 1, j - 1)[k] - src.at<Vec3b>(i + 1, j)[k] - src.at<Vec3b>(i + 1, j + 1)[k]) / 9;
			}
		}
	}
	imshow("Average", src);
}


void median_fliter(Mat dst) {
	int col = dst.cols, row = dst.rows;
	for (int i = 1; i <= row - 2; i++) {
		for (int j = 1; j <= col - 2; j++) {
			for (int k = 0; k <= 2; k++) {
				int a[9] = { dst.at<Vec3b>(i - 1, j - 1)[k], dst.at<Vec3b>(i - 1, j)[k], dst.at<Vec3b>(i - 1, j + 1)[k], 0, 0 , 0, -1 * dst.at<Vec3b>(i + 1, j - 1)[k], -1 * dst.at<Vec3b>(i + 1, j)[k], -1 * dst.at<Vec3b>(i + 1, j + 1)[k] };
				sort(a, a + 8);
				dst.at<Vec3b>(i, j)[k] = a[4];
			}
		}
	}
	imshow("Median", dst);
}



int main() {
	Mat dst1, dst2;
	dst2 = imread("1.jpg");
	dst1 = imread("1.jpg");
	//AverageFilter(dst1);
	//median_fliter(dst2);


	Mat src = imread("1.jpg");
	Mat blur_img, sobel_img1, sobel_img2, gauss_img, mykernel_img;
	double I[3][3] = { -1,-1,-1,-1,8,-1,-1,-1,-1 };
	Mat M(3, 3, CV_64F, I);

	blur(src, blur_img, Size(3, 3));
	imshow("Blur", blur_img);
	imwrite("Blur.jpg", blur_img);

	Sobel(src, sobel_img1, src.depth(), 1, 0, 3);
	Sobel(src, sobel_img2, src.depth(), 0, 2, 3);

	Laplacian(src, gauss_img, src.depth());
	filter2D(src, mykernel_img, src.depth(), M);

	imshow("Sobel Image dx=1, dy=0 ", sobel_img1);
	imwrite("sobel_img1.jpg", sobel_img1);
	imshow("Sobel Image dx=0, dy=2 ", sobel_img2);
	imwrite("sobel_img2.jpg", sobel_img2);
	imshow("Laplace Image ", gauss_img);
	imwrite("gauss_img.jpg", gauss_img);
	imshow("My Kernel Image ", mykernel_img);
	imwrite("mykernel_img.jpg", mykernel_img);
	waitKey(0);
	return 0;
}
