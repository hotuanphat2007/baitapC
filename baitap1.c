#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// nhap vao 1 so tu ban phim <9.999.999 7 chữ số
/*mot so truong hop dac biet
1.000.x01 - 1.000.009   1 trieu khong nghin khong tram linh 1 - 9 (XX)
1.000.010: 1 trieu khong nghin khong tram muoi (XX)
1.000.01X: 1 trieu khong nghin khong tram muoi (XX)

1.x00.000: 1 triệu x trăm nghìn (XX)
1.x00.x00: 1 triệu x trăm nghìn x trăm (XX)

1.xx5.xx5: 1 triệu X tram x muoi lam nghìn, x tram x muoi lam (XX)
1.x0x.x0x: 1 triệu x trăm linh x nghìn. x trăm linh x (XX)
1.xx1.xx1: 1 triệu x trăm x muoi mốt nghìn, x trăm x mươi mốt (XX)
*/

uint8_t *ptr;
uint8_t *length;
int inputNumber();              // Hàm nhập vào 1 số
int countNumber(uint32_t tnum); // Hàm đếm số chữ số của số nhập vào
void readNumber(uint32_t tnum); // Hàm lưu các chữ số của số đó và trong mảng
void readUnits(uint8_t num);    // Hàm đọc số 1 2 3 4
void decNumber(uint8_t num);    // Hàm đọc đơn vị của số hàng chục, hàm trăm...
int inputNumber()
{
    int number;
    printf("Input the number: ");
    scanf("%d", &number);
    return number;
}

int countNumber(uint32_t tnum)
{
    uint8_t count = 0; // Biến count đếm số chữ số của 1 số
    while (tnum >= 10) // Khi nào số nhập vào còn > 10
    {
        tnum /= 10; // chia số đó cho 10
        count++;
    }
    return count;
}

void readNumber(uint32_t tnum)
{
    uint8_t a = countNumber(tnum);
    length = &a;                                       // gán biến length cho địa chỉ a
    ptr = (uint8_t *)malloc(*(length) * sizeof(tnum)); // Tạo mảng để lưu các chữ số của số nhâp vào

    for (int i = 0; i <= *length; i++)
    {
        ptr[i] = tnum % 10; // Lưu các chữ số vào ptr
        tnum /= 10;
    }
}

void readUnits(uint8_t num)
{
    switch (num)
    {
    case 0:
        printf("KHONG  ");
        break;
    case 1:
        printf("MOT  ");
        break;
    case 2:
        printf("HAI  ");
        break;
    case 3:
        printf("BA  ");
        break;
    case 4:
        printf("BON  ");
        break;
    case 5:
        printf("NAM  ");
        break;
    case 6:
        printf("SAU  ");
        break;
    case 7:
        printf("BAY  ");
        break;
    case 8:
        printf("TAM  ");
        break;
    case 9:
        printf("CHIN  ");
        break;
    default:
        printf("ERROR!!! KHONG HOP LE!!\n");
        break;
    }
}

void decNumber(uint8_t num)
{
    switch (num)
    {
    case 1: // 1 2 3 4 5 6 1
    case 4:
        printf("MUOI  ");
        break;
    case 2:
    case 5:
        printf("TRAM  ");
        break;
    case 3:
        printf("NGHIN  ");
        break;
    case 6:
        printf("TRIEU  ");
        break;
    default:
        break;
    }
}

void convert()
{
    int i;                     // Biến i là số thứ tự của chữ số trong số đó vd 1.234.567 thì tại số 1 i = 6
    int dai = *length;         // Biến dai bằng độ dài của số đó
    for (i = dai; i >= 0; i--) // Quét số cuối trở về 0 vì ptr lưu ngược các chữ số ở hàm readNumber
    {
        if ((i == 2) && ((*(ptr + i) == 0) && (*(ptr + i - 1) == 0) && (*(ptr + i - 2) == 0)))
        {
            break;
        }

        if ((i == 5) && ((*(ptr + i) == 0) && (*(ptr + i - 1) == 0) && (*(ptr + i - 2) == 0)))
        {
            if (((*(ptr + i - 3) == 0) && (*(ptr + i - 4) == 0) && (*(ptr + i - 5) == 0)))
            {
                break;
            }
            else
                i -= 2;
        }
        // 1 000 000
        if ((i == 1 || i == 4) && (*(ptr + i) == 0)) // Xét trường hợp số hàng chục nghìn và hàng chục bằng 0
        {
            if (*(ptr + i - 1) != 0) // Nếu số sau số hàng chục hoặc hàng chục nghìn khác không
            {
                printf("LINH "); // Đọc thêm chữ linh
                i--;             // Bỏ trường hợp đọc 0 chục
                readUnits(*(ptr + i));
                decNumber(i);
            }
            else
            {
                decNumber(i - 1); // Nếu số sau số hàng chục hoặc hàng chục nghìn bằng 0 luôn thì đọc hàng đơn vị: trăm, nghìn luôn
                i -= 1;
            }
        }
        else if ((i == 1 || i == 4) && (*(ptr + i) != 0)) // Xét trường hợp số hàng chuc nghìn và hàng chục khác 0
        {
            if (*(ptr + i) == 1) // xét trường hợp hàng chục ngìn hoặc hàng chục bằng 1 để đọc là mười một// không đọc 1 mười một
            {
                if (*(ptr + i - 1) != 0) // Nếu số sau nó khác không thì đọc là mười ... ví dụ mười hai
                {
                    if (*(ptr + i - 1) == 5) // nếu sau nó là số 5 thì đọc mười lăm
                    {
                        printf("MUOI  ");
                        i--;
                        printf("LAM  ");
                        decNumber(i);
                    }
                    else // đọc bình thường là mười ... nếu số sau nó không phải là 5
                    {
                        printf("MUOI  ");
                        i--;
                        readUnits(*(ptr + i));
                        decNumber(i);
                    }
                }
                else // Nếu số sau nó là 0 thì đọc là mười thôi
                {
                    printf("MUOI  ");
                    decNumber(i - 1);
                    i -= 1;
                }
            }
            else // xét trường hợp số hàng chục, chục nghìn khác một
            {
                if (*(ptr + i - 1) == 0) // Nếu số sau nó bằng 0 thì chỉ đọc đơn vị của nó. chứ không đọc là 0 nghìn
                {
                    readUnits(*(ptr + i));
                    decNumber(i);
                    i--;
                    decNumber(i);
                }
                else if (*(ptr + i - 1) == 5) // Nếu số sau nó bằng 5 thì đọc vd hai mươi lăm
                {
                    readUnits(*(ptr + i));
                    decNumber(i);
                    i--;
                    printf("LAM  ");
                    decNumber(i);
                }
                else if (*(ptr + i - 1) == 1) // nếu số sau nó bằng 1 thì đọc vd hai mươi mốt
                {
                    readUnits(*(ptr + i));
                    decNumber(i);
                    i--;
                    printf("MOT'  ");
                    decNumber(i);
                }
                else // trường hợp còn lại đọc bình thường
                {
                    readUnits(*(ptr + i));
                    decNumber(i);
                }
            }
        }
        else // đọc bình thường các trường hợp còn lại
        {
            readUnits(*(ptr + i));
            decNumber(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int num = inputNumber();
    readNumber(num);
    convert();
    return 0;
}
