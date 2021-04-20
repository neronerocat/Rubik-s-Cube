//颜色识别部分

#ifndef COLOUR_H
#define COLOUR_H

#include "arm.h"

typedef struct cube {
    Point Loc;
    int color;
}cube;

typedef struct facelet {
    cube C1; cube C2; cube C3; cube C4; cube C5; cube C6; cube C7; cube C8; cube C9;
}facelet;

facelet UDLRFB;

facelet locating(Mat src);
void color_detect(Mat src, facelet *face, string c);
void identify_colors(Mat src, facelet * face);

string a[9];    //保存颜色

Mat imgOriginal, imgOriginal_quarter;

void image_process()
{

    imgOriginal = imread("/home/pi/FINAL/Face/image.jpg", 1);
    resize(imgOriginal, imgOriginal_quarter, Size(imgOriginal.cols / 2, imgOriginal.rows /2), 0, 0, INTER_AREA);		//尺寸缩小到原图1/5
    waitKey(600);
    UDLRFB = locating(imgOriginal_quarter);
    identify_colors(imgOriginal_quarter, &UDLRFB);
    circle(imgOriginal_quarter, UDLRFB.C1.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C2.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C3.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C4.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C5.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C6.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C7.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C8.Loc, 4, Scalar(255, 255, 255));
    circle(imgOriginal_quarter, UDLRFB.C9.Loc, 4, Scalar(255, 255, 255));
}

void identify_colors(Mat src, facelet *face)
{
    Mat imgHSV;
    vector<Mat> hsvSplit;
    cvtColor(src, imgHSV, COLOR_BGR2HSV);
    split(imgHSV, hsvSplit);
    equalizeHist(hsvSplit[2], hsvSplit[2]);
    merge(hsvSplit, imgHSV);

    Mat imgThresholded;
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    //Red
    inRange(imgHSV, Scalar(0, 43, 46), Scalar(2, 255, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "F");

    inRange(imgHSV, Scalar(125, 43, 46), Scalar(180, 255, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "F");

    inRange(imgHSV, Scalar(0, 0, 0), Scalar(180, 255, 46), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "F");
    //Orange
    inRange(imgHSV, Scalar(3, 43, 46), Scalar(25, 255, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "B");
    //Yellow
    inRange(imgHSV, Scalar(26, 43, 46), Scalar(36, 255, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "U");
    //Green
    inRange(imgHSV, Scalar(37, 43, 46), Scalar(85, 255, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "R");
    //Blue
    inRange(imgHSV, Scalar(86, 43, 46), Scalar(124, 255, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "L");
    //White
    inRange(imgHSV, Scalar(0, 0, 46), Scalar(180, 43, 255), imgThresholded);
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    color_detect(imgThresholded, face, "D");

}

void color_detect(Mat src, facelet *face, string c)
{
    if (src.at<uchar>((*face).C1.Loc) == 255)
    {a[0] = c;}
    if (src.at<uchar>((*face).C2.Loc) == 255)
    {a[1] = c;}
    if (src.at<uchar>((*face).C3.Loc) == 255)
    {a[2] = c;}
    if (src.at<uchar>((*face).C4.Loc) == 255)
    {a[3] = c;}
    if (src.at<uchar>((*face).C5.Loc) == 255)
    {a[4] = c;}
    if (src.at<uchar>((*face).C6.Loc) == 255)
    {a[5] = c;}
    if (src.at<uchar>((*face).C7.Loc) == 255)
    {a[6] = c;}
    if (src.at<uchar>((*face).C8.Loc) == 255)
    {a[7] = c;}
    if (src.at<uchar>((*face).C9.Loc) == 255)
    {a[8] = c;}

}

facelet locating(Mat src)
{
    facelet position;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, d;
    Mat dst = src.clone();
    cvtColor(src, src, COLOR_BGR2GRAY);
    bilateralFilter(src, dst, 8, 16, 5);
    Mat element = getStructuringElement(MORPH_RECT, Size(2, 2));
    Canny(dst, dst, 60, 70);
//    imshow("dst", dst);

    //coorinate
    for (int j = 25;j< int(dst.rows*0.5);j = j + 1)
    {
        uchar* data = dst.ptr<uchar>(j);
        for (int i = 0;i < 0.5*dst.cols;i++)
        {
            if (data[i] == 255)
            {
                x1 = i;
                Point pointInterest;
                pointInterest.x = i;
                pointInterest.y = j;
                circle(dst, pointInterest, 10, Scalar(255, 255, 255));
//                imshow("show", dst);
                waitKey(600);
                break;
            }
        }
        if (data[x1] == 255)
        {
            y1 = j;
            break;
        }
    }

    for (int j = int(dst.rows) - 50;j > int(dst.rows*0.5);j = j - 1)
    {
        uchar* data = dst.ptr<uchar>(j);
        for (int i = dst.cols;i > 0.75*dst.cols;i--)
        {
            if (data[i] == 255)
            {
                x2 = i;
                Point pointInterest;
                pointInterest.x = i;
                pointInterest.y = j;
                circle(dst, pointInterest, 10, Scalar(255, 255, 255));
//                imshow("show", dst);
                waitKey(600);
                break;
            }
        }
        if (data[x2] == 255)
        {
            y2 = j;
            break;
        }
    }
    d = (x2 + y2 - x1 - y1) / 6;

    position.C1.Loc = Point(x1 + 0.6 * d, y1 + 0.2 * d);
    position.C2.Loc = Point(x1 + 1.6 * d, y1 + 0.2 * d);
    position.C3.Loc = Point(x1 + 2.7 * d, y1 + 0.2 * d);
    position.C4.Loc = Point(x1 + 0.6 * d, y1 + 1.3 * d);
    position.C5.Loc = Point(x1 + 1.6 * d, y1 + 1.3 * d);
    position.C6.Loc = Point(x1 + 2.7 * d, y1 + 1.3 * d);
    position.C7.Loc = Point(x1 + 0.6 * d, y1 + 2.4 * d);
    position.C8.Loc = Point(x1 + 1.6 * d, y1 + 2.4 * d);
    position.C9.Loc = Point(x1 + 2.7 * d, y1 + 2.4 * d);


    return position;
}

#endif // COLOUR_H
