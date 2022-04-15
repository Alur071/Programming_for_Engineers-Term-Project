# include "customer.h"

customer::customer() = default;

    struct Customer {
        std::string CustomerName = "";
        int CustomerAge = 0;
        int CustomerMoney = 0;
    };

    Customer customer_line[10]; // creating list of 10 struct

    void customer::setCustomerName(std::string c_name, int line){ //these are to set the name methods
        customer_line[line].CustomerName = {std::move(c_name)};
    }

    void customer::setCustomerAge(int c_age ,int line){
        customer_line[line].CustomerAge = c_age;
    }

    void customer::setCustomerMoney(int c_money, int line){
        customer_line[line].CustomerMoney = c_money;
    }

    std::string customer::getCustomerName(int line){ // these get methods are to return the cust
        std::string str = customer_line[line].CustomerName;
        return str;
    }

    int customer::getCustomerAge(int line){
        int num = customer_line[line].CustomerAge;
        return num;
    }

    int customer::getCustomerMoney(int line){
        int num = customer_line[line].CustomerMoney;
        return num;
    }

    void customer::getAll_Customers(){ //to display the name age and money
        int a = sizeof(customer_line)/sizeof(customer_line[0]);
        for(int i=0;i<a;i++){
            std::cout << "\nLine " << i << std::endl;
            std::cout << "Customer Name: " << customer_line[i].CustomerName << std::endl;
            std::cout << "Customer Age: " <<customer_line[i].CustomerAge << std::endl;
            std::cout << "Customer Money " << customer_line[i].CustomerMoney <<  " $" <<std::endl;
        }
    }

    int customer::sizeOfQueue(){ //and this returns to size of the que
        int a = sizeof(customer_line)/sizeof(customer_line[0]);
        return a;
    }

