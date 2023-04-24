/*
File name: bai1.cpp
Author: Ho Tuan Phat
Day: 24/04/2023
Description: Viết chương trình để tính khoảng cách, diện tích của các điểm trong mặt phẳng 2D
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
Class: point
Description: tạo class chứa thuộc tính của điểm bao gồm hoành độ và tung độ
Input: none
Output: none
*/
class Point
{
private:
    int8_t ordinate;
    int8_t abscissa;

public:
    Point(int8_t ordinate = 0, int8_t abscissa = 0);
    int8_t getOrdinate() { return ordinate; }
    int8_t getabscissa() { return abscissa; }
};

Point::Point(int8_t ordinate, int8_t abscissa)
{
    Point::ordinate = ordinate;
    Point::abscissa = abscissa;
}
/*
Class: SpaceMath
Description: tạo class cho các điểm trong không gian 2D
Input: none
Output: none
*/
class SpaceMath
{
private:
    Point firstCoordinate;
    Point SecondCoordinate;
    Point ThirdCoordinate;
    typedef enum
    {
        DISTANCE = 5,
        AREA_OF_TRIAGLE
    } Math;

    Math math;

public:
    SpaceMath(Point firstCoordinate, Point SecondCoordinate);
    SpaceMath(Point firstCoordinate, Point SecondCoordinate, Point ThirdCoordinate);
    double calculateDistance();
    double calculateAcreage();
};
/*
Function: SpaceMath::SpaceMath
Description: gọi hàm khởi tạo constructor cho 2 điểm
Input: none
Output: none
*/
SpaceMath::SpaceMath(Point firstCoordinate, Point SecondCoordinate) // phai khoi tao point moi goi duoc
{
    math = DISTANCE;
    SpaceMath::firstCoordinate = firstCoordinate;
    SpaceMath::SecondCoordinate = SecondCoordinate;
}
/*
Function: SpaceMath::SpaceMath
Description: gọi hàm khởi tạo constructor cho 3 điểm
Input: none
Output: none
*/
SpaceMath::SpaceMath(Point firstCoordinate, Point SecondCoordinate, Point ThirdCoordinate)
{
    math = AREA_OF_TRIAGLE;
    SpaceMath::firstCoordinate = firstCoordinate;
    SpaceMath::SecondCoordinate = SecondCoordinate;
    SpaceMath::ThirdCoordinate = ThirdCoordinate;
}
/*
Function: SpaceMath::calculateDistance
Description: hàm tính toán khoảng cách giữa 2 điểm
Input: none
Output: distance
*/
double SpaceMath::calculateDistance()
{
    double distance;
    double x;
    double y;
    if (math == DISTANCE)
    {
        y = firstCoordinate.getabscissa() - SecondCoordinate.getabscissa();
        x = firstCoordinate.getOrdinate() - SecondCoordinate.getOrdinate();
        distance = sqrt(pow(x, 2) + pow(y, 2));
    }
    else
    {
        printf("input again");
    }
    return distance;
}
/*
Function: SpaceMath::calculateAcreage
Description: hàm tính toán diện tích của 3 điểm
Input: none
Output: area
*/
double SpaceMath::calculateAcreage()
{
    double area;
    if (math == AREA_OF_TRIAGLE)
    {
        // sabc = 1/2(xb - xa)(yc - ya) - (xc - xa)(yb - ya)
        area = abs(0.5 * (SecondCoordinate.getOrdinate() - firstCoordinate.getOrdinate()) * (ThirdCoordinate.getabscissa() - firstCoordinate.getabscissa() - (ThirdCoordinate.getOrdinate() - firstCoordinate.getOrdinate()) * (SecondCoordinate.getabscissa() - firstCoordinate.getabscissa())));
    }
    else
        printf("input again");
    return area;
}
/*
Function: main
Description: khai báo các điểm, thực hiện tính toán và xuất kết quả
Input: none
Output: distance, area
*/
int main(int argc, char const *argv[])
{
    Point point1(1, -5);
    Point point2(2, 1);
    Point point3(13, -8);
    SpaceMath math(point1, point2);
    SpaceMath math1(point1, point2, point3);
    printf("%lf\n", math.calculateDistance());
    printf("%lf\n", math1.calculateAcreage());
    return 0;
}
