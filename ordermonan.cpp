#include <stdio.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <vector>
/*--------------------------------------------------------MACRO---------------------------------------------------------------*/
/*
 * Function: MACRO ENTER_DATA
 * Description: Macro nhập vào dữ liệu
 * Input:
 *   content - Nội dung cần nhập
 *   type - kiểu dữ liệu
 *   variable - biến cần nhập vào
 */
#define ENTER_DATA(type, variable, content) \
    printf(content);                        \
    scanf(type, variable);

/*
 * Function: CHECK_DATA
 * Description: kiểm tra có dữ liệu ở vector hay không
 * Input:
 *   vector - tên vector
 *   content - nội dung inra
 *   code - nội dung code
 */
#define CHECK_DATA(vector, content, code) \
    if (vector->empty())                  \
    {                                     \
        printf(content);                  \
    }                                     \
    else                                  \
    {                                     \
        code                              \
    }
/*
 * Function: CHECK_ID
 * Description: kiểm tra id có tồn tại không
 * Input:
 *   id - id cần check
 *   check - biến check (đúng = 1 sai = 0)
 *   vector - tên vector
 *   code - nội dung code
 */
#define CHECK_ID(id, check, vector, code)                     \
    do                                                        \
    {                                                         \
        for (int index = 0; index < vector->size(); index++)  \
        {                                                     \
            if ((vector->at(index)).getId() == id)            \
            {                                                 \
                check++;                                      \
                code                                          \
            }                                                 \
        }                                                     \
        if (check == 0)                                       \
        {                                                     \
            ENTER_DATA("%d", &id, "Wrong id, input again: "); \
        }                                                     \
    } while (check == 0);
using namespace std;

enum options
{
    option0 = 0,
    option1 = 1,
    option2,
    option3,
    option4,
    option5,

};
/*
 * Function: Class Món ăn
 * Description: Chứa Property & Method sử dụng cho class Món ăn
 */
class dishes
{
public:
    dishes(int ident, char name[20], float pr)
    {
        strcpy(dishName, name);
        id = ident;
        price = pr;
    }

    void setNameOfDish(char name[20]) { strcpy(this->dishName, name); }
    char *getNameOfDish() { return dishName; }
    void setPriceOfDish(float price) { this->price = price; }
    float getPriceOfDish() { return price; }
    int getId() { return id; }

private:
    int id;
    char dishName[20];
    float price;
};
/*
 * Function: Class Món ăn đã được order
 * Description: Chứa thông tin các món đã gọi
 */
class orderedDish
{
public:
    orderedDish(const int id, const char name[], const float price, const int quantity);
    void setQuantity(const int quantity);
    int getQuantity();
    char *getNameDish();
    float getPriceDish();
    int getIdDish();

private:
    char name[20];
    float price;
    int id;
    int quantity;
};

orderedDish::orderedDish(const int id, const char name[], const float price, const int quantity)
{
    orderedDish::id = id;
    orderedDish::quantity = quantity;
    orderedDish::price = price;
    strcpy(orderedDish::name, name);
}

void orderedDish::setQuantity(const int quantity)
{
    orderedDish::quantity = quantity;
}

int orderedDish::getQuantity()
{
    return orderedDish::quantity;
}

char *orderedDish::getNameDish()
{
    return orderedDish::name;
}

int orderedDish::getIdDish()
{
    return orderedDish::id;
}

float orderedDish::getPriceDish()
{
    return orderedDish::price;
}

class manager
{
public:
    manager() : id(100), numberOfTable(0) {}

    void setNumberOfTable(int n);

    int getNumberOfTable();

    void addDishes();

    void updateDish();

    void deleteDish();

    void showList();

    void managerOptions();
    void managerAddDish();
    void managerUpdateDish();
    void managerDeleteDish();

    vector<dishes> &getDishList() { return dishList; }

private:
    int id;
    int numberOfTable;
    vector<dishes> dishList;
};

void manager::setNumberOfTable(int n)
{
    manager::numberOfTable = n;
}

int manager::getNumberOfTable()
{
    return manager::numberOfTable;
}

/*
 * Function: addDishes
 * Description: hàm thêm món ăn của quản lý
 */
void manager::addDishes()
{
    int k;
    char name[20];
    float price;
    do
    {
        ENTER_DATA(" %s", &name, "Enter the name of the dish: ")
        ENTER_DATA("%f", &price, "Enter the price of the dish: ")
        dishes dish(id++, name, price);
        dishList.push_back(dish);
        printf("Enter 1 to continue add dish\n");
        ENTER_DATA("%d", &k, "Any key to exit: ");
    } while (k == 1);
}

/*
 * Function: updateDish
 * Description: hàm update danh sách món ăn theo id của quản lý
 */
void manager::updateDish()
{

    int key;
    int id;
    float newPrice;
    int check = 0;
    vector<dishes> *dish = &dishList;
    CHECK_DATA(
        dish,
        "No data\n",

        do {
            ENTER_DATA("%d", &id, "Input id of dish that you want to change: ");
            do
            {
                for (int index = 0; index < dish->size(); index++)
                {
                    if ((dish->at(index)).getId() == id)
                    {
                        check++;
                        ENTER_DATA("%f", &newPrice, "Input new price of the dish: ");
                        (dish->at(index)).setPriceOfDish(newPrice);
                    }
                }

                if (check == 0)
                {
                    ENTER_DATA("%d", &id, "Wrong id, input again: ");
                }
            } while (check == 0);

            printf("Enter 1 to continue update\n");
            ENTER_DATA("%d", &key, "Any key to exit: ");
        } while (key == 1);)
}

/*
 * Function: deleteDish
 * Description: hàm xóa danh sách món ăn theo id của quản lý
 */
void manager::deleteDish()
{
    int key;
    int id;
    int check = 0;
    vector<dishes> *dish = &dishList;
    CHECK_DATA(
        dish,
        "No data\n",
        do {
            ENTER_DATA("%d", &id, "Input id of dish that you want to delete: ");
            CHECK_ID(id,
                     check,
                     dish,
                     dishList.erase(dish->begin() + index);
                     printf("Deleting completed\n");)
            printf("Enter 1 to continue update\n");
            ENTER_DATA("%d", &key, "Any key to exit: ");
        } while (key == 1);)
}

/*
 * Function: showList
 * Description: hàm hiển thị danh sách món ăn của quản lý
 */
void manager::showList()
{
    int stt = 1;

    printf("STT     ID      DishName            Price\n");
    for (dishes dish : dishList)
    {
        printf("%d      %d      %s          %f\n", stt++, dish.getId(), (char *)dish.getNameOfDish(), dish.getPriceOfDish());
    }
}

void managerFunction(manager *manager)
{
    int key;
    int quantity = 0;

    do
    {
        printf("1. Add dish\n");
        printf("2. Update dish\n");
        printf("3. Delete dish\n");
        printf("4. Show the dished list\n");
        printf("5. Set the number of tables\n");
        printf("0. Exit\n");
        printf("-------------------------------------------\n");

        do
        {
            ENTER_DATA("%d", &key, "Select option: ");
        } while (key > 5 || key < 0);

        switch (key)
        {
        case option1:
            manager->addDishes();
            break;
        case option2:
            manager->updateDish();
            break;
        case option3:
            manager->deleteDish();
            break;
        case option4:
            manager->showList();
            break;
        case option5:
            ENTER_DATA("%d", &quantity, "Input the number of the tables: ");
            manager->setNumberOfTable(quantity);
            break;
        case 0:
            return;
        default:
            break;
        }
    } while (key);
}
/*
 * Function: Class bàn
 * Description: Chứa Property & Method sử dụng cho class staff
 */
class table
{
public:
    table(manager manager);
    void orderDish();
    void showOrderedDishes();
    void getBill();
    bool getStatusTable();
    void updateData(manager manager);

private:
    vector<orderedDish> orderedList;
    vector<dishes> dishList;
    bool status = 0;
    float bill;
};

table::table(manager manager)
{
    for (auto data : manager.getDishList())
    {
        dishList.push_back(data);
    }
}

void table::updateData(manager manager)
{
    dishList.clear();
    for (auto data : manager.getDishList())
    {
        dishList.push_back(data);
    }
}

/*
 * Function: orderDish
 * Description: gọi món
 */
void table::orderDish()
{
    int k;
    int check = 0;
    do
    {
        vector<dishes> *dish = &dishList;
        int id;
        int quantity;
        CHECK_DATA(dish,
                   "No data\n",
                   ENTER_DATA("%d", &id, "Enter the id which you want to order: ");
                   ENTER_DATA("%d", &quantity, "Enter the quantity of dishes which you want to order: ");
                   CHECK_ID(id,
                            check,
                            dish,
                            orderedDish ordered(dish->at(index).getId(), dish->at(index).getNameOfDish(), dish->at(index).getPriceOfDish(), quantity);
                            orderedList.push_back(ordered);
                            status = 1;)
                       printf("Enter 1 to continue order more\n");
                   ENTER_DATA("%d", &k, "Any key to exit: ");)

    } while (k == 1);
}
/*
 * Function: showOrderedDishes
 * Description: hiển thị danh sách món đã gọi
 */
void table::showOrderedDishes()
{
    int k;

    do
    {
        printf("STT     ID      Name    Quantity\n");
        int stt = 1;
        for (orderedDish dish : orderedList)
        {
            printf("%d      %d      %s      %d\n", stt++, dish.getIdDish(), dish.getNameDish(), dish.getQuantity());
        }
        printf("\nEnter 1 to continue order more\n");
        ENTER_DATA("%d", &k, "Any key to exit: ");
    } while (k == 1);
}

/*
 * Function: getBill
 * Description: xuất bill cho khách hàng
 */
void table::getBill()
{
    int k;
    printf("STT     ID      Name        Quantity        Price\n");
    int stt = 1;
    for (orderedDish dish : orderedList)
    {
        printf("%d      %d      %s          %d          %f\n", stt++, dish.getIdDish(), dish.getNameDish(), dish.getQuantity(), dish.getPriceDish());
    }
    do
    {
        for (orderedDish dish : orderedList)
        {
            table::bill += dish.getPriceDish() * dish.getQuantity();
        }
        printf("\nTotal: %f\n", table::bill);

        status = 0;
        orderedList.clear();
        printf("Enter 1 to continue get another bill\n");
        ENTER_DATA("%d", &k, "Any key to exit: ");
    } while (k == 1);
}

bool table::getStatusTable()
{
    return table::status;
}

class staff
{
public:
    void showStatusTable();
    void selectTable(int numTable);

    int getNumberOfTable();
    void getData(manager *manager);
    void getUpdateData(manager *manager);

private:
    vector<table> listTable;
    int numberOfTable = 0;
};

void staff::getData(manager *manager)
{
    staff::numberOfTable = manager->getNumberOfTable();
    for (int index = 0; index < staff::numberOfTable; index++)
    {
        table table(*manager);
        listTable.push_back(table);
    }
}

int staff::getNumberOfTable()
{
    return staff::numberOfTable;
}

void staff::showStatusTable()
{
    if (staff::numberOfTable != 0)
    {
        printf("Table     ");
        for (int index = 0; index < staff::numberOfTable; index++)
        {
            printf(" %d  |", index + 1);
        }
        printf("\nStatus    ");

        for (int index = 0; index < staff::numberOfTable; index++)
        {
            if (listTable.at(index).getStatusTable() == 1)
            {
                printf(" x  |");
            }
            else
            {
                printf("    |");
            }
        }
    }
    else
    {
        printf("No table added\n");
    }
}

void staff::selectTable(int numTable)
{
    int key;
    printf("Table No: %d\n", numTable);
    printf("1. Order the dish\n");
    printf("2. Show the dishes list\n");
    printf("3. Get bill\n");
    printf("0. Exit\n");
    ENTER_DATA("%d", &key, "Select option: ");
    switch (key)
    {
    case option1:
        listTable.at(numTable - 1).orderDish();
        break;
    case option2:
        listTable.at(numTable - 1).showOrderedDishes();
        break;
    case option3:
        listTable.at(numTable - 1).getBill();
        break;
    case option0:
        return;
    default:
        break;
    }
}

void staff::getUpdateData(manager *manager)
{
    int lastNumberOfTable = staff::numberOfTable;
    staff::numberOfTable = manager->getNumberOfTable();

    for (int index = 0; index < lastNumberOfTable; index++)
    {
        table table(*manager);
        listTable.at(index).updateData(*manager);
    }

    for (int index = lastNumberOfTable; index < staff::getNumberOfTable(); index++)
    {
        table table(*manager);
        listTable.push_back(table);
    }
}

void staffFunction(staff *staff)
{
    int key;
    do
    {
        staff->showStatusTable();
        printf("\n0. Exit\n");
        ENTER_DATA("%d", &key, "Select the table No: ");

        switch (key)
        {
        case option0:
            return;
        default:
            staff->selectTable(key);
            break;
        }
    } while (1);
}

void run()
{
    int key;
    manager manager;
    staff staff;

    do
    {
        printf("WELCOME TO ORDER SYSTEM\n");
        printf("1. Manager\n");
        printf("2. Staff\n");
        printf("0. Exit\n");
        printf("-------------------------------------------\n");
        do
        {
            ENTER_DATA("%d", &key, "Select option: ");
        } while (key > 2 || key < 0);

        switch (key)
        {
        case 1:
            managerFunction(&manager);
            staff.getData(&manager);
            break;
        case 2:

            staff.getUpdateData(&manager);
            staffFunction(&staff);
            break;
        case 0:
            exit(0);
        default:
            break;
        }

    } while (1);
}

int main(int argc, char const *argv[])
{
    run();
    return 0;
}
