#include <stdio.h>
#include <stdlib.h>

// char arr[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
//  char arr[] = "The Grammy award-winning singer";
//   Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//   cau 2: In Hoa chu cai dau tien sau dau cham
//   Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//   Cau 4: Chuyen doi tat ca doan van thanh chu hoa
/*
    Su dung bang ascII
*/

// Khai báo mảng

typedef struct
{
    char *firstChar; // Địa chỉ đầu tiên của mảng
    int length;      // Độ dài của mảng
} array;

// Functions
void createTempArr(array tempArr, array text); // Hàm tạo một mảng tạm và sao chép các chữ trong mảng khai báo vào nó
void reverse(array text);                      // Hàm đảo ngược chữ
void upcaseAfterDot(array text);               // Hàm in hoa chữ sau dấu (.)
void upcaseAll(array text);                    // Hàm in hoa tất cả các chữ cái
void lowcaseAll(array text);                   // Hàm in thường tất cả các chữ cái

void createTempArr(array tempArr, array text)
{
    tempArr.firstChar = (char *)malloc(text.length * sizeof(char)); // Tạo một mảng trung gian để lưu mảng khai báo
    for (int i = 0; i < text.length; i++)
    {
        *(tempArr.firstChar + i) = *(text.firstChar + i); // Gián chữ của mảng khai báo qua mảng trung gian
    }
}
// Câu 1: viết đảo ngược đoạn văn
void reverse(array text)
{
    int length = text.length; // Gán biến length = độ dài của mảng
    int countLetter = 0;      // Biến countLetter để đếm số chữ cái trong 1 từ
    while (length >= 0)
    {                                          // Xét mảng từ ký tự cuối cùng của mảng
        length--;                              // Giảm độ dài mảng đi một vì index của mảng bắt đầu từ 0
        if (*(text.firstChar + length) == ' ') // Nếu gặp dấu cách thì in từ sau dấu cách đó
        {
            for (int j = length + 1; j < length + countLetter; j++) // Vòng lặp for chạy từ index sau dấu cách 1 đơn vị đến hết độ dài của từ
            {
                printf("%c", *(text.firstChar + j));
            }
            printf("%c", ' '); // In dấu cách sau từ vừa in
            countLetter = 0;   // Cho CountLetter = 0 để đếm lại số chữ cái trong từ tiếp theo
        }
        countLetter++;   // Đếm số chữ cái trong 1 từ
        if (length == 0) // Do trước từ đầu tiên không có dấu cách nên phải in riêng nó ra
        {
            int i = 0;                           // Khai báo biến chạy
            while (*(text.firstChar + i) != ' ') // In ra từ đầu tiên đến dấu cách thì dừng
            {
                printf("%c", *(text.firstChar + i));
                i++;
            }
        }
    }
    printf("\n \n");
}
// Câu 2: in hoa chữ cái sau dấu .
void upcaseAfterDot(array text)
{
    array tempArr;
    createTempArr(tempArr, text); // Tạo một mảng trung gian để lưu mảng khai báo
    int length = text.length;     // Gán biến length = độ dài của mảng
    while (length >= 0)           // Quét tất cả các chữ cái trong mảng
    {
        length--;
        if (*(tempArr.firstChar + length) == '.') // Nếu xuất hiện dấu chấm
        {
            if ((*(tempArr.firstChar + length + 2) >= 97) && (*(tempArr.firstChar + length + 2) <= 122)) // Kiểm tra xem sau dấu chấm có đang là chữ thường hay không
            {
                *(tempArr.firstChar + length + 2) -= 32; // Đổi chữ thường cách đó 2 index sau dấu chấm bằng cách -32
            }
        }
    }
    printf("%s", tempArr.firstChar);
    printf("\n \n");
}
// Câu 3: in hoa tất cả các chữ
void upcaseAll(array text)
{
    array tempArr;
    createTempArr(tempArr, text);
    int length = text.length;        // Gán biến length = độ dài của mảng
    for (int i = 0; i < length; i++) // Quét toàn mảng
    {
        // Xét điều kiện đối với các chữ cái: A -> Z là từ 60 - 90 và a -> z là 97 - 122
        if ((*(tempArr.firstChar + i) >= 97) && (*(tempArr.firstChar + i) <= 122)) // Nếu là chữ thường
        {
            *(tempArr.firstChar + i) -= 32; // Đối thành chữ hoa bằng cách - 32
        }
    }
    printf("%s", tempArr.firstChar);
    printf("\n \n");
}
// Câu 4: in thường tất cả các chữ
void lowcaseAll(array text)
{
    array tempArr;
    createTempArr(tempArr, text);
    int length = text.length; // Gán biến length = độ dài của mảng
    for (int i = 0; i < length; i++)
    {
        // Xét điều kiện đối với các chữ cái: A -> Z là từ 60 - 90 và a -> z là 97 - 122
        if ((*(tempArr.firstChar + i) >= 60) && (*(tempArr.firstChar + i) <= 90)) // Nếu là chữ hoa
        {
            *(tempArr.firstChar + i) += 32;
        }
    }
    printf("%s", tempArr.firstChar);
    printf("\n \n");
}

int main(int argc, char const *argv[])
{
    char arr[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
    array text;
    text.firstChar = arr;
    text.length = sizeof(arr);
    printf("REVERSE THE STRING:\n");
    reverse(text);
    printf("UPCASE THE FIRST LETTER AFTER A DOT:\n");
    upcaseAfterDot(text);
    printf("UPCASE ALL WORDS OF THE STRING:\n");
    upcaseAll(text);
    printf("LOWCASE ALL WORDS OF THE STRING\n");
    lowcaseAll(text);
    return 0;
}
