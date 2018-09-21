#include<iostream>
#include<algorithm>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#define FORU(i,a,b) for(int i = a;i <= b;i++)
#define FORD(i,a,b) for(int i = a;i >= b;i--)
using namespace std;
using namespace cv;
int main() {
	Mat res = imread("C:/Users/ThinKPad/Downloads/402689.png");
	int ker[4][4], bug0[10], bug1[10], bug2[10], hang, cot, row, col, k;
	cin >> hang >> cot;
	FORU(i, 0, hang - 1) {
		FORU(j, 0, cot - 1) cin >> ker[i][j];
	}
	FORU(i, hang / 2, res.rows - hang / 2 - 1) {
		FORU(j, cot / 2, res.cols - cot / 2 - 1) {
			row = 0;
			col = 0;
			k = 0;
			FORU(x, i - hang / 2, i + hang / 2) {
				FORU(y, j - cot / 2, j + cot / 2) {

					bug0[k] = (int)res.at<Vec3b>(x, y)[0] * ker[row][col];
					bug1[k] = (int)res.at<Vec3b>(x, y)[1] * ker[row][col];
					bug2[k] = (int)res.at<Vec3b>(x, y)[2] * ker[row][col];
					col++;
					k++;
				}
				row++;
			}
			sort(bug0, bug0 + 9);
			sort(bug1, bug1 + 9);
			sort(bug2, bug2 + 9);
			res.at<Vec3b>(i, j)[0] = bug0[k / 2];
			res.at<Vec3b>(i, j)[1] = bug1[k / 2];
			res.at<Vec3b>(i, j)[2] = bug2[k / 2];
		}
	}
	imshow("img", res);
	waitKey(0);
	return 0;
}

