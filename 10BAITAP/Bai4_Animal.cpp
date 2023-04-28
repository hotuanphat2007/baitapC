/*
File name: Bai4_Animal.cpp
Author: Ho Tuan Phat
Day: 28/04/2023
Description: Viết chương trình tạo các thuộc tính của động vật và tạo các phương thức để tính bmi của chúng và so sánh chúng theo cân nặng và theo tuổi
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;
/*
Class: Animal
Description: tạo class chứa thuộc tính của động vật và các phương thức so sánh và tính bmi của chúng
Input: none
Output: none
*/
class Animal
{
private:
    char nameOfAnimal[20];
    int ageOfAnimal;
    float weightOfAnimal;
    float heightOfAnimal;

public:
    Animal(char *name, int age, float weight, float height);
    void getBMI(char *name);
    void getTableSortedByAge();
    void getTableSortedByWeight();
    void setAnimal(char *name, int age, float weight, float height);
};
// Tạo vector để chứa các thuộc tính của các động vật khác nhau
vector<Animal> AnimalList;
/*
Function: Animal::Animal
Description: Tạo constructor cho các thuộc tính của class Animal
Input: none
Output: none
*/
Animal::Animal(char *name, int age, float weight, float height)
{
    Animal::ageOfAnimal = age;
    strcpy(Animal::nameOfAnimal, name);
    Animal::weightOfAnimal = weight;
    Animal::heightOfAnimal = height;
}
/*
Function: Animal::setAnimal
Description: Thêm động vật và các thuộc tính của nó vào danh sách
Input: none
Output: none
*/
void Animal::setAnimal(char *name, int age, float weight, float height)
{
    AnimalList.push_back(Animal(name, age, weight, height));
}
/*
Function: Animal::getBMI
Description: Tính toán chỉ số BMI cho các loài động vật
Input: name
Output: bmi
*/
void Animal::getBMI(char *name)
{
    float bmi;
    for (int i = 0; i < AnimalList.size(); i++)
    {
        Animal *ani = &AnimalList.at(i);
        if (strcmp(name, ani->nameOfAnimal) == 0)
        {
            bmi = ani->weightOfAnimal / (pow(ani->heightOfAnimal, 2));
            printf("bmi of %s is: %.2f\n", name, bmi);
        }
        else
        {
            printf("%s does not exist\n", name);
        }
    }
}
/*
Function: swap
Description: Thuật toán hoán đổi chỗ của 2 động vật trong danh sách
Input: name
Output: bmi
*/
void swap(Animal *ani1, Animal *ani2)
{
    Animal midAni = *ani1;
    *ani1 = *ani2;
    *ani2 = midAni;
}
/*
Function: Animal::getTableSortedByAge
Description: Lập danh sách sắp xếp để so sánh tuổi của các động vật
Input: none
Output: none
*/
void Animal::getTableSortedByAge()
{
    for (int i = 0; i < AnimalList.size(); i++)
    {
        Animal *ani1 = &AnimalList.at(i);
        for (int j = i + 1; j < AnimalList.size(); j++)
        {
            Animal *ani2 = &AnimalList.at(j);
            if (ani1->ageOfAnimal > ani2->ageOfAnimal)
            {
                swap(ani1, ani2);
            }
        }
    }
    printf("List of animal: \n");
    printf("Name        Age     Weight      Height\n");
    for (Animal ani : AnimalList)
    {
        printf("%s      %d      %f      %f\n", ani.nameOfAnimal, ani.ageOfAnimal, ani.weightOfAnimal, ani.heightOfAnimal);
    }
}
/*
Function: Animal::getTableSortedByWeight
Description: Lập danh sách sắp xếp để so sánh cân nặng của các động vật
Input: none
Output: none
*/
void Animal::getTableSortedByWeight()
{
    for (int i = 0; i < AnimalList.size(); i++)
    {
        Animal *ani1 = &AnimalList.at(i);
        for (int j = i + 1; j < AnimalList.size(); j++)
        {
            Animal *ani2 = &AnimalList.at(j);
            if (ani1->weightOfAnimal > ani2->weightOfAnimal)
            {
                swap(ani1, ani2);
            }
        }
    }
    printf("List of animal: \n");
    printf("Name        Age     Weight      Height\n");
    for (Animal ani : AnimalList)
    {
        printf("%s      %d      %f      %f\n", ani.nameOfAnimal, ani.ageOfAnimal, ani.weightOfAnimal, ani.heightOfAnimal);
    }
}
/*
Function: main
Description: tạo các thuộc tính cho động vật và gọi các phương thức để tính toán, so sánh
Input: none
Output: none
*/
int main(int argc, char const *argv[])
{

    Animal *ani;
    // add animal
    ani->setAnimal("meo", 4, 6.0, 0.4);
    ani->getBMI("meo"); // call the name of animal which u want to calcualte the bmi
    ani->setAnimal("cho", 3, 114.0, 1.4);
    ani->getBMI("cho");
    ani->setAnimal("ga", 1, 2.5, 0.3);
    ani->getBMI("ga");
    // compare the age of all the animal in list
    ani->getTableSortedByAge();
    // compare the weight of all the animal in list
    ani->getTableSortedByWeight();
    return 0;
}
