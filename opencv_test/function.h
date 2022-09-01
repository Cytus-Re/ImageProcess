#ifndef FUNCTION_H
#define FUNCTION_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QImage>
#include <ctime>
using namespace cv;
using namespace std;

Mat add_salt_pepper_noise(Mat image, int nums);
Mat add_gaussian_noise(Mat image,int mu, int sigma);
Mat add_randomExponential(Mat image,double lambda);
Mat add_random_noise(Mat image);

double getPSNR(const Mat& I1, const Mat& I2);
Scalar getMSSIM( const Mat& i1, const Mat& i2);

void get_para(Mat src, Mat& rst, double &psnr, Scalar &mssim);
uchar Median(uchar n1, uchar n2, uchar n3, uchar n4, uchar n5,
             uchar n6, uchar n7, uchar n8, uchar n9);
void generateGaussMask(Mat& Mask,Size wsize, double sigma);

Mat GaussianFilter(const Mat& src, Mat window);
Mat AverFiltering(const Mat &src);
Mat MedianFlitering(const Mat &src);

#endif // FUNCTION_H
