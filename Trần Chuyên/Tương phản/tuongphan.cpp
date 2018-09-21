#include<iostream>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src;
	src = imread("1.jpg");
	Mat dst = src.clone();
	double alpha = 2.0;
	int beta = 30;
	cout << "Alpha(double) = " << endl; cin >> alpha;
	cout << "Beta(int) = " << endl; cin >> beta;
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			for (int k = 0; k < 3; k++) {
				dst.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(alpha * (src.at<Vec3b>(i, j)[k])+ beta);
			}
		}
	}
	imshow("Anh goc", src);
	imshow("Anh sau chinh sua", dst);	
	imwrite("Anhsua.jpg", dst);

	waitKey(0);
	return 0;
}
