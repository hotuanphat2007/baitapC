/*
File name: Bai7_Age.cpp
Author: Ho Tuan Phat
Day: 05/05/2023
Description: Viết chương trình tạo class ngày tháng năm và các phương thức để tính tuổi và kiểm tra có phải ngày lễ hay không
*/
#include <stdio.h>
#include <math.h>
/*
Class: date
Description: tạo class chứa thuộc tình của ngày tháng năm và phương thức tính tuổi, kiểm tra ngày lễ
Input: none
Output: none
*/
class date
{
public:
    int getDay();
    int getMonth();
    int getYear();
    date(int day, int month, int year);
    int calculateAge(int dayB, int monthB, int yearB);
    bool checkHoliday(int day, int month);

private:
    int day;
    int month;
    int year;
};
/*
Function: date::date
Description: gọi hàm khởi tạo constructor cho ngày tháng năm
Input: none
Output: none
*/
date::date(int day, int month, int year)
{
    date::day = day;
    date::month = month;
    date::year = year;
}
/*
Function: date::calculateAge
Description: hàm tính tuổi
Input: none
Output: none
*/
int date::calculateAge(int day, int month, int year)
{
    int age;
    age = year - date::year;
    if (date::month > month)
    {
        age -= 1;
    }
    else if (date::day > day)
    {
        age -= 1;
    }
    return age;
}
/*
Function: date::checkHoliday
Description: hàm kiểm tra có phải ngày lễ hay không
Input: none
Output: none
*/
bool date::checkHoliday(int day, int month)
{
    if (date::day == day && date::month == month)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*
Function: main
Description: hàm main khởi tạo ngày tháng năm và gọi các phương thức để tính toán
Input: none
Output: none
*/
int main(int argc, char const *argv[])
{
    int age;
    int day, month, year;
    int dayCheck, monthCheck;
    printf("Enter the current date: \n");
    printf("Day: ");
    scanf("%d", &day);
    printf("Month: ");
    scanf("%d", &month);
    printf("Year: ");
    scanf("%d", &year);
    date dateOfBirht(20, 07, 2001);
    printf("Age: %d\n", dateOfBirht.calculateAge(day, month, year));
    printf("Enter the day you want to check if it is a holiday: \n");
    printf("Day: ");
    scanf("%d", &dayCheck);
    printf("Month: ");
    scanf("%d", &monthCheck);
    date holiday(2, 9, 1975);
    if (holiday.checkHoliday(dayCheck, monthCheck) == 1)
    {
        printf("This is a holiday\n");
    }
    else
    {
        printf("This is not a holiday\n");
    }
    return 0;
}
