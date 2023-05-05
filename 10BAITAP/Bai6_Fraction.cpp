/*
File name: Bai6_Fraction.cpp
Author: Ho Tuan Phat
Day: 05/05/2023
Description: Viết chương trình tính các phép tính của phân số
*/
#include <stdio.h>
#include <math.h>
/*
Class: point
Description: tạo class chưa thuộc tính của phân số
Input: none
Output: none
*/
class Fraction
{
public:
    Fraction(float numerator = 0, float denominator = 0);
    int getNumerator();
    int getDenominator();
    Fraction reduceFraction(int numerator, int denominator);
    bool checkTheDenominator();

private:
    float numerator;
    float denominator;
};
/*
Function: Fraction::getDenominator
Description: hàm trả về mẫu số của phân số
Input: none
Output: none
*/
int Fraction::getDenominator()
{
    return Fraction::denominator;
}
/*
Function: Fraction::getDenominator
Description: hàm trả về tử số của phân số
Input: none
Output: none
*/
int Fraction::getNumerator()
{
    return Fraction::numerator;
}
/*
Function: Fraction::Fraction
Description: constructor khởi tạo tử số và mẫu số cho phân số
Input: none
Output: none
*/
Fraction::Fraction(float numerator, float denominator)
{
    Fraction::numerator = numerator;
    Fraction::denominator = denominator;
}
/*
Function: Fraction::checkTheDenominator
Description: hàm kiểm tra mẫu số có bằng không hay không
Input: none
Output: none
*/
bool Fraction::checkTheDenominator()
{
    if (Fraction::denominator == 0)
    {
        return 1;
    }
    else
        return 0;
}
/*
Class: MathFraction
Description: class chứa các phương thức để tính cộng trừ nhân chia phân số
Input: none
Output: none
*/
class MathFraction
{
private:
    Fraction fraction1;
    Fraction fraction2;
    Fraction result;

public:
    MathFraction(Fraction fraction1, Fraction fraction2);
    void sum();
    void minus();
    void multiple();
    void divide();
};
/*
Function: MathFraction::MathFraction
Description: constructor khởi tạo các phân số đầu vào cho class tính toán
Input: none
Output: none
*/
MathFraction::MathFraction(Fraction fraction1, Fraction fraction2)
{
    MathFraction::fraction1 = fraction1;
    MathFraction::fraction2 = fraction2;
}
/*
Function: MathFraction::sum
Description: hàm tính tổng 2 phân số
Input: none
Output: none
*/
void MathFraction::sum()
{
    Fraction result, result1;
    int newNumerator;
    int newDenominator;
    newNumerator = fraction1.getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * fraction1.getDenominator();
    newDenominator = fraction1.getDenominator() * fraction2.getDenominator();
    if (newNumerator == 0)
    {
        printf("The result after adding 2 fractions is 0\n");
    }
    else
    {
        result1 = result.reduceFraction(newNumerator, newDenominator);
        printf("The result after adding 2 fractions is %d/%d\n", result1.getNumerator(), result1.getDenominator());
    }
}
/*
Function: MathFraction::minus
Description: hàm tính hiệu 2 phân số
Input: none
Output: none
*/
void MathFraction::minus()
{
    Fraction result, result1;
    int newNumerator;
    int newDenominator;
    newNumerator = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
    newDenominator = fraction1.getDenominator() * fraction2.getDenominator();
    if (newNumerator == 0)
    {
        printf("The result after subtracting 2 fractions is 0\n");
    }
    else
    {
        result1 = result.reduceFraction(newNumerator, newDenominator);
        printf("The result after subtracting 2 fractions is %d/%d\n", result1.getNumerator(), result1.getDenominator());
    }
}
/*
Function: MathFraction::multiple
Description: hàm tính tích 2 phân số
Input: none
Output: none
*/
void MathFraction::multiple()
{
    Fraction result, result1;
    int newNumerator;
    int newDenominator;
    newNumerator = fraction1.getNumerator() * fraction2.getNumerator();
    newDenominator = fraction1.getDenominator() * fraction2.getDenominator();
    if (newNumerator == 0)
    {
        printf("The result after subtracting 2 fractions is 0\n");
    }
    else
    {
        result1 = result.reduceFraction(newNumerator, newDenominator);
        printf("The result after multiplying 2 fractions is %d/%d\n", result1.getNumerator(), result1.getDenominator());
    }
}
/*
Function: MathFraction::divide
Description: hàm tính thương 2 phân số
Input: none
Output: none
*/
void MathFraction::divide()
{
    Fraction result, result1;
    int newNumerator;
    int newDenominator;
    newNumerator = fraction1.getNumerator() * fraction2.getDenominator();
    newDenominator = fraction1.getDenominator() * fraction2.getNumerator();
    if (newNumerator == 0)
    {
        printf("The result after subtracting 2 fractions is 0\n");
    }
    else
    {
        result1 = result.reduceFraction(newNumerator, newDenominator);
        printf("The result after dividing 2 fractions is %d/%d\n", result1.getNumerator(), result1.getDenominator());
    }
}
/*
Function: Fraction::reduceFraction
Description: hàm rút gọn 2 phân số
Input: int numerator, int denominator
Output: Fration result
*/
Fraction Fraction::reduceFraction(int numerator, int denominator)
{
    int a, b;
    Fraction result;
    result.numerator = numerator;
    result.denominator = denominator;
    // tim ucln
    a = abs(result.numerator);
    b = abs(result.denominator);
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
            b = b - a;
    }
    result.numerator /= a;
    result.denominator /= b;
    return result;
}
/*
Function: main
Description: khai báo các phân số, gọi các phương thức để tính
Input: none
Output: none
*/
int main(int argc, char const *argv[])
{
    Fraction fraction1(-3, 7);
    Fraction fraction2(3, 4);
    if (fraction1.checkTheDenominator() == 1 || fraction2.checkTheDenominator() == 1)
    {
        printf("Wrong!!");
        return 0;
    }
    MathFraction calculator(fraction1, fraction2);
    calculator.sum();
    calculator.minus();
    calculator.divide();
    calculator.multiple();
    return 0;
}
