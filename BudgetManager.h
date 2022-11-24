#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>


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

    /*time_t typePeroid();
    time_t setDate();
    bool isDateCorrect();
    bool fileExist();*/

    vector<Income>setTemporaryIncomeVectorCurrentMonth();
    vector<Expense>setTemporaryExpenseVectorCurrentMonth();
    vector<Income>setTemporaryIncomeVectorPreviousMonth();
    vector<Expense>setTemporaryExpenseVectorPreviousMonth();
    vector<Income>setTemporaryIncomeVectorChosenPeroid(string startDate, string endDate);
    vector<Expense>setTemporaryExpenseVectorChosenPeroid(string startDate, string endDate);
    double showIncomes (Income income);
    double showExpenses (Expense expense);

public:
    BudgetManager (int loggedUserId, string incomeFileName, string expenseFileName)
        : LOGGED_USER_ID (loggedUserId), incomeFile(incomeFileName), expenseFile (expenseFileName)
        {
            incomes = incomeFile.loadIncomeFromFile(LOGGED_USER_ID);
            expenses = expenseFile.loadExpenseFromFile(LOGGED_USER_ID);
        }

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showChosenPeroidBalance();


};
#endif
