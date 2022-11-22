#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId, userId, incomeDate;
    double amount;
    string item;

public:
    //Income();
    void setIncomeId (int newId);
    void setUserId (int newId);
    void setIncomeDate (int newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);

    int getIncomeId();
    int getUserId();
    int getIncomeDate();
    string getItem();
    double getAmount();
};
#endif
