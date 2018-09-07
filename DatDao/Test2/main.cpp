#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(){
    Mat src;
    src = imread("1.png");
    namedWindow("Display window",CV_WINDOW_AUTOSIZE);
    imshow("Display window",src);
    waitKey(0);
    return 0;
}
