#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QImage>
#include "function.h"
#include <ctime>
using namespace cv;
using namespace std;

//获取参数
void get_para(Mat src,Mat &rst,double &psnr,Scalar &mssim){
    psnr = getPSNR(src, rst);
    mssim = getMSSIM(src, rst);
}


//Get median
uchar Median(uchar n1, uchar n2, uchar n3, uchar n4, uchar n5,
    uchar n6, uchar n7, uchar n8, uchar n9) {
    uchar arr[9];
    arr[0] = n1;
    arr[1] = n2;
    arr[2] = n3;
    arr[3] = n4;
    arr[4] = n5;
    arr[5] = n6;
    arr[6] = n7;
    arr[7] = n8;
    arr[8] = n9;
    //Sort
    for (int gap = 9 / 2; gap > 0; gap /= 2)
        for (int i = gap; i < 9; ++i)
            for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
                swap(arr[j], arr[j + gap]);
    //Get median
    return arr[4];
}


//Get Gaussian mask()
void generateGaussMask(Mat& Mask,Size wsize, double sigma){
    Mask.create(wsize,CV_64F);
    int h = wsize.height;
    int w = wsize.width;
    int center_h = (h - 1) / 2;
    int center_w = (w - 1) / 2;
    double sum = 0.0;
    double x, y;
    //2^(Distance from the center)
    for (int i = 0; i < h; ++i){
        y = pow(i - center_h, 2);
        for (int j = 0; j < w; ++j){
            x = pow(j - center_w, 2);
            //Gaussian distribution
            double g = exp(-(x + y) / (2 * sigma*sigma));
            Mask.at<double>(i, j) = g;
            sum += g;
        }
    }
    Mask = Mask / sum;
}




/***************************** noise **********************************/
//椒盐噪声
Mat add_salt_pepper_noise(Mat image, int nums) {
    RNG rng(12345);
    int h = image.rows;
    int w = image.cols;

    for (int i = 0; i < nums; i++) {
        int x = rng.uniform(0, w);
        int y = rng.uniform(0, h);
        if (i % 2 == 1) {
            image.at<Vec3b>(y, x) = Vec3b(255, 255, 255);
        }
        else {
            image.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
        }
    }
    return image;
}


//高斯噪声
Mat add_gaussian_noise(Mat image,int mu, int sigma) {
    Mat noise = Mat::zeros(image.size(), image.type());
    randn(noise, (mu, mu, mu), (sigma, sigma, sigma));
    Mat dst;
    add(image, noise, dst);
    return dst;
}


//指数噪声
Mat add_randomExponential(Mat image,double lambda)
{
    Mat noise = Mat::zeros(image.size(), image.type());
    Mat dst;

    int w = image.cols;
    int h = image.rows;

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            double pv = (double)(rand()%100)/100;
            while(pv == 0)
            {
            pv = (double)(rand() % 100)/100;
            }
        pv =255 * (-1 / lambda)*log(1-pv);
        noise.at<Vec3b>(row, col) = Vec3b(pv, pv, pv);

        }

    }
    add(image,noise,dst);
    return dst;
}

//随机噪声
Mat add_random_noise(Mat image){
    Mat noise = Mat::zeros(image.size(), image.type());
    Mat dst;

    int w = image.cols;
    int h = image.rows;

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
        int pv = 255 * rand() ;
        noise.at<Vec3b>(row, col) = Vec3b(pv, pv, pv);
        }
    }
    add(image,noise,dst);
    return dst;
}

/***************************** calculate **********************************/
double getPSNR(const Mat& I1, const Mat& I2)
{
    Mat s1;
    absdiff(I1, I2, s1);       // |I1 - I2|
    s1.convertTo(s1, CV_32F);  // cannot make a square on 8 bits
    s1 = s1.mul(s1);           // |I1 - I2|^2
    Scalar s = sum(s1);         // sum elements per channel
    double sse = s.val[0] + s.val[1] + s.val[2]; // sum channels
    if( sse <= 1e-10) // for small values return zero
        return 0;
    else
    {
        double mse =sse /(double)(I1.channels() * I1.total());
        double psnr = 10.0*log10((255*255)/mse);
        return psnr;
    }
}
Scalar getMSSIM( const Mat& i1, const Mat& i2)
{
    const double C1 = 6.5025, C2 = 58.5225;
    //init
    int d     = CV_32F;
    Mat I1, I2;
    i1.convertTo(I1, d);           // cannot calculate on one byte large values
    i2.convertTo(I2, d);
    Mat I2_2   = I2.mul(I2);        // I2^2
    Mat I1_2   = I1.mul(I1);        // I1^2
    Mat I1_I2  = I1.mul(I2);        // I1 * I2
    //end init
    Mat mu1, mu2;   // PRELIMINARY COMPUTING
    GaussianBlur(I1, mu1, Size(11, 11), 1.5);
    GaussianBlur(I2, mu2, Size(11, 11), 1.5);
    Mat mu1_2   =   mu1.mul(mu1);
    Mat mu2_2   =   mu2.mul(mu2);
    Mat mu1_mu2 =   mu1.mul(mu2);
    Mat sigma1_2, sigma2_2, sigma12;
    GaussianBlur(I1_2, sigma1_2, Size(11, 11), 1.5);
    sigma1_2 -= mu1_2;
    GaussianBlur(I2_2, sigma2_2, Size(11, 11), 1.5);
    sigma2_2 -= mu2_2;
    GaussianBlur(I1_I2, sigma12, Size(11, 11), 1.5);
    sigma12 -= mu1_mu2;
    Mat t1, t2, t3;
    t1 = 2 * mu1_mu2 + C1;
    t2 = 2 * sigma12 + C2;
    t3 = t1.mul(t2);              // t3 = ((2*mu1_mu2 + C1).*(2*sigma12 + C2))
    t1 = mu1_2 + mu2_2 + C1;
    t2 = sigma1_2 + sigma2_2 + C2;
    t1 = t1.mul(t2);               // t1 =((mu1_2 + mu2_2 + C1).*(sigma1_2 + sigma2_2 + C2))
    Mat ssim_map;
    divide(t3, t1, ssim_map);      // ssim_map =  t3./t1;
    Scalar mssim = mean( ssim_map ); // mssim = average of ssim map
    return mssim;
}
/***************************** filter **********************************/


//均值滤波
Mat AverFiltering(const Mat &src) {
    Mat dst(src.size(), src.type());
    //Traversal every spot
    for (int i = 1; i<src.rows; ++i)
        for (int j = 1; j < src.cols; ++j) {
            if ((i - 1 >= 0) && (j - 1) >= 0 && (i + 1)<src.rows && (j + 1)<src.cols) {
                dst.at<Vec3b>(i, j)[0] = (src.at<Vec3b>(i, j)[0] + src.at<Vec3b>(i - 1, j - 1)[0] + src.at<Vec3b>(i - 1, j)[0] + src.at<Vec3b>(i, j - 1)[0] +
                    src.at<Vec3b>(i - 1, j + 1)[0] + src.at<Vec3b>(i + 1, j - 1)[0] + src.at<Vec3b>(i + 1, j + 1)[0] + src.at<Vec3b>(i, j + 1)[0] +
                    src.at<Vec3b>(i + 1, j)[0]) / 9;
                dst.at<Vec3b>(i, j)[1] = (src.at<Vec3b>(i, j)[1] + src.at<Vec3b>(i - 1, j - 1)[1] + src.at<Vec3b>(i - 1, j)[1] + src.at<Vec3b>(i, j - 1)[1] +
                    src.at<Vec3b>(i - 1, j + 1)[1] + src.at<Vec3b>(i + 1, j - 1)[1] + src.at<Vec3b>(i + 1, j + 1)[1] + src.at<Vec3b>(i, j + 1)[1] +
                    src.at<Vec3b>(i + 1, j)[1]) / 9;
                dst.at<Vec3b>(i, j)[2] = (src.at<Vec3b>(i, j)[2] + src.at<Vec3b>(i - 1, j - 1)[2] + src.at<Vec3b>(i - 1, j)[2] + src.at<Vec3b>(i, j - 1)[2] +
                    src.at<Vec3b>(i - 1, j + 1)[2] + src.at<Vec3b>(i + 1, j - 1)[2] + src.at<Vec3b>(i + 1, j + 1)[2] + src.at<Vec3b>(i, j + 1)[2] +
                    src.at<Vec3b>(i + 1, j)[2]) / 9;
            }
            //Set border
            else {
                dst.at<Vec3b>(i, j)[0] = src.at<Vec3b>(i, j)[0];
                dst.at<Vec3b>(i, j)[1] = src.at<Vec3b>(i, j)[1];
                dst.at<Vec3b>(i, j)[2] = src.at<Vec3b>(i, j)[2];
            }
        }
    return dst;
}


//中值滤波
Mat MedianFlitering(const Mat &src) {
    Mat dst(src.size(), src.type());
    for(int i=0;i<src.rows;++i)
        for (int j=0; j < src.cols; ++j) {
            if ((i - 1) > 0 && (i + 1) < src.rows && (j - 1) > 0 && (j + 1) < src.cols) {
                dst.at<Vec3b>(i, j)[0] = Median(src.at<Vec3b>(i, j)[0], src.at<Vec3b>(i + 1, j + 1)[0],
                    src.at<Vec3b>(i + 1, j)[0], src.at<Vec3b>(i, j + 1)[0], src.at<Vec3b>(i + 1, j - 1)[0],
                    src.at<Vec3b>(i - 1, j + 1)[0], src.at<Vec3b>(i - 1, j)[0], src.at<Vec3b>(i, j - 1)[0],
                    src.at<Vec3b>(i - 1, j - 1)[0]);
                dst.at<Vec3b>(i, j)[1] = Median(src.at<Vec3b>(i, j)[1], src.at<Vec3b>(i + 1, j + 1)[1],
                    src.at<Vec3b>(i + 1, j)[1], src.at<Vec3b>(i, j + 1)[1], src.at<Vec3b>(i + 1, j - 1)[1],
                    src.at<Vec3b>(i - 1, j + 1)[1], src.at<Vec3b>(i - 1, j)[1], src.at<Vec3b>(i, j - 1)[1],
                    src.at<Vec3b>(i - 1, j - 1)[1]);
                dst.at<Vec3b>(i, j)[2] = Median(src.at<Vec3b>(i, j)[2], src.at<Vec3b>(i + 1, j + 1)[2],
                    src.at<Vec3b>(i + 1, j)[2], src.at<Vec3b>(i, j + 1)[2], src.at<Vec3b>(i + 1, j - 1)[2],
                    src.at<Vec3b>(i - 1, j + 1)[2], src.at<Vec3b>(i - 1, j)[2], src.at<Vec3b>(i, j - 1)[2],
                    src.at<Vec3b>(i - 1, j - 1)[2]);
            }
            else
                dst.at<Vec3b>(i, j) = src.at<Vec3b>(i, j);
        }
    return dst;
}



//高斯滤波
Mat GaussianFilter(const Mat& src, Mat mask){
    int hh = (mask.rows - 1) / 2;
    int hw = (mask.cols - 1) / 2;
    Mat dst(src.size(), src.type());
    //Set border
    Mat Newsrc;
    copyMakeBorder(src, Newsrc, hh, hh, hw, hw, cv::BORDER_REPLICATE);//边界复制
    //Traversal
    for (int i = hh; i < src.rows + hh;++i){
        for (int j = hw; j < src.cols + hw; ++j){
            double sum[3] = { 0 };
            for (int r = -hh; r <= hh; ++r){
                for (int c = -hw; c <= hw; ++c){
                        Vec3b rgb = Newsrc.at<cv::Vec3b>(i+r,j + c);
                        sum[0] = sum[0] + rgb[0] * mask.at<double>(r + hh, c + hw);//B
                        sum[1] = sum[1] + rgb[1] * mask.at<double>(r + hh, c + hw);//G
                        sum[2] = sum[2] + rgb[2] * mask.at<double>(r + hh, c + hw);//R
                }
            }
            for (int k = 0; k < src.channels(); ++k){
                if (sum[k] < 0)
                    sum[k] = 0;
                else if (sum[k]>255)
                    sum[k] = 255;
            }
                Vec3b rgb (static_cast<uchar>(sum[0]), static_cast<uchar>(sum[1]), static_cast<uchar>(sum[2]));
                dst.at<cv::Vec3b>(i-hh, j-hw) = rgb;

        }
    }
    return dst;
}

