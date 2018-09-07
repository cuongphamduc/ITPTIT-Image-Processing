#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(){
    Mat im_rgb  = imread("dang.jpg");
    Mat im_gray;
    cvtColor(im_rgb,im_gray,CV_RGB2GRAY);
    //Mat im_gray = imread("image.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    //Mat img_bw = im_gray > 128;
    waitKey(0);
    return 0;
}
