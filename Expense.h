#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int expenseId, userId, expenseDate;
    double amount;
    string item;

public:
    //Expense();
    void setExpenseId (int newId);
    void setUserId (int newId);
    void setExpenseDate (int newDate);
    void setItem (string newItem);
    void setAmount (double newAmount);

    int getExpenseId();
    int getUserId();
    int getExpenseDate();
    string getItem();
    double getAmount();
};
#endif
