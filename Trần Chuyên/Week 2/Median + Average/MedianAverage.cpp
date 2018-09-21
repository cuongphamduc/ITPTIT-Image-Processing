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
	Mat src, dst1, dst2;
	src = imread("1.jpg");
	dst2 = imread("1.jpg");
	dst1 = imread("1.jpg");
	//AverageFilter(dst1);
	//median_fliter(dst2);
	
	waitKey(0);
	return 0;
}
