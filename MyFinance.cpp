#include "MyFinance.h"

void MyFinance::signUpUser()
{
    userManager.signUpUser();
}

void MyFinance::signInUser()
{
    userManager.signInUser();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(userManager.getLoggedUserId(), INCOME_FILE_NAME, EXPENSE_FILE_NAME);
    }
}

void MyFinance::signOutUser()
{
    userManager.signOutUser();
}

void MyFinance::writeAllUsers()
{
    userManager.writeAllUsers();
}

void MyFinance::changePassword()
{
    userManager.changePassword();
}

void MyFinance::addIncome()
{
    if (isUserLoggedIn())
    {
    budgetManager->addIncome();
    }
    else
    {
        cout << "To add income, sign in first." << endl;
        system("pause");
    }
}
void MyFinance::addExpense()
{
    if (isUserLoggedIn())
    {
    budgetManager->addExpense();
    }
    else
    {
        cout << "To add expense, sign in first." << endl;
        system("pause");
    }
}

void MyFinance::showCurrentMonthBalance()
{
    if (isUserLoggedIn())
    {
    budgetManager->showCurrentMonthBalance();
    }
    else
    {
        cout << "To show balance, sign in first." << endl;
        system("pause");
    }
}

void MyFinance::showPreviousMonthBalance()
{
    if (isUserLoggedIn())
    {
    budgetManager->showPreviousMonthBalance();
    }
    else
    {
        cout << "To show balance, sign in first." << endl;
        system("pause");
    }
}

void MyFinance::showChosenPeroidBalance()
{
    if (isUserLoggedIn())
    {
    budgetManager->showChosenPeroidBalance();
    }
    else
    {
        cout << "To show balance, sign in first." << endl;
        system("pause");
    }
}

char MyFinance::chooseFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log In" << endl;
    cout << "9. End programm " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethod::getChar();

    return choice;
}

char MyFinance::chooseFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Summary of the current month" << endl;
    cout << "4. Summary of the previous month" << endl;
    cout << "5. Summary of the chosen peroid" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethod::getChar();

    return choice;
}

bool MyFinance::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}
