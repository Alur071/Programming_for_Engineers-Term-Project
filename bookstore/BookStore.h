#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>

class BookStore
{
public:
    BookStore();
    struct BookShelf {
        std::string BookName;
        int BookPrice{};
        int BookAmount{};
    };

    static void addBook(std::string bookname, int price, int amount);
    static void setBookName(std::string bookname, int pos);
    static void setBookPrice(int price, int pos);
    static void setBookAmount(int amount, int pos);
    static std::string getBookName(int pos);
    static int getBookPrice(int pos);
    static int getBookAmount(int pos);
    static void getAll();
    static BookShelf getBook(std::string bookname);
    static void setBookAfterSell(std::string bookname);
    static void InitialBooks();
    void static Buy_Book(int pos);
    void static Sell_Book(int pos);
    static bool IsThereAnyBook(std::string bookname);

};

#endif //BOOKSTORE_H
