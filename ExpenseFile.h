#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include "DBFile.h"
#include "AuxiliaryMethod.h"
#include "Expense.h"
#include "Markup.h"

using namespace std;

class ExpenseFile : public DBFile
{
    CMarkup xml;

    int lastExpenseId;
    int setlastExpenseIdFromFile();

public:
    ExpenseFile(string fileName) : DBFile(fileName)
    {
    lastExpenseId = setlastExpenseIdFromFile();
    };
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpenseFromFile(int currentUserId);
    void saveAllExpensesToFile(vector <Expense> &expenses);

    int getlastExpenseId();

};
#endif
