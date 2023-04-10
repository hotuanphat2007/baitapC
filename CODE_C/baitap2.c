#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
// tao mot mang random -> sap xep theo thu tu tang dan -> dem so lan xuat hien cua tung so trong mang

typedef struct
{
    uint8_t size;
    uint8_t *firtsAdd;
} typeArr;
int random(int minN, int maxN);                    // Hàm random 1 số
int randomArr(typeArr *arr, uint8_t length);       // Hàm tạo ra 1 mảng random
void createTempArr(typeArr tempArr, typeArr text); // Hàm tạo một mảng trung gian để lưu giá trị của mảng random
void sortArr(typeArr *arr);                        // Hàm sắp xếp theo thứ tự tăng dần
void countApp1(typeArr arr);                       // Hàm đếm số lần xuất hiện của các số trong mảng khi mảng đã sắp xếp
void countApp2(typeArr arr);                       // Hàm đếm số lần xuất hiện của các số trong mảng khi mảng chưa sắp xếp
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int randomArr(typeArr *arr, uint8_t length)
{
    arr->size = length;
    arr->firtsAdd = (uint8_t *)malloc(sizeof(uint8_t) * arr->size);

    srand((int)time(0));

    for (int i = 0; i < arr->size; ++i)
    {
        arr->firtsAdd[i] = random(0, 10);
    }
}
void createTempArr(typeArr tempArr, typeArr text)
{
    tempArr.firtsAdd = (char *)malloc(text.size * sizeof(char)); // Tạo một mảng trung gian để lưu mảng khai báo
    for (int i = 0; i < text.size; i++)
    {
        *(tempArr.firtsAdd + i) = *(text.firtsAdd + i); // Gián chữ của mảng khai báo qua mảng trung gian
    }
    tempArr.size = text.size;
}
// Sắp xếp theo thứ tự tăng dần của các số trong mảng
void sortArr(typeArr *arr)
{

    for (int i = 0; i < arr->size; i++) // Quét tất cả các số trong mảng
    {
        uint8_t mid = 0;
        for (int j = i + 1; j < arr->size; j++) // Quét tất cả các số sau sau i 1 đơn vị cho đén cuối mảng
        {
            if (arr->firtsAdd[i] > arr->firtsAdd[j]) // Nếu i > j thì hoán đổi vị trí
            {
                mid = arr->firtsAdd[i];
                arr->firtsAdd[i] = arr->firtsAdd[j];
                arr->firtsAdd[j] = mid;
            }
        }
    }
}
// Đếm số lần xuất hiện của từng chữ số trong mảng sau khi mảng đã được sắp xếp
void countApp1(typeArr arr)
{
    uint8_t count = 0; // Biến count đếm số lần xuất hiện
    int i = 0;
    while (i < arr.size) // Quét toàn mảng
    {
        count = 1;
        for (int j = i + 1; j < arr.size; j++)
        {
            if (arr.firtsAdd[i] == arr.firtsAdd[j]) // Nếu số sau bằng số trước thì tắng đếm lên 1
            {
                count++;
            }
        }
        printf("the number [%d] appears %d times\n", arr.firtsAdd[i], count); // In ra số lần xuất hiện
        i = i + count;                                                        // Biến chạy i nhảu count lần để đếm số tiếp theo
    }
}
// Đếm số lần xuất hiện của từng chữ số trong mảng khi mảng chưa được sắp xếp
void countApp2(typeArr arr)
{
    typeArr tempArr;
    createTempArr(tempArr, arr);
    uint8_t count = 0;

    for (int i = 0; i < tempArr.size; i++) // Đếm số lần xuất hiện của số 0
    {
        if (tempArr.firtsAdd[i] == 0)
        {
            count++;
        }
    }
    if (count != 0)
        printf("the number [0] appears %d times\n", count); // In số lần xuất hiện của số 0

    for (int i = 0; i < tempArr.size; i++) // Quét toàn bộ mảng
    {
        count = 1;                                 // Biến đếm số lần xuất hiện count = 1;
        for (int j = i + 1; j < tempArr.size; j++) // Quét sau i 1 đơn vị cho đến cuối mảng
        {
            if (tempArr.firtsAdd[i] == tempArr.firtsAdd[j]) // Nếu số i mà bằng số j thì đếm count lên 1;
            {
                count++;                 // Đếm count lên 1;
                tempArr.firtsAdd[j] = 0; // Gán số vừa được đếm = 0
            }
        }
        if (tempArr.firtsAdd[i] != 0) // loại trường hợp số bằng 0 do đã đếm ở trên rồi
        {
            printf("the number [%d] apears %d times\n", tempArr.firtsAdd[i], count);
        }
    }
}

int main()
{
    typeArr arr;
    // random mảng
    randomArr(&arr, 20);

    for (int i = 0; i < arr.size; i++)
    {
        printf("after ramdom: arr[%d] = %d\n", i, arr.firtsAdd[i]);
    }
    printf("--------------------------------------\n");
    // đếm số lần xuất hiện trước khi sắp xếp
    countApp2(arr);
    printf("--------------------------------------\n");
    // sắp xếp các chữ số trong mảng theo thứ tự tăng dần
    sortArr(&arr);
    for (int i = 0; i < arr.size; i++)
    {
        printf("after sort: arr[%d] = %d\n", i, arr.firtsAdd[i]);
    }
    printf("--------------------------------------\n");
    // đếm số lần xuất hiện sau khi sắp xếp
    printf("count after sorting\n");
    countApp1(arr);
}
