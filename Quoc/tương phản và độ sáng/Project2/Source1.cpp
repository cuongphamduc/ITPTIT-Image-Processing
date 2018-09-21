#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
int main() {
	Mat imp = imread("C:/Users/ThinKPad/Downloads/402689.png");
	for (int i = 0; i < imp.rows; i++) {
		for (int j = 0; j < imp.cols; j++) {
			for (int k = 0; k < 3; k++) {
				imp.at<Vec3b>(i, j)[k] = saturate_cast < uchar>(2 * imp.at<Vec3b>(i, j)[k] + 30);
			}
		}
	}
	imshow("Impage", imp);
	waitKey(0);
	return 0;
}

