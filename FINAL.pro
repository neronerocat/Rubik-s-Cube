//pro文件

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \
                /usr/local/include/raspicam

LIBS += -L/usr/local/include -lwiringPi \
        /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_video.so \
        /usr/local/lib/libopencv_videoio.so \
        /usr/local/lib/libopencv_videostab.so \
        /usr/local/lib/libraspicam.so \
        /usr/local/lib/libraspicam_cv.so \
        -L/usr/local/lib \
        -lopencv_core \
        -lopencv_imgcodecs \
        -lopencv_highgui \
        -lopencv_video \
        -lopencv_videoio \
        -lopencv_videostab \
        -lraspicam \
        -lraspicam_cv


SOURCES += \
        main.cpp

HEADERS += \
    arm.h \
    photo.h \
    colour.h \
    rotation.h \
    thistlethwaite.h
