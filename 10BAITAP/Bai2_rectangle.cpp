/*
File name: Bai2_rectangle
Author: Ho Tuan Phat
Day: 24/04/2023
Description: Viết chương trình để tính chu vi, diện tích, đường chéo và kiểm tra có phải hình vuông không của một hình chữ nhật
*/
#include <stdio.h>
#include <stdint.h>
#include <math.h>
/*
Class: Rectangle
Description: tạo class chứa thuộc tính hình chữ nhật là chiều dài và chiều rộng
Input: none
Output: none
*/
class Rectangle
{
public:
    Rectangle(float lenght = 0, float width = 0);
    float getPremeter();
    float getAcreage();
    float getDiagnolLine();
    void checkSquare();

private:
    float length;
    float width;
};
/*
Function: Rectangle::Rectangle
Description: constructor khởi tạo chiều dài và rộng
Input: none
Output: none
*/
Rectangle::Rectangle(float le, float width)
{
    Rectangle::length = le;
    Rectangle::width = width;
}
/*
Class: Rectangle::getPremeter
Description: hàm nhận giá trị chu vi của hình chữ nhật
Input: none
Output: none
*/
float Rectangle::getPremeter()
{
    float premeter;
    premeter = (Rectangle::length + Rectangle::width) * (2.0);
    return premeter;
}
/*
Class: Rectangle::getAcreage
Description: hàm nhận giá trị diện tích của hình chữ nhật
Input: none
Output: none
*/
float Rectangle::getAcreage()
{
    float acreage;
    acreage = Rectangle::length * Rectangle::width;
    return acreage;
}
/*
Class: Rectangle::getDiagnolLine
Description: hàm nhận giá trị đường chéo của hình chữ nhật
Input: none
Output: none
*/
float Rectangle::getDiagnolLine()
{
    float diagnol;
    diagnol = sqrt(pow(Rectangle::length, 2) + pow(Rectangle::width, 2));
    return diagnol;
}
/*
Class: Rectangle::checkSquare
Description: hàm kiểm tra hình chữ nhật có phải hình vuông không
Input: none
Output: none
*/
void Rectangle::checkSquare()
{
    if (Rectangle::length == Rectangle::width)
    {
        printf("This is a square");
    }
    else
        printf("This is not a square");
}
/*
Class: main
Description: hàm
Input: none
Output: none
*/
int main(int argc, char const *argv[])
{
    Rectangle rec(5, 5);
    printf("The perimeter of the rectangle is: %.2f\n", rec.getPremeter());
    printf("The acreage of the rectangle is: %.2f\n", rec.getAcreage());
    printf("The diagnol line of the rectangle is: %.2f\n", rec.getDiagnolLine());
    rec.checkSquare();
    return 0;
}
