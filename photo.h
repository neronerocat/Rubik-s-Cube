//拍照

#ifndef PHOTO_H
#define PHOTO_H

#include "arm.h"

void take_photo ()
{
    waitKey(1000);
    VideoCapture Camera(0);
    cv::Mat image;
    int nCount=60;
    //set camera params
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC2 );
    //Open camera
    if (!Camera.isOpened()) {cerr<<"Error opening the camera"<<endl;//return -1;
    }
    //Start capture
    for ( int i=0; i<=nCount; i++ ) {
        Camera.grab();
        Camera.retrieve ( image);
    }
    Camera.release();
    //save image
    imwrite("/home/pi/FINAL/Face/image.jpg",image);
    waitKey(500);
}

#endif // PHOTO_H
