#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <iostream>
// nhan 1 de ket thuc chuong tirnh .....
using namespace std;

#define INPUT_DATA(content, type, variable) \
    printf(content);                        \
    scanf(type, variable);

class Student
{
public:
    Student(const char name[20], const char sex[7], int age,
            double mathScore, double physicsScore, double chemistryScore);
    void setNameOfStudent(const char name[]);
    void setSexOfStudent(const char sex[]);
    void setAgeOfStudent(int ageOfStudent);
    void setMathScore(double mathScore);
    void setChemistryScore(double chemistryScore);
    void setPhysicsScore(double physicsScore);

    char *getNameOfStudent();
    char *getSexOfStudent();
    int getAgeOfStudent();
    double getMathScore();
    double getPhysicsScore();
    double getChemistryScore();
    double getGpa();
    char *getRank();
    int getId();

private:
    int id;
    char nameOfStudent[20];
    char sexOfStudent[7]; // nam 3 nu 2 null 1 nen can
    int ageOfStudent;
    double mathScore;
    double physicsScore;
    double chemistryScore;
    double gpa;
    char capacity[11];
};

class Menu
{
public:
    void addStudent();
    void updateStudentInforById();
    void deleteStudentById();
    void searchStudentByName();
    void sortStudentByGpa();
    void sortStudentByName();
    void showList();
    int checkId(int id);
    int checkName(char *name);
    int inputId();
    char *inputName();
    void swap(Student *st1, Student *st2);
    void choseAction();

private:
    vector<Student> studentList;
    vector<Student> studentListMid;
};

enum choice
{
    choice1 = 1,
    choice2,
    choice3,
    choice4,
    choice5,
    choice6,
    choice7,
    choice8
};
Student::Student(const char name[20], const char sex[7], int age, double mathScore, double physicsScore, double chemistryScore)
{ // const do nhap truc tiep,

    setNameOfStudent(name);
    setSexOfStudent(sex);
    setAgeOfStudent(age);
    setMathScore(mathScore);
    setPhysicsScore(physicsScore);
    setChemistryScore(chemistryScore);

    static int id = 100;
    Student::id = id;
    id++;
}

void Student::setSexOfStudent(const char sex[7])
{
    if (strcmp((char *)"male", sex) != 0 && strcmp((char *)"female", sex) != 0)
    {
        printf("ERROR!! WRONG SEX\n");
    }
    else
    {
        strcpy(sexOfStudent, sex);
    }
}

char *Student::getSexOfStudent()
{
    return sexOfStudent;
}

void Student::setNameOfStudent(const char name[20])
{
    strcpy(nameOfStudent, name);
}

char *Student::getNameOfStudent()
{
    return nameOfStudent;
}

void Student::setAgeOfStudent(int age)
{
    ageOfStudent = age;
}

int Student::getAgeOfStudent()
{
    return ageOfStudent;
}

void Student::setChemistryScore(double hoa)
{
    chemistryScore = hoa;
}

double Student::getChemistryScore()
{
    return chemistryScore;
}

void Student::setPhysicsScore(double ly)
{
    physicsScore = ly;
}

double Student::getPhysicsScore()
{
    return physicsScore;
}

void Student::setMathScore(double toan)
{
    mathScore = toan;
}

double Student::getMathScore()
{
    return mathScore;
}

int Student::getId()
{
    return id;
}

double Student::getGpa()
{

    return (chemistryScore + physicsScore + mathScore) / 3.0;
}
char *Student::getRank()
{
    if (getGpa() >= 8.0)
    {
        strcpy(capacity, "Gioi");
    }
    else if (getGpa() >= 6.5)
    {
        strcpy(capacity, "Kha");
    }
    else if (getGpa() >= 5.0)
    {
        strcpy(capacity, "Trung Binh");
    }
    else
        strcpy(capacity, "Yeu");

    return capacity;
}

void Menu::swap(Student *st1, Student *st2)
{
    Student st = *st1;
    *st1 = *st2;
    *st2 = st;
}

int Menu::checkId(int id)
{
    int count = 0;
    for (Student st : studentList)
    {

        if (id == st.getId())
        {
            count++;
        }
    }
    return count; // count = 0 la khong co id nhap vao
}

int Menu::checkName(char *name)
{
    int count = 0;
    for (Student st : studentList)
    {

        if (strcmp(name, (char *)st.getNameOfStudent()) == 0)
        {
            count++;
        }
    }
    return count;
}

char *Menu::inputName()
{
    char *nameInput;
    char name[20];
    int count = 0; // dem so lan nhap lai
    do
    {
        if ((count != 0) && (checkName((char *)name) == 0))
        {
            printf("The name does not exist, please input again: ");
        }
        else
        {
            printf("Input the name: ");
        }
        scanf("%s", &name);
        count++;
    } while (checkName((char *)name) == 0);
    strcpy(nameInput, name);
    return nameInput;
}

int Menu::inputId()
{
    int inputId;
    int count = 0; // dem so lan nhap lai
    do
    {
        if ((count != 0) && (checkId(inputId) == 0))
        {
            printf("The Id does not exist, please input again: ");
        }
        else
        {
            printf("Input the Id: ");
        }
        scanf("%d", &inputId);
        count++;
    } while (checkId(inputId) == 0);
    return inputId;
}

void Menu::addStudent()
{
    char name[20];
    int age;
    char sex[7];
    double mathScore;
    double physicsScore;
    double chemistryScore;
    int key = 0;
    do
    {
        INPUT_DATA("Input Student's name: ", "%s", &name);
        INPUT_DATA("Input Student's sex: ", "%s", &sex);
        INPUT_DATA("Input Student's age: ", "%d", &age);
        INPUT_DATA("Input Student's math score: ", "%lf", &mathScore);
        INPUT_DATA("Input Student's physics score: ", "%lf", &physicsScore);
        INPUT_DATA("Input Student's chemistry score: ", "%lf", &chemistryScore);
        Student st(name, sex, age, mathScore, physicsScore, chemistryScore);
        studentList.push_back(st);
        printf("Press 1 to continue add student\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::updateStudentInforById()
{
    int i = 0; // dem vi tri cua ID
    int id = inputId();
    int key = 0;
    do
    {
        for (Student st : studentList)
        {
            if (id == st.getId())
            {
                studentList.erase(studentList.begin() + i);
                char name[20];
                int age;
                char sex[7];
                double mathScore;
                double physicsScore;
                double chemistryScore;

                INPUT_DATA("Input Student's name: ", "%s", &name);
                st.setNameOfStudent(name);
                INPUT_DATA("Input Student's sex: ", "%s", &sex);
                st.setSexOfStudent(sex);
                INPUT_DATA("Input Student's age: ", "%d", &age);
                st.setAgeOfStudent(age);
                INPUT_DATA("Input Student's math score: ", "%lf", &mathScore);
                st.setMathScore(mathScore);
                INPUT_DATA("Input Student's physics score: ", "%lf", &physicsScore);
                st.setPhysicsScore(physicsScore);
                INPUT_DATA("Input Student's chemistry score: ", "%lf", &chemistryScore);
                st.setChemistryScore(chemistryScore);

                studentList.insert(studentList.begin() + i, st);
            }
            i++;
        }
        printf("Press 1 to continue update student's information\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::showList()
{
    int key = 0;
    do
    {
        printf("Student list:\n");
        printf("Id\tName\tSex\tAge\tMath\tPhysics\tChemis\tGPA\tCapacity\n");
        for (Student st : studentList)
        {
            printf("%d\t%s\t%s\t%d\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%s\n", st.getId(), st.getNameOfStudent(), st.getSexOfStudent(), st.getAgeOfStudent(),
                   st.getMathScore(), st.getPhysicsScore(), st.getChemistryScore(), st.getGpa(), st.getRank());
        }
        printf("Press 1 to continue show the list of the students\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::deleteStudentById()
{
    int i = 0; // dem vi tri cua ID
    int id = inputId();
    int key = 0;
    do
    {
        for (Student st : studentList)
        {
            if (id == st.getId())
            {
                studentList.erase(studentList.begin() + i);
            }
            i++;
        }
        printf("Press 1 to continue delete student's information\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::searchStudentByName()
{
    int key = 0;
    do
    {
        char *name = inputName();
        for (Student st : studentList)
        {
            if (strcmp(name, (char *)st.getNameOfStudent()) == 0)
            {
                printf("%d\t%s\t%s\t%d\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%s\n", st.getId(), st.getNameOfStudent(), st.getSexOfStudent(), st.getAgeOfStudent(),
                       st.getMathScore(), st.getPhysicsScore(), st.getChemistryScore(), st.getGpa(), st.getRank());
            }
        }
        printf("Press 1 to continue search student's information by name\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::sortStudentByName()
{
    int key = 0;
    do
    {
        for (int i = 0; i < studentList.size(); i++)
        {
            Student *st1 = &studentList.at(i);
            for (int j = i + 1; j < studentList.size(); j++)
            {
                Student *st2 = &studentList.at(j);
                if (*(st1->getNameOfStudent()) > *(st2->getNameOfStudent()))
                {
                    swap(st1, st2);
                }
            }
        }
        printf("Press 1 to continue sort student's information by name\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::sortStudentByGpa()
{
    int key = 0;
    do
    {
        for (int i = 0; i < studentList.size(); i++)
        {
            Student *st1 = &studentList.at(i);
            for (int j = i + 1; j < studentList.size(); j++)
            {
                Student *st2 = &studentList.at(j);
                if ((st1->getGpa()) > (st2->getGpa()))
                {
                    swap(st1, st2);
                }
            }
        }
        printf("Press 1 to continue update student's information\n");
        printf("Any key to exit\n");
        scanf("%d", &key);
    } while (key == 1);
}

void Menu::choseAction()
{
    int choice;
    do
    {
        printf("1. Insert a student\n");
        printf("2. Update the student's information\n");
        printf("3. Delete the tudent's information by ID\n");
        printf("4. Search the student's information by name\n");
        printf("5. Sort the student's information by GPA\n");
        printf("6. Sort the student's information by name\n");
        printf("7. Show the list of the students\n");
        printf("8. Exit\n");
        printf("Please input the action: ");
        do
        {
            scanf("%d", &choice);
        } while (choice > 8 || choice < 1);

        switch (choice)
        {
        case choice1:
            addStudent();
            break;
        case choice2:
            updateStudentInforById();
            break;
        case choice3:
            deleteStudentById();
            break;
        case choice4:
            searchStudentByName();
            break;
        case choice5:
            sortStudentByGpa();
            break;
        case choice6:
            sortStudentByName();
            break;
        case choice7:
            showList();
            break;
        case choice8:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);
}
int main(int argc, char const *argv[])
{
    Menu mn;
    mn.choseAction();
    return 0;
}
