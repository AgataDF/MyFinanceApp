#include "BudgetManager.h"

void BudgetManager::addIncome() {
    time_t now;
    Income income;
    char choice;
    string date, item, amount;
    system("cls");

    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    income.setIncomeId(incomeFile.getlastIncomeId()+1);
    income.setUserId(LOGGED_USER_ID);

    cout << "Does the income relate to today (pick 1) or add with another date (pick 2)? " << endl;
    choice = AuxiliaryMethod::getChar();

    if (choice == '1') {
        now = time(0);
        struct tm tstruct;
        char date_char[50];
        tstruct = *localtime(&now);
        strftime(date_char, 50, "%Y%m%d", &tstruct);
        date = date_char;
        income.setIncomeDate(AuxiliaryMethod::convertStringToInt(date));
        cout << "What the income is about? " << endl;
        item = AuxiliaryMethod::getTypedLine();
        income.setItem(item);
        cout << "How much is the income: " << endl;
        amount = AuxiliaryMethod::getTypedLine();
        amount = AuxiliaryMethod::commaToDot(amount);
        income.setAmount(AuxiliaryMethod::convertStringToDouble(amount));
        incomes.push_back(income);
        incomeFile.addIncomeToFile(income);
        cout << "New income added to file." << endl;
        system("pause");
    } else if (choice == '2') {
        cout << "Type date (yyyy-mm-dd): ";
        date = AuxiliaryMethod::getTypedLine();
        date = AuxiliaryMethod::removeDashFromDate(date);
        if (AuxiliaryMethod::checkDate(date)) {
            income.setIncomeDate(AuxiliaryMethod::convertStringToInt(date));
            cout << "What the income is about? " << endl;
            item = AuxiliaryMethod::getTypedLine();
            income.setItem(item);
            cout << "How much is the income: " << endl;
            amount = AuxiliaryMethod::getTypedLine();
            amount = AuxiliaryMethod::commaToDot(amount);
            income.setAmount(AuxiliaryMethod::convertStringToDouble(amount));
            incomes.push_back(income);
            incomeFile.addIncomeToFile(income);
            cout << "New income added to file." << endl;
            system("pause");
        } else {
            cout << "Check the date again" <<endl;
            system("pause");
        }

    }
}

void BudgetManager::addExpense() {
    Expense expense;
    char choice;
    string date, item, amount;
    system("cls");

    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    expense.setExpenseId(expenseFile.getlastExpenseId()+1);
    expense.setUserId(LOGGED_USER_ID);

    cout << "Does the expense relate to today (pick 1) or add with another date (pick 2)? " << endl;
    choice = AuxiliaryMethod::getChar();

    if (choice == '1') {
        time_t now = time(0);
        struct tm tstruct;
        char date_char[50];
        tstruct = *localtime(&now);
        strftime(date_char, 50, "%Y%m%d", &tstruct);
        date = date_char;
        expense.setExpenseDate(AuxiliaryMethod::convertStringToInt(date));
        cout << "What the expense is about? " << endl;
        item = AuxiliaryMethod::getTypedLine();
        expense.setItem(item);
        cout << "How much is the expense: " << endl;
        amount = AuxiliaryMethod::getTypedLine();
        amount = AuxiliaryMethod::commaToDot(amount);
        expense.setAmount(AuxiliaryMethod::convertStringToDouble(amount));
        expenses.push_back(expense);
        expenseFile.addExpenseToFile(expense);
        cout << "New expense added to file." << endl;
        system("pause");
    } else if (choice == '2') {
        cout << "Type date (yyyy-mm-dd): ";
        date = AuxiliaryMethod::getTypedLine();
        date = AuxiliaryMethod::removeDashFromDate(date);
        if (AuxiliaryMethod::checkDate(date)) {
            expense.setExpenseDate(AuxiliaryMethod::convertStringToInt(date));
            cout << "What the expense is about? " << endl;
            item = AuxiliaryMethod::getTypedLine();
            expense.setItem(item);
            cout << "How much is the expense: " << endl;
            amount = AuxiliaryMethod::getTypedLine();
            amount = AuxiliaryMethod::commaToDot(amount);
            expense.setAmount(AuxiliaryMethod::convertStringToDouble(amount));
            expenses.push_back(expense);
            expenseFile.addExpenseToFile(expense);
            cout << "New expense added to file." << endl;
            system("pause");
        } else {
            cout << "Check the date again" <<endl;
            system("pause");
        }

    }
}

void BudgetManager::showCurrentMonthBalance() {
    vector <Income> tempIncomes = setTemporaryIncomeVectorCurrentMonth();
    vector <Expense> tempExpenses = setTemporaryExpenseVectorCurrentMonth();
    double balanceIncome = 0, balanceExpense = 0;
    system("cls");
    if (!tempIncomes.empty()&&!tempExpenses.empty()) {
        cout << "        >>> CURRENT MONTH BALACE <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Incomes:" << endl;
        for (vector <Income> :: iterator itr = tempIncomes.begin(); itr != tempIncomes.end(); itr++) {
            balanceIncome += showIncomes(*itr);
        }
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Expenses:" << endl;
        for (vector <Expense> :: iterator itr = tempExpenses.begin(); itr != tempExpenses.end(); itr++) {
            balanceExpense += showExpenses(*itr);
        }
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Sum of incomes:        "<< balanceIncome << endl;
        cout << "Sum of expenses:       "<< balanceExpense << endl;
        cout << "Total balance:         "<< balanceIncome - balanceExpense << endl;
    } else {
        cout << endl << "No incomes and expenses in current month." << endl << endl;
    }
    system("pause");
}

void BudgetManager::showPreviousMonthBalance() {
    vector <Income> tempIncomes = setTemporaryIncomeVectorPreviousMonth();
    vector <Expense> tempExpenses = setTemporaryExpenseVectorPreviousMonth();
    double balanceIncome = 0, balanceExpense = 0;
    system("cls");
    if (!tempIncomes.empty()&&!tempExpenses.empty()) {
        cout << "       >>> PREVIOUS MONTH BALACE <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Incomes:" << endl;
        for (vector <Income> :: iterator itr = tempIncomes.begin(); itr != tempIncomes.end(); itr++) {
            balanceIncome += showIncomes(*itr);
        }
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Expenses:" << endl;
        for (vector <Expense> :: iterator itr = tempExpenses.begin(); itr != tempExpenses.end(); itr++) {
            balanceExpense += showExpenses(*itr);
        }
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Sum of incomes:        "<< balanceIncome << endl;
        cout << "Sum of expenses:       "<< balanceExpense << endl;
        cout << "Total balance:         "<< balanceIncome - balanceExpense << endl;
    } else {
        cout << endl << "No incomes and expenses in previous month." << endl << endl;
    }
    system("pause");
}

void BudgetManager::showChosenPeroidBalance() {
    system("cls");
    string startDate, endDate;
    double balanceIncome = 0, balanceExpense = 0;

    cout << "Type the start date of the period (yyyy-mm-dd): " << endl;
    startDate = AuxiliaryMethod::getTypedLine();
    startDate = AuxiliaryMethod::removeDashFromDate(startDate);

    if (AuxiliaryMethod::checkDate(startDate)) {
        cout << "Type the end date of the period (yyyy-mm-dd): " << endl;
        endDate = AuxiliaryMethod::getTypedLine();
        endDate = AuxiliaryMethod::removeDashFromDate(endDate);

        if (AuxiliaryMethod::checkDate(endDate)) {
            vector <Income> tempIncomes = setTemporaryIncomeVectorChosenPeroid(startDate, endDate);
            vector <Expense> tempExpenses = setTemporaryExpenseVectorChosenPeroid(startDate, endDate);

            if (!tempIncomes.empty()&&!tempExpenses.empty()) {
                cout << ">>> BALANCE FROM "<<AuxiliaryMethod::addDashesToDate(startDate) << " TO " << AuxiliaryMethod::addDashesToDate(endDate) << " <<<" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Incomes:" << endl;
                for (vector <Income> :: iterator itr = tempIncomes.begin(); itr != tempIncomes.end(); itr++) {
                    balanceIncome += showIncomes(*itr);
                }
                cout << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Expenses:" << endl;
                for (vector <Expense> :: iterator itr = tempExpenses.begin(); itr != tempExpenses.end(); itr++) {
                    balanceExpense += showExpenses(*itr);
                }
                cout << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Sum of incomes:        "<< balanceIncome << endl;
                cout << "Sum of expenses:       "<< balanceExpense << endl;
                cout << "Total balance:         "<< balanceIncome - balanceExpense << endl;
            } else {
                cout << endl << "No incomes and expenses in chosen peroid." << endl << endl;
            }
            system("pause");
        } else {
            cout << "Try again" << endl;
            system("pause");
        }
    } else {
        cout << "Try again" << endl;
        system("pause");
    }
}

vector <Income> BudgetManager::setTemporaryIncomeVectorCurrentMonth() {
    Income temp;
    vector <Income> temporary;

    time_t now = time(0);
    struct tm tstruct;
    char date_char[10];
    tstruct = *localtime(&now);
    strftime(date_char, 10, "%Y%m", &tstruct);
    string dateNow = date_char;

    for (unsigned int i = 0; i < incomes.size(); i++) {
        string incomeDate = AuxiliaryMethod::convertIntToString(incomes[i].getIncomeDate());
        incomeDate = incomeDate.substr(0, 6);
        if ( incomeDate == dateNow ) {
            temp.setIncomeDate(incomes[i].getIncomeDate());
            temp.setItem(incomes[i].getItem());
            temp.setAmount(incomes[i].getAmount());
            temporary.push_back(temp);
        }
    }

    sort( temporary.begin( ), temporary.end( ), [ ]( Income& lhs,  Income& rhs ) {
        return lhs.getIncomeDate() < rhs.getIncomeDate();
    });
    return temporary;
}

vector <Expense> BudgetManager::setTemporaryExpenseVectorCurrentMonth() {
    Expense temp;
    vector <Expense> temporary;

    time_t now = time(0);
    struct tm tstruct;
    char date_char[10];
    tstruct = *localtime(&now);
    strftime(date_char, 10, "%Y%m", &tstruct);
    string dateNow = date_char;

    for (unsigned int i = 0; i < expenses.size(); i++) {
        string expenseDate = AuxiliaryMethod::convertIntToString(expenses[i].getExpenseDate());
        expenseDate = expenseDate.substr(0, 6);
        if ( expenseDate == dateNow ) {
            temp.setExpenseDate(expenses[i].getExpenseDate());
            temp.setItem(expenses[i].getItem());
            temp.setAmount(expenses[i].getAmount());
            temporary.push_back(temp);
        }
    }

    sort( temporary.begin( ), temporary.end( ), [ ]( Expense& lhs, Expense& rhs ) {
        return lhs.getExpenseDate() < rhs.getExpenseDate();
    });
    return temporary;
}

double BudgetManager::showIncomes (Income income) {
    string date = AuxiliaryMethod::addDashesToDate(AuxiliaryMethod::convertIntToString(income.getIncomeDate()));
    cout << endl << "Date:          " << date << endl;
    cout << "Item:          " << income.getItem()<< endl;
    cout << "Amount:        " << income.getAmount() << endl;
    return income.getAmount();
}

double BudgetManager::showExpenses (Expense expense) {
    string date = AuxiliaryMethod::addDashesToDate(AuxiliaryMethod::convertIntToString(expense.getExpenseDate()));
    cout << endl << "Date:          " << date << endl;
    cout << "Item:          " << expense.getItem()<< endl;
    cout << "Amount:        " << expense.getAmount() << endl;
    return expense.getAmount();
}

vector <Income> BudgetManager::setTemporaryIncomeVectorPreviousMonth() {
    Income temp;
    vector <Income> temporary;

    time_t now = time(0);
    struct tm tstruct;
    char date_char[10];
    tstruct = *localtime(&now);
    strftime(date_char, 10, "%Y%m", &tstruct);
    string dateNowString = date_char;

    string month = dateNowString.substr(4, 2);
    string year = dateNowString.substr(0, 4);

    string datePreviousString;

    if (month != "01") {
        datePreviousString = AuxiliaryMethod::convertIntToString(AuxiliaryMethod::convertStringToInt(dateNowString) - 1);
    } else {
        year = AuxiliaryMethod::convertIntToString(AuxiliaryMethod::convertStringToInt(year) - 1);
        datePreviousString = year+"12";
    }

    for (unsigned int i = 0; i < incomes.size(); i++) {
        string incomeDate = AuxiliaryMethod::convertIntToString(incomes[i].getIncomeDate());
        incomeDate = incomeDate.substr(0, 6);
        if ( incomeDate == datePreviousString ) {
            temp.setIncomeDate(incomes[i].getIncomeDate());
            temp.setItem(incomes[i].getItem());
            temp.setAmount(incomes[i].getAmount());
            temporary.push_back(temp);
        }
    }

    sort( temporary.begin( ), temporary.end( ), [ ]( Income& lhs, Income& rhs ) {
        return lhs.getIncomeDate() < rhs.getIncomeDate();
    });
    return temporary;
}

vector <Expense> BudgetManager::setTemporaryExpenseVectorPreviousMonth() {
    Expense temp;
    vector <Expense> temporary;

    time_t now = time(0);
    struct tm tstruct;
    char date_char[10];
    tstruct = *localtime(&now);
    strftime(date_char, 10, "%Y%m", &tstruct);
    string dateNowString = date_char;

    string month = dateNowString.substr(4, 2);
    string year = dateNowString.substr(0, 4);

    string datePreviousString;

    if (month != "01") {
        datePreviousString = AuxiliaryMethod::convertIntToString(AuxiliaryMethod::convertStringToInt(dateNowString) - 1);
    } else {
        year = AuxiliaryMethod::convertIntToString(AuxiliaryMethod::convertStringToInt(year) - 1);
        datePreviousString = year+"12";
    }
    for (unsigned int i = 0; i < expenses.size(); i++) {
        string expenseDate = AuxiliaryMethod::convertIntToString(expenses[i].getExpenseDate());
        expenseDate = expenseDate.substr(0, 6);
        if ( expenseDate == datePreviousString ) {
            temp.setExpenseDate(expenses[i].getExpenseDate());
            temp.setItem(expenses[i].getItem());
            temp.setAmount(expenses[i].getAmount());
            temporary.push_back(temp);
        }
    }
    sort( temporary.begin( ), temporary.end( ), [ ]( Expense& lhs, Expense& rhs ) {
        return lhs.getExpenseDate() < rhs.getExpenseDate();
    });
    return temporary;
}

vector <Income> BudgetManager::setTemporaryIncomeVectorChosenPeroid(string startDate, string endDate) {
    Income temp;
    vector <Income> temporary;

    int fromStart = AuxiliaryMethod::convertStringToInt(startDate);
    int toEnd = AuxiliaryMethod::convertStringToInt(endDate);

    for (unsigned int i = 0; i < incomes.size(); i++) {
        int incomeDate = incomes[i].getIncomeDate();
        if (( incomeDate >= fromStart )&&  ( incomeDate <= toEnd)) {
            temp.setIncomeDate(incomes[i].getIncomeDate());
            temp.setItem(incomes[i].getItem());
            temp.setAmount(incomes[i].getAmount());
            temporary.push_back(temp);
        }
    }

    sort( temporary.begin( ), temporary.end( ), [ ]( Income& lhs, Income& rhs ) {
        return lhs.getIncomeDate() < rhs.getIncomeDate();
    });
    return temporary;
}

vector <Expense> BudgetManager::setTemporaryExpenseVectorChosenPeroid(string startDate, string endDate) {
    Expense temp;
    vector <Expense> temporary;

    int fromStart = AuxiliaryMethod::convertStringToInt(startDate);
    int toEnd = AuxiliaryMethod::convertStringToInt(endDate);

    for (unsigned int i = 0; i < expenses.size(); i++) {
        int expenseDate = expenses[i].getExpenseDate();
        if (( expenseDate >= fromStart )&&  ( expenseDate <= toEnd)) {
            temp.setExpenseDate(expenses[i].getExpenseDate());
            temp.setItem(expenses[i].getItem());
            temp.setAmount(expenses[i].getAmount());
            temporary.push_back(temp);
        }
    }

    sort( temporary.begin( ), temporary.end( ), [ ]( Expense& lhs, Expense& rhs ) {
        return lhs.getExpenseDate() < rhs.getExpenseDate();
    });
    return temporary;
}

