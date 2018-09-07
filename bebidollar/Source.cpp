#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
//img.at<Vec3b>(0, 0)[0];

int main(){
	Mat a = imread("C:/Users/ThinkPad/Downloads/Image/1.jpg", 0);
	// 0 read by gray
	Mat grey_a = a > 128; 
	//cvtColor(a, grey_a, CV_BGR2GRAY);
	//imwrite("C:/Users/ThinkPad/Downloads/Image/2.jpg", grey_a);
	imshow("Image", grey_a);
	waitKey(0);
	return 0;
}
