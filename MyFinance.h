#ifndef MYFINANCE_H
#define MYFINANCE_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class MyFinance
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    MyFinance(string userFileName, string incomeFileName, string expenseFileName)
        :userManager(userFileName),INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
    {
        budgetManager = NULL;
    };
    ~MyFinance()
    {
        delete budgetManager;
        budgetManager = NULL;
    };
    void signUpUser();
    void signInUser();
    void signOutUser();
    void writeAllUsers();
    void changePassword();
    char chooseFromMainMenu();
    char chooseFromUserMenu();
    bool isUserLoggedIn();
};
#endif
