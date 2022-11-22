#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <vector>
#include <cstdlib>
#include <time.h>


#include "IncomeFile.h"
#include "Income.h"
#include "ExpenseFile.h"
#include "Expense.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    time_t typePeroid();
    time_t setDate();
    bool isDateCorrect();
    bool fileExist();
    void sortCashOperationsByDate();

public:
    BudgetManager (string incomeFileName, string expenseFileName, int loggedUserId)
        : incomeFile(incomeFileName), expenseFile (expenseFileName), LOGGED_USER_ID (loggedUserId)
        {
            incomes = incomeFile.loadIncomeFromFile(LOGGED_USER_ID);
            expenses = expenseFile.loadExpenseFromFile(LOGGED_USER_ID);
        }

    void addIncome();
    //void loadUserIncomes ();
    void showIncomes ();
    void addExpense();
    //void loadUserExpenses ();
    void showExpenses ();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showChosenPeroidBalance();


};
#endif
