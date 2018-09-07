#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
    Mat image = imread("C:/Users/admin/Pictures/New folder/Chua Mot Cot.jpg");
    for( int i = 0 ; i < image.rows ; i++)
    {
        for( int j = 0 ; j < image.cols ; j++ )
        {
            if(image.type() == CV_8UC1)
            {
                image.at<uchar>(i,j) = 255;
            }
            else if(image.type() == CV_8UC3)
            {
                cout << image.at<Vec3b>(i,j)[0] << " " << image.at<Vec3b>(i,j)[1] << " " << image.at<Vec3b>(i,j)[2] << endl;

                image.at<Vec3b>(i,j)[0] = 255;
                image.at<Vec3b>(i,j)[1] = 255;
                image.at<Vec3b>(i,j)[2] = 255;

                cout << (int)image.at<Vec3b>(i,j)[0] << " " << (int)image.at<Vec3b>(i,j)[1] << " " << (int)image.at<Vec3b>(i,j)[2] << endl;
            }
        }
    }
    imshow("Ket qua", image);
    waitKey(0);
}
