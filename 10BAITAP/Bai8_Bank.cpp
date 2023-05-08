/*
File name: Bai8_Bank.cpp
Author: Ho Tuan Phat
Day: 08/05/2023
Description:  Viết chương trình tạo thuộc tính của tài khoản ngân hàng và các phương thức để nạp, rút, kiểm tra số dư
*/
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
/*
Class: bankAccount
Description: tạo class chứa thuộc tính của tài khoản ngân hàng và các phương thức để nạp, rút, kiểm tra tài khoản
Input: none
Output: none
*/
class bankAccount
{
public:
    void withdraw(int numberAccount, float amount);
    void recharge(int numberAccount, float amount);
    float getBalance(int numberAccount);
    bankAccount(char *name, int number, float balance);
    void setAccount(char *name, int number, float balance);

private:
    char nameAccount[20];
    int numberAccount;
    float accountBalance;
};
/*
vector: accountList
Description: tạo vector chứa các thông tin của tài khoản ngân hàng
Input: none
Output: none
*/
vector<bankAccount> accountList;
/*
Function: bankAccount::setAccount
Description: tạo tài khoản ngân hàng
Input: none
Output: none
*/
void bankAccount::setAccount(char *name, int numeber, float balance)
{
    accountList.push_back(bankAccount(name, numeber, balance));
}
/*
Function: bankAccount::bankAccount
Description: constructor khởi tạo giá trị ban đầu cho tài khoản ngân hàng
Input: none
Output: none
*/
bankAccount::bankAccount(char *name, int number, float balance)
{
    strcpy(bankAccount::nameAccount, name);
    bankAccount::numberAccount = number;
    bankAccount::accountBalance = balance;
}
/*
Function: bankAccount::getBalance
Description: hàm trả về số dư của tài khoản ngân hàng
Input: none
Output: money
*/
float bankAccount::getBalance(int numberAccount)
{
    float money;
    for (bankAccount account : accountList)
    {
        if (account.numberAccount == numberAccount)
        {
            money = account.accountBalance;
        }
    }
    return money;
}
/*
Function: bankAccount::recharge
Description: hàm nạp tiền vào tài khoản ngân hàng
Input: int numberAccount, float amount
Output: none
*/
void bankAccount::recharge(int numberAccount, float amount)
{
    for (bankAccount &account : accountList)
    {
        if (account.numberAccount == numberAccount)
        {
            account.accountBalance += amount;
        }
    }
}
/*
Function: bankAccount::withdraw
Description: hàm rút tiền từ tài khoản ngân hàng
Input: int numberAccount, float amount
Output: none
*/
void bankAccount::withdraw(int numberAccount, float amount)
{
    for (bankAccount &account : accountList)
    {
        if (account.numberAccount == numberAccount)
        {
            account.accountBalance -= amount;
        }
    }
}
/*
Function: main
Description: hàm main khởi tạo tên tài khoản, số tài khoản, số dư ban đầu và gọi các phương thức thực hiện rút tiền, nạp tiền, kiểm tra số dư
Input: int numberAccount, float amount
Output: none
*/
int main(int argc, char const *argv[])
{
    char name[20];
    printf("input name of account: ");
    scanf("%s", name);
    bankAccount *tuanphat;
    tuanphat->setAccount(name, 914540503, 2.000000000);
    tuanphat->recharge(914540503, 2);
    tuanphat->withdraw(914540503, 3);
    printf("so du la: %f", tuanphat->getBalance(914540503));
    return 0;
}
