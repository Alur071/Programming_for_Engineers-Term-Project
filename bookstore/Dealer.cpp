# include "Dealer.h"

Dealer::Dealer() = default;

    struct Dealer_Books {
        std::string BookNameOfDealer;
        int BookPriceOfDealer{};
        int BookAmountOfDealer{};
    };

    Dealer_Books BooksOfDealer[3];

    void Dealer::InitialBooksOfDealer(){
        BooksOfDealer[0].BookNameOfDealer = "HarryPotter";
        BooksOfDealer[0].BookPriceOfDealer = 20;
        BooksOfDealer[0].BookAmountOfDealer = 2;

        BooksOfDealer[1].BookNameOfDealer = "TheLordOfTheRings";
        BooksOfDealer[1].BookPriceOfDealer = 25;
        BooksOfDealer[1].BookAmountOfDealer = 1;

        BooksOfDealer[2].BookNameOfDealer = "Labyrinth";
        BooksOfDealer[2].BookPriceOfDealer = 15;
        BooksOfDealer[2].BookAmountOfDealer = 4;

    }

    void Dealer::setBookNameDealer(std::string bookname,int pos){
        BooksOfDealer[pos].BookNameOfDealer = {std::move(bookname)};
    }

    void Dealer::setBookPriceDealer(int BookPrice,int pos){
        BooksOfDealer[pos].BookPriceOfDealer = BookPrice;
    }

    void Dealer::setBookAmountDealer(int Amount,int pos){
        BooksOfDealer[pos].BookAmountOfDealer = Amount;
    }

    std::string Dealer::getBookNameDealer(int pos){
        std::string str = BooksOfDealer[pos].BookNameOfDealer;
        return str;
    }

    int Dealer::getBookPriceDealer(int pos){
        int num = BooksOfDealer[pos].BookPriceOfDealer;
        return num;
    }

    int Dealer::getBookAmountDealer(int pos){
        int num = BooksOfDealer[pos].BookAmountOfDealer;
        return num;
    }

    void Dealer::getAll_Dealer(){
        int a = sizeof(BooksOfDealer)/sizeof(BooksOfDealer[0]);
        for(int i=0;i<a;i++){
            std::cout << "\nPos " << i << std::endl;
            std::cout << "Book Name: " << BooksOfDealer[i].BookNameOfDealer << std::endl;
            std::cout << "Book Price: " << BooksOfDealer[i].BookPriceOfDealer << " $" << std::endl;
            std::cout << "Book Amount " << BooksOfDealer[i].BookAmountOfDealer << std::endl;
        }
    }

    void Dealer::Sell(int pos, BookStore& db){
        bool isHere = db.IsThereAnyBook(BooksOfDealer[pos].BookNameOfDealer);
        if (isHere) {
            db.setBookAfterSell(BooksOfDealer[pos].BookNameOfDealer);
        } else {
            db.addBook(BooksOfDealer[pos].BookNameOfDealer , BooksOfDealer[pos].BookPriceOfDealer,
                                                                        BooksOfDealer[pos].BookAmountOfDealer);
        }
        BooksOfDealer[pos].BookAmountOfDealer -= 1;
    }
