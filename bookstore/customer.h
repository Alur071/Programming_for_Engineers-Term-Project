#ifndef UNTITLED1_CUSTOMER_H
#define UNTITLED1_CUSTOMER_H
#include <iostream>
class customer
{
public:
    customer();
    static void setCustomerName(std::string c_name, int line);
    static void setCustomerAge(int c_age, int line);
    static void setCustomerMoney(int c_money, int line);
    static std::string getCustomerName(int line);
    static int getCustomerAge(int line);
    static int getCustomerMoney(int line);
    static void getAll_Customers();
    static int sizeOfQueue();

};


#endif //UNTITLED1_CUSTOMER_H
