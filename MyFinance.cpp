#include "MyFinance.h"

void MyFinance::signUpUser()
{
    userManager.signUpUser();
}

void MyFinance::signInUser()
{
    userManager.signInUser();
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
    cout << "1. Add income/ Show all users" << endl;
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
