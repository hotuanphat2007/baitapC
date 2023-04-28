/*
File name: Bai5_Human.cpp
Author: Ho Tuan Phat
Day: 28/04/2023
Description:  Viết chương trình tạo các thuộc tính của con người và các phương thức để hiển thị thông tin và tính tuổi.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
/*
Class: Human
Description: tạo class chứa thuộc tính của con người và các phương thức để hiển thị thông tin và tính tuổi
Input: none
Output: none
*/
class Human
{
public:
    Human(char *name, int yearOfBirth, char *address);
    void showInfor();
    int calculatorAge();
    char *getName();

private:
    char name[20];
    int yearOfBirth;
    char address[30];
};
/*
Function: Human::Human
Description: Tạo constructor cho các thuộc tính của class Human
Input: none
Output: none
*/
Human::Human(char *name, int yearOfBirth, char *address)
{
    strcpy(Human::name, name);
    Human::yearOfBirth = yearOfBirth;
    strcpy(Human::address, address);
}
/*
Function: Human::showInfor
Description: Hàm hiển thị thông tin của con người
Input: none
Output: none
*/
void Human::showInfor()
{
    printf("Show the information of the human:\n");
    printf("Name        YOB         Address\n");
    printf("%s      %d      %s\n", Human::name, Human::yearOfBirth, Human::address);
}
/*
Function: Human::calculatorAge
Description: Hàm tính toán tuổi của con người
Input: none
Output: age
*/
int Human::calculatorAge()
{
    int age;
    age = 2023 - Human::yearOfBirth;
    return age;
}
/*
Function: Human::getName
Description: Hàm lấy tên của con người
Input: none
Output: name
*/
char *Human::getName()
{
    return Human::name;
}
/*
Function: main
Description: khởi tạo các thuộc tính của con người và thực hiện các phương thức hiển thị danh sách và tính tuổi
Input: none
Output: none
*/
int main(int argc, char const *argv[])
{
    Human human1("phat", 2001, "lam van thanh");
    human1.showInfor();
    printf("Age of %s is: %d", human1.getName(), human1.calculatorAge());
    return 0;
}
