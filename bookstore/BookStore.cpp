#include "BookStore.h"

BookStore::BookStore() = default;

    BookStore::BookShelf bookshelf[20];

    void BookStore::setBookName(std::string bookname,int pos){
        bookshelf[pos].BookName = {std::move(bookname)};
    }

    void BookStore::setBookPrice(int BookPrice,int pos){
        bookshelf[pos].BookPrice = BookPrice;
    }

    void BookStore::setBookAmount(int Amount,int pos){
        bookshelf[pos].BookAmount = Amount;
    }

    void BookStore::setBookAfterSell(std::string bookname) {
        BookShelf bs = BookStore::getBook(bookname);
        bs.BookAmount += 1;

    }

    std::string BookStore::getBookName(int pos){
        std::string str = bookshelf[pos].BookName;
        return str;
    }

    int BookStore::getBookPrice(int pos){
        int num = bookshelf[pos].BookPrice;
        return num;
    }

    int BookStore::getBookAmount(int pos){
        int num = bookshelf[pos].BookAmount;
        return num;
    }

    bool BookStore::IsThereAnyBook(std::string bookname) {
        bool isHere = false;
        int a = sizeof(bookshelf)/sizeof(bookshelf[0]);

        for (int i = 0 ; i < a; i++ ) {
            if (bookshelf[i].BookName == bookname) {
                isHere = true;
            }
        }

        return isHere;
    }

    void BookStore::getAll(){
        int a = sizeof(bookshelf)/sizeof(bookshelf[0]);
        for(int i=0;i<a;i++){
            std::cout << "\nPos " << i << std::endl;
            std::cout << "Book Name: " << bookshelf[i].BookName << std::endl;
            std::cout << "Book Price: " <<bookshelf[i].BookPrice << " $" << std::endl;
            std::cout << "Book Amount " << bookshelf[i].BookAmount << std::endl;
        }
    }

    void BookStore::InitialBooks() {
        bookshelf[0].BookName = "HarryPotter";
        bookshelf[0].BookPrice = 20;
        bookshelf[0].BookAmount = 2;

        bookshelf[1].BookName = "Labyrinth";
        bookshelf[1].BookPrice = 15;
        bookshelf[1].BookAmount = 4;

        bookshelf[2].BookName = "TheLordOfTheRings";
        bookshelf[2].BookPrice = 25;
        bookshelf[2].BookAmount = 1;

        bookshelf[3].BookName = "Chocolat";
        bookshelf[3].BookPrice = 30;
        bookshelf[3].BookAmount = 2;

        bookshelf[4].BookName = "Hannibal";
        bookshelf[4].BookPrice = 15;
        bookshelf[4].BookAmount = 3;
    }

    void BookStore::Buy_Book(int pos){
        bookshelf[pos].BookAmount += 1;
    }

    void BookStore::Sell_Book(int pos){
        bookshelf[pos].BookAmount -= 1;
    }


    BookStore::BookShelf BookStore::getBook(std::string bookname) {
        int a = sizeof(bookshelf)/sizeof(bookshelf[0]);

        for (int i = 0;  i < a; i++ ) {
            if (bookshelf[i].BookName == bookname) {
                return bookshelf[i];
            }
        }
    }

    void BookStore::addBook(std::string bookname, int price, int amount) {
        int index = sizeof(bookshelf);

        bookshelf[index + 1].BookName = bookname;
        bookshelf[index + 1].BookAmount = amount;
        bookshelf[index + 1].BookPrice = price;
    }
