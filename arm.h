//控制机械臂旋转

#ifndef FUNCTION_H
#define FUNCTION_H

#include<wiringPi.h>
#include <iostream>
#include<string>
#include<ctime>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<stdlib.h>
#include<string>
#include <cstdio>
#include <cctype>

using namespace cv;
using namespace std;

void slider1push()
{
    digitalWrite(26,HIGH);
    delayMicroseconds(1250);
    digitalWrite(26,LOW);
    delayMicroseconds(18750);
}
void slider1back()
{
    digitalWrite(26,HIGH);
    delayMicroseconds(2000);
    digitalWrite(26,LOW);
    delayMicroseconds(18000);
}

void slider2push()
{
    digitalWrite(27,HIGH);
    delayMicroseconds(1150);
    digitalWrite(27,LOW);
    delayMicroseconds(18850);
}
void slider2back()
{
    digitalWrite(27,HIGH);
    delayMicroseconds(2000);
    digitalWrite(27,LOW);
    delayMicroseconds(18000);
}

void slider3push()
{
    digitalWrite(28,HIGH);
    delayMicroseconds(1200);
    digitalWrite(28,LOW);
    delayMicroseconds(18800);
}
void slider3back()
{
    digitalWrite(28,HIGH);
    delayMicroseconds(2150);
    digitalWrite(28,LOW);
    delayMicroseconds(17850);
}

void slider4push()
{
    digitalWrite(29,HIGH);
    delayMicroseconds(1200);
    digitalWrite(29,LOW);
    delayMicroseconds(18800);
}
void slider4back()
{
    digitalWrite(29,HIGH);
    delayMicroseconds(2000);
    digitalWrite(29,LOW);
    delayMicroseconds(18000);
}

void rot1left()
{
    digitalWrite(22,HIGH);
    delayMicroseconds(550);
    digitalWrite(22,LOW);
    delayMicroseconds(19450);
}
void rot1mid()
{
    digitalWrite(22,HIGH);
    delayMicroseconds(1520);
    digitalWrite(22,LOW);
    delayMicroseconds(18480);
}
void rot1right()
{
    digitalWrite(22,HIGH);
    delayMicroseconds(2470);
    digitalWrite(22,LOW);
    delayMicroseconds(17530);
}

void rot2left()
{
    digitalWrite(23,HIGH);
    delayMicroseconds(500);
    digitalWrite(23,LOW);
    delayMicroseconds(19500);
}
void rot2mid()
{
    digitalWrite(23,HIGH);
    delayMicroseconds(1500);
    digitalWrite(23,LOW);
    delayMicroseconds(18500);
}
void rot2right()
{
    digitalWrite(23,HIGH);
    delayMicroseconds(2470);
    digitalWrite(23,LOW);
    delayMicroseconds(17530);
}

void rot3left()
{
    digitalWrite(21,HIGH);
    delayMicroseconds(520);
    digitalWrite(21,LOW);
    delayMicroseconds(19480);
}
void rot3mid()
{
    digitalWrite(21,HIGH);
    delayMicroseconds(1520);
    digitalWrite(21,LOW);
    delayMicroseconds(18480);
}
void rot3right()
{
    digitalWrite(21,HIGH);
    delayMicroseconds(2460);
    digitalWrite(21,LOW);
    delayMicroseconds(17540);
}

void rot4left()
{
    digitalWrite(25,HIGH);
    delayMicroseconds(530);
    digitalWrite(25,LOW);
    delayMicroseconds(19470);
}
void rot4mid()
{
    digitalWrite(25,HIGH);
    delayMicroseconds(1500);
    digitalWrite(25,LOW);
    delayMicroseconds(18500);
}
void rot4right()
{
    digitalWrite(25,HIGH);
    delayMicroseconds(2450);
    digitalWrite(25,LOW);
    delayMicroseconds(17550);
}

#endif // FUNCTION_H
