/*
File name: Bai3_Circle.cpp
Author: Ho Tuan Phat
Day: 24/04/2023
Description: Viết chương trình để tính chu vi, diện tích, đường chéo và kiểm tra có phải hình vuông không của một hình chữ nhật
*/
#include <stdio.h>
#include <math.h>
/*
Class: Rectangle
Description: tạo class chứa thuộc tính bán kính của hình tròn và các phương thức để tính chu vi và diện tích
Input: none
Output: none
*/
class Circle
{
private:
    float radius;

public:
    float getPremeter();
    float getAceage();
    Circle(float r);
};

Circle::Circle(float r)
{
    Circle::radius = r;
}

float Circle::getPremeter()
{
    float premeter;
    premeter = M_PI * 2 * Circle::radius;
    return premeter;
}

float Circle::getAceage()
{
    float aceage;
    aceage = M_PI * pow(Circle::radius, 2);
    return aceage;
}

int main(int argc, char const *argv[])
{
    Circle circle(5.0);
    printf("The premeter of the circle: %.2f\n", circle.getPremeter());
    printf("The aceage of the circle: %.2f\n", circle.getAceage());
    return 0;
}
