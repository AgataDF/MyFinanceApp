#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    time_t now;
    Income inc;
    char choice;
    string date, item, amount;
    system("cls");

/*
    xml.AddElem("IncomeId", AuxiliaryMethod::convertIntToString(incomes[i].getIncomeId()));
    xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(incomes[i].getUserId()));
    xml.AddElem("Date", AuxiliaryMethod::convertIntToString(incomes[i].getIncomeDate()));
    xml.AddElem("Item", incomes[i].getItem());
    xml.AddElem("Amount", AuxiliaryMethod::convertDoubleToString(incomes[i].getAmount()));*/

    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    inc.setIncomeId(incomeFile.getlastIncomeId()+1);
    inc.setUserId(LOGGED_USER_ID);

    cout << "Does the income relate to today (pick 1) or add with another date (pick 2)? " << endl;
    choice = AuxiliaryMethod::getChar();

    if (choice == '1')
    {
        time_t now = time(0);
        struct tm tstruct;
        char date_char[50];
        tstruct = *localtime(&now);
        strftime(date_char, 50, "%Y%m%d", &tstruct);
        date = date_char;
        cout << date << endl;
        inc.setIncomeDate(AuxiliaryMethod::convertStringToInt(date));
        cout << inc.getIncomeDate() << endl;
        system("pause");
        cout << "What the income is about? " << endl;
        item = AuxiliaryMethod::getTypedLine();
        inc.setItem(item);
        cout << inc.getItem() << endl;
        system("pause");
        cout << "How much is the income " << endl;
        amount = AuxiliaryMethod::getTypedLine();
        cout << amount << endl;
        AuxiliaryMethod::commaToDot(amount);
        cout << amount << endl;
        double am = AuxiliaryMethod::convertStringToDouble(amount);
        inc.setAmount(am);
        cout << inc.getAmount() << endl;
        system("pause");
        cout << "New income added to file" << endl;
        system("pause");
    }
    else if (choice == '2')
    {
        cout << "Type date (yyyy-mm-dd): ";
        date = AuxiliaryMethod::getTypedLine();
        date = AuxiliaryMethod::removeDashFromDate(date);
        cout << date << endl;
        system("pause");
        if (AuxiliaryMethod::checkDate(date))
        {
            inc.setIncomeDate(AuxiliaryMethod::convertStringToInt(date));
            cout << inc.getIncomeDate() << endl;
            system("pause");
            cout << "What the income is about? " << endl;
            item = AuxiliaryMethod::getTypedLine();
            inc.setItem(item);
            cout << inc.getItem() << endl;
            system("pause");
            cout << "How much is the income " << endl;
            amount = AuxiliaryMethod::getTypedLine();
            AuxiliaryMethod::commaToDot(amount);
            inc.setAmount(AuxiliaryMethod::convertStringToDouble(amount));
            cout << inc.getAmount() << endl;
            system("pause");
            cout << "New income added to file" << endl;
            system("pause");
        }
        else
        {
            cout << "Check the date again" <<endl;
            system("pause");
        }

    }

    incomes.push_back(inc);
    incomeFile.addIncomeToFile(inc);
    /*if ())
        cout << "New income added to file" << endl;
    else
        cout << "Error. Problem with saving the file." << endl;*/

}
/*

void BudgetManager::loadUserIncomes();
void BudgetManager::showIncomes();
void BudgetManager::addExpense();
void BudgetManager::loadUserExpenses();
void BudgetManager::showExpenses ();

*/
