#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTextStream>
#include <QFileDialog>
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_load_clicked();



    void on_close_clicked();


    void on_salt_clicked();

    void on_gaussian_clicked();

    void on_blur_clicked();

    void on_g_blur_clicked();

    void on_m_blur_clicked();

    void on_para_clicked();

    void on_para_2_clicked();

    void on_exponential_clicked();

    void on_random_clicked();

    void on_export_file_clicked();

    void on_bilater_clicked();

    void on_c_av_clicked();

    void on_c_med_clicked();

    void on_c_gau_clicked();

private:
    Ui::MainWindow *ui;
    Mat src;
    int f_src;
    Mat rst;
    Mat b_rst;
    QImage Qimg;
    QString filename;
    double psnr;
    Scalar mssim;
    int flag_n;
    int flag_b;
    int flag;

};

#endif // MAINWINDOW_H
