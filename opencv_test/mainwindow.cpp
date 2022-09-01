#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QImage>
#include <QTextStream>
#include "function.h"
using namespace cv;
using namespace std;


QString noise_name[5] = {"NULL","Salt Pepper noise","Gaussian noise","RandomExponential noise","Random noise"};
QString blur_name[8] = {"NULL","Average Blur","Gaussian Blur","Median Blur","Bilateral Filter","Custom Average Blur","Custom Median Blur","Custom Gaussian Blur"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     flag_n = 0;
     flag_b = 0;
     flag = -1;
     f_src = 0;
     QString strFilePath = "./result.txt";
     QFile file(strFilePath);
     //clear file
     file.open(QFile::WriteOnly|QFile::Truncate);
     file.close();
     QTextStream out(&file);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_clicked()
{
        //获取文件路径
        filename = QFileDialog::getOpenFileName( this, tr("Open Image"), ".",tr("Image Files(*.png *.jpg *.jpeg *.bmp)"));
        if(filename.length()<=0)
            return;
        src=imread(filename.toUtf8().data());
        if(src.empty())
            return;
        cvtColor( src, src, CV_BGR2RGB );
        //将Mat转为QImage
        Qimg = QImage( (const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888 );
        //显示图片
        ui->showImageLabel->setPixmap( QPixmap::fromImage(Qimg));
        ui->showImageLabel->setScaledContents(true);
        f_src =  1;
        flag_n = 0;
        flag_b = 0;

}



void MainWindow::on_close_clicked()
{
    close();
}




void MainWindow::on_blur_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    QString input = ui->b_combo->currentText();
    if(input.compare(QString::fromLocal8Bit("3*3"))==0)
    blur(rst, b_rst, Size(3, 3));
    else if(input.compare(QString::fromLocal8Bit("5*5"))==0)
    blur(rst, b_rst, Size(5, 5));
    else if(input.compare(QString::fromLocal8Bit("8*8"))==0)
    blur(rst, b_rst, Size(8, 8));
    else
    blur(rst, b_rst, Size(5, 5));
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 1;
}

void MainWindow::on_g_blur_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    QString input = ui->g_combo->currentText();
    if(input.compare(QString::fromLocal8Bit("3*3"))==0)
    GaussianBlur(rst, b_rst, Size(3, 3),0);
    else if(input.compare(QString::fromLocal8Bit("5*5"))==0)
    GaussianBlur(rst, b_rst, Size(5, 5),0);
    else if(input.compare(QString::fromLocal8Bit("7*7"))==0)
    GaussianBlur(rst, b_rst, Size(7, 7),0);
    else
    GaussianBlur(rst, b_rst, Size(5, 5),0);
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 2;
}

void MainWindow::on_m_blur_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    QString input = ui->m_combo->currentText();
    int num = input.toInt();
    medianBlur(rst, b_rst, num);
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 3;
}

void MainWindow::on_para_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    cout<<"psnr_before = "<<psnr<<endl;
    get_para(src,rst,psnr,mssim);
    cout<<"psnr = "<<psnr<<endl;
    QString str_p = QString::number(psnr,'f',2);
    ui->P_num->setText(str_p);
    double b=mssim[0];
    double g=mssim[1];
    double r=mssim[2];
    QString str_b = QString::number(b, 'f', 2);
    QString str_g = QString::number(g, 'f', 2);
    QString str_r = QString::number(r, 'f', 2);
    ui->b->setText(str_b);
    ui->g->setText(str_g);
    ui->r->setText(str_r);
    flag = 0;
}

void MainWindow::on_para_2_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_b){
        QMessageBox::information(NULL, "Tips", "Please blur first");
        return;
    }
    cout<<"psnr_before = "<<psnr<<endl;
    get_para(src,b_rst,psnr,mssim);
    cout<<"psnr = "<<psnr<<endl;
    QString str_p = QString::number(psnr,'f',2);
    ui->P_num->setText(str_p);
    double b=mssim[0];
    double g=mssim[1];
    double r=mssim[2];
    QString str_b = QString::number(b, 'f', 2);
    QString str_g = QString::number(g, 'f', 2);
    QString str_r = QString::number(r, 'f', 2);
    ui->b->setText(str_b);
    ui->g->setText(str_g);
    ui->r->setText(str_r);
    flag = 1;
}


void MainWindow::on_salt_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    //add noise
    QString input = ui->salt_combo->currentText();
    int num = input.toInt();
    Mat temp = src.clone();
    rst = add_salt_pepper_noise(temp,num);
    Qimg = QImage( (const unsigned char*)(rst.data), rst.cols, rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_2->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_2->setScaledContents(true);
    flag_n = 1;

}

void MainWindow::on_gaussian_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if (filename.length()<=0) {
        cout<<"could not load image...\n"<<endl;
        close();
    }
        QString input_m = ui->mu->currentText();
        int MU = input_m.toInt();
        QString input_s = ui->sigma->currentText();
        int SIGMA = input_s.toInt();
        //add noise
        rst = add_gaussian_noise(src,MU,SIGMA);
        Qimg = QImage( (const unsigned char*)(rst.data), rst.cols, rst.rows, QImage::Format_RGB888 );
        ui->showImageLabel_2->setPixmap( QPixmap::fromImage(Qimg));
        ui->showImageLabel_2->setScaledContents(true);
        flag_n = 2;

}

void MainWindow::on_exponential_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
        QString input_l = ui->ex_combo->currentText();
        int lameda = input_l.toInt();
        //add noise
        rst = add_randomExponential(src, lameda);
        Qimg = QImage( (const unsigned char*)(rst.data), rst.cols, rst.rows, QImage::Format_RGB888 );
        ui->showImageLabel_2->setPixmap( QPixmap::fromImage(Qimg));
        ui->showImageLabel_2->setScaledContents(true);
        flag_n = 3;
}

void MainWindow::on_random_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    rst = add_random_noise(src);
    Qimg = QImage( (const unsigned char*)(rst.data), rst.cols, rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_2->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_2->setScaledContents(true);
    flag_n = 4;
}

void MainWindow::on_export_file_clicked()
{
    QString strFilePath = "./result.txt";
    QFile file(strFilePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::information(NULL, "Tips", "Fail to open the files");
        return;
    }
    QTextStream out(&file);
    if(flag == -1){
        QMessageBox::information(NULL, "Tips", "Please calculate first");
        return;
    }
    else if(flag == 0){
        if(flag_n){
            QString noise = noise_name[flag_n];
            out<<"Noise:"<<noise<<endl;
            out<<"PNSR:"<<ui->P_num->text()<<endl;
            out<<"MSSIM:"<<endl;
            out<<"r:"<<ui->r->text()<<endl;
            out<<"g:"<<ui->g->text()<<endl;
            out<<"b:"<<ui->b->text()<<endl;
            out<<"**************************"<<endl;
            QMessageBox::information(NULL, "Tips", "Finished");
        }
        else{
            QMessageBox::information(NULL, "Tips", "PLease add noise first");
            return;
        }
    }
    else if(flag == 1){
        if(flag_b){
            QString blur = blur_name[flag_b];
            out<<"Blur:"<<blur<<endl;
            out<<"PNSR:"<<ui->P_num->text()<<endl;
            out<<"MSSIM:"<<endl;
            out<<"r:"<<ui->r->text()<<endl;
            out<<"g:"<<ui->g->text()<<endl;
            out<<"b:"<<ui->b->text()<<endl;
            out<<"**************************"<<endl;
            QMessageBox::information(NULL, "Tips", "Finished");
        }
        else{
            QMessageBox::information(NULL, "Tips", "PLease blur first");
            return;
        }
    }

    file.close();
}

void MainWindow::on_bilater_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    bilateralFilter(rst, b_rst, 25,25*2,25/2);
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 4;
}

void MainWindow::on_c_av_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    b_rst = AverFiltering(rst);
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 5;
}

void MainWindow::on_c_med_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    b_rst = MedianFlitering(rst);
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 6;
}

void MainWindow::on_c_gau_clicked()
{
    if(!f_src){
        QMessageBox::information(NULL, "Tips", "Please load image first");
        return;
    }
    if(!flag_n){
        QMessageBox::information(NULL, "Tips", "Please add noise first");
        return;
    }
    Mat mask;
    QString input = ui->g_combo->currentText();
    if(input.compare(QString::fromLocal8Bit("3*3"))==0)
    generateGaussMask(mask,Size(3, 3), 0.8);
    else if(input.compare(QString::fromLocal8Bit("5*5"))==0)
    generateGaussMask(mask,Size(5, 5), 0.8);
    else if(input.compare(QString::fromLocal8Bit("7*7"))==0)
    generateGaussMask(mask,Size(7, 7), 0.8);
    else
    generateGaussMask(mask,Size(7, 7), 0.8);

    b_rst = GaussianFilter(rst, mask);
    Qimg = QImage( (const unsigned char*)(b_rst.data), b_rst.cols, b_rst.rows, QImage::Format_RGB888 );
    ui->showImageLabel_3->setPixmap( QPixmap::fromImage(Qimg));
    ui->showImageLabel_3->setScaledContents(true);
    flag_b = 7;
}
