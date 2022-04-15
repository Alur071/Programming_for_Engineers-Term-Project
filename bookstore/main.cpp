//----------------------------------------------------------------------------
//  Name of the Contributors: Ali Ugur Yüce, Burak Gödek, Mehmet Berat Öztürk
//  ID of the Contributors: 64190010, 64190011, 64190003
//----------------------------------------------------------------------------
#include <iostream>
#include "BookStore.h"
#include "customer.h"
#include "Dealer.h"

using namespace std;


void menu_for_Identity();
void menu_Employee();
void menu_for_Customer();
void menu_for_Dealer();
void Choice_Employee();
void Choice_Customer();
void Choice_Dealer(BookStore& db);
void printAll_Books();
void printAll_Customers();
void printAll_Dealer();
void Initial_BooksOfDealer();
void InitialBooks();


int main() {
    BookStore db;
    Initial_BooksOfDealer();
    InitialBooks();
    int Identity_num;
    menu_for_Identity();
    cout << "Enter you Choice:" << endl;
    cin >> Identity_num;

    while (Identity_num != 4) {

        if (Identity_num == 1) {

            Choice_Customer();
            cout << "\n";
            menu_for_Identity();
            cout << "Enter you Choice:" << endl;
            cin >> Identity_num;

        } else if (Identity_num == 2) {

            Choice_Employee();
            cout << "\n";
            menu_for_Identity();
            cout << "Enter you Choice:" << endl;
            cin >> Identity_num;

        } else if (Identity_num == 3) {
            Choice_Dealer(db);
            cout << "\n";
            menu_for_Identity();
            cout << "Enter you Choice:" << endl;
            cin >> Identity_num;
        }
    }
    return 0;
}

//-----------------------------------------------
// These are to print the menus for each Person!
//-----------------------------------------------

void menu_for_Identity(){
    cout << "-----------------------------------------" << endl;
    cout << "If you are a Customer press 1" << endl;
    cout << "If you are a Employee press 2" << endl;
    cout << "If you are a Dealer press 3" << endl;
    cout << "If you want to exit back press 4" << endl;
    cout << "-----------------------------------------" << endl;
}


void menu_Employee(){
    cout << "-----------------------------------------" << endl;
    cout << "BOOKSTORE:" << endl;
    cout << "Press 1 to set or update Book Name, Book Price and Book Amount" << endl;
    cout << "Press 2 to set or update only Book Name" << endl;
    cout << "Press 3 to set or update only Book Price" << endl;
    cout << "Press 4 to set or update only Book Amount" << endl;
    cout << "Press 5 to display selected Positions" << endl;
    cout << "Press 6 to display All Positions" << endl;
    cout << "Press 7 to serve all customers" << endl;
    cout << "Press 8 to go Back" << endl;
    cout << "-----------------------------------------" << endl;
}


void menu_for_Customer(){
    cout << "-----------------------------------------" << endl;
    cout << "If you want to enter your Name, Age, Money, line press 1" << endl; // we can sett age money by pressin 1
    cout << "If you want to print the line of all Customers press 2" << endl;
    cout << "If you want to print a selected line of Customers press 3" << endl;
    cout << "If you want to see the Books in the Store press 4" << endl;
    cout << "If you want to go back press 5" << endl;
    cout << "-----------------------------------------" << endl;
}

void menu_for_Dealer(){
    cout << "-----------------------------------------" << endl;
    cout << "If you want to show the Employee the sellable Books press 1" << endl;
    cout << "If you agreed to sell a book from one of the Positions press 2" << endl;
    cout << "If you want to go back press 3" << endl;
    cout << "-----------------------------------------" << endl;
}

//-----------------------------------------------
// These are to execute the Choices of the Executor!
//-----------------------------------------------

void Choice_Employee(){
    menu_Employee();
    string bookname;

    int pos, bookprice, bookamount;

    int num;
    cout << "Enter Choice:" << endl;
    cin >> num;
    while (num != 8) {

        if (num == 1) {
            cout << "Book Name:" << endl;
            cin >> bookname;
            cout << "Book Price:" << endl;
            cin >> bookprice;
            cout << "Book Amount:" << endl;
            cin >> bookamount;
            cout << "Book Position (0-19):" << endl;
            cin >> pos;

            BookStore::setBookName(bookname, pos);
            BookStore::setBookPrice(bookprice, pos);
            BookStore::setBookAmount(bookamount, pos);

            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;

        } else if (num == 2){
            cout << "Book Name:" << endl;
            cin >> bookname;
            cout << "Book Position (0-19):" << endl;
            cin >> pos;
            BookStore::setBookName(bookname, pos);

            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;

        } else if (num == 3) {
            cout << "Book Price:" << endl;
            cin >> bookprice;
            cout << "Book Position (0-19):" << endl;
            cin >> pos;
            BookStore::setBookPrice(bookprice, pos);

            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;

        } else if (num == 4) {
            cout << "Book Amount:" << endl;
            cin >> bookamount;
            cout << "Book Position (0-19):" << endl;
            cin >> pos;
            BookStore::setBookAmount(bookamount, pos);

            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;

        }else if(num == 5){

            int position;
            cout << "Enter the Position you want to get printed: " << endl;
            cin >> position;
            cout << "\n-----------------------------------------" << endl;
            cout << "Pos " << position << endl;
            cout << "Book Name: " << BookStore::getBookName(position) << endl;
            cout << "Book Price: " << BookStore::getBookPrice(position) << " $" << endl;
            cout << "Book Amount: " << BookStore::getBookAmount(position) << endl;
            cout << "-----------------------------------------" << endl;
            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;

        } else if(num == 6){
            cout << "\n-----------------------------------------" << endl;
            printAll_Books();
            cout << "-----------------------------------------" << endl;
            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;
        } else if(num == 7){
            int a = customer::sizeOfQueue();
            for (int i=0;i<=a;i++){

                if(customer::getCustomerName(i).empty()){
                    cout << "\nThere are no Customers!" << endl;
                    break;
                }
                while(!customer::getCustomerName(i).empty()){
                    int pos_Queue;
                    cout << "\n-----------------------------------------" << endl;
                    printAll_Books();
                    cout << "-----------------------------------------" << endl;
                    cout << "Ask Customer the Position of the book they want to buy:" << endl;
                    cin >> pos_Queue;
                    string name = BookStore::getBookName(pos_Queue);

                    if(pos_Queue > 19 ||pos_Queue < 0){
                        cout << "There is no Position " << pos_Queue << endl;
                        exit(1);
                    } else if(!BookStore::IsThereAnyBook(name)){
                        cout << "This Book is not in Stock!" << endl;
                    } else if(BookStore::getBookAmount(pos_Queue) == 0){
                        cout << "This Book is sold out!" << endl;
                    } else if(customer::getCustomerMoney(pos_Queue) < BookStore::getBookPrice(pos_Queue)){
                        cout << "You dont have enough Money to buy that book!" << endl;
                        break;
                    } else {
                        BookStore::Sell_Book(pos_Queue);
                        cout << customer::getCustomerName(pos_Queue) << " has bought "
                                                << BookStore::getBookName(pos_Queue) << " and is very happy!"<< endl;
                        customer::setCustomerName("", pos_Queue);
                        customer::setCustomerAge(0, pos_Queue);
                        customer::setCustomerMoney(0, pos_Queue);

                        }
                }
            }
        }

            cout << "\n";
            menu_Employee();
            cout << "Enter what next:" << endl;
            cin >> num;
        }
    }



void Choice_Customer(){

    int choice_customer;
    menu_for_Customer();
    cout << "Enter your Choice:" << endl;
    cin >> choice_customer;

    while (choice_customer != 5) {

        if (choice_customer == 1) {
            string name_customer;
            int line, customer_age, customer_Money;
            cout << "Customer Name:" << endl;
            cin >> name_customer;

            cout << "Customer Age:" << endl;
            cin >> customer_age;

            cout << "Customer Money:" << endl;
            cin >> customer_Money;

            cout << "Customer line (0-9):" << endl;
            cin >> line;
            customer::setCustomerName(name_customer, line);
            customer::setCustomerAge(customer_age, line);
            customer::setCustomerMoney(customer_Money, line);

            cout << "\n";
            menu_for_Customer();
            cout << "Enter what next:" << endl;
            cin >> choice_customer;

        } else if (choice_customer == 2) {

            cout << "\n-----------------------------------------" << endl;
            printAll_Customers();
            cout << "-----------------------------------------" << endl;

            cout << "\n";
            menu_for_Customer();
            cout << "Enter what next:" << endl;
            cin >> choice_customer;

        } else if(choice_customer == 3){

            int line;
            cout << "Enter the Line you want to get printed: " << endl;
            cin >> line;
            cout << "\n-----------------------------------------" << endl;
            std::cout << "\nLine " << line << std::endl;
            std::cout << "Customer Name: " << customer::getCustomerName(line) << std::endl;
            std::cout << "Customer Age: " << customer::getCustomerAge(line) << std::endl;
            std::cout << "Customer Money " << customer::getCustomerMoney(line) <<  " $" <<std::endl;
            cout << "-----------------------------------------" << endl;

            cout << "\n";
            menu_for_Customer();
            cout << "Enter what next:" << endl;
            cin >> choice_customer;
        } else if(choice_customer == 4){
            cout << "\n-----------------------------------------" << endl;
            printAll_Books();
            cout << "-----------------------------------------" << endl;

            cout << "\n";
            menu_for_Customer();
            cout << "Enter what next:" << endl;
            cin >> choice_customer;
        }
    }
}


void Choice_Dealer(BookStore& db){
    int choice_Dealer;
    menu_for_Dealer();
    cout << "Enter your Choice:" << endl;
    cin >> choice_Dealer;
    while (choice_Dealer != 3) {

        if (choice_Dealer == 1) {
            cout << "\n-----------------------------------------" << endl;
            printAll_Dealer();
            cout << "-----------------------------------------" << endl;

            cout << "\n";
            menu_for_Dealer();
            cout << "Enter what next:" << endl;
            cin >> choice_Dealer;

        } else if(choice_Dealer == 2){
            int pos_sell, pos_booksehlf;
            cout << "\n-----------------------------------------" << endl;
            printAll_Dealer();
            cout << "-----------------------------------------" << endl;
            cout << "\nEnter the Position of the Book you want to sell:" << endl;
            cin >> pos_sell;
            Dealer::Sell(pos_sell, db);

            cout << "\n-----------------------------------------" << endl;
            BookStore::getAll();
            cout << "-----------------------------------------" << endl;
            cout << "\nEnter the Position of the Bookshelf you want to enter it:" << endl;
            cin >> pos_booksehlf;
            BookStore::Buy_Book(pos_booksehlf);

            cout << "\n";
            menu_for_Dealer();
            cout << "Enter what next:" << endl;
            cin >> choice_Dealer;
        }
    }
}

//-----------------------------------------------
// These are to print everything!
//-----------------------------------------------

void printAll_Books(){
    cout << "All Books in Store!" << endl;
    BookStore::getAll();
}


void printAll_Customers(){
    customer::getAll_Customers();
}


void printAll_Dealer(){
    cout << "All Books of Dealer!" << endl;
    Dealer::getAll_Dealer();
}

//-----------------------------------------------
// These are the Initial Books in Stock!
//-----------------------------------------------

void Initial_BooksOfDealer(){
    Dealer::InitialBooksOfDealer();
}


void InitialBooks(){
    BookStore::InitialBooks();
}
