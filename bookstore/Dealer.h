#ifndef UNTITLED1_DEALER_H
#define UNTITLED1_DEALER_H
#include <iostream>
#include "BookStore.h"
class Dealer
{
public:
    Dealer();
    static void setBookNameDealer(std::string booknameDealer, int pos);
    static void setBookPriceDealer(int priceDealer, int pos);
    static void setBookAmountDealer(int amountDealer, int pos);
    static std::string getBookNameDealer(int pos);
    static int getBookPriceDealer(int pos);
    static int getBookAmountDealer(int pos);
    static void getAll_Dealer();
    static void InitialBooksOfDealer();
    static void Sell(int pos,BookStore& db);
};
#endif //UNTITLED1_DEALER_H
