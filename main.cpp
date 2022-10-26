#include <iostream>
#include "MyFinance.h"

using namespace std;

int main()
{
    MyFinance myFinance("Users.xml", "Incomes.xml", "Expenses.xml");

     char choice;
    while (true)
    {
        if (!myFinance.isUserLoggedIn())
        {
            choice = myFinance.chooseFromMainMenu();

            switch (choice)
            {
            case '1':
                myFinance.signUpUser();
                break;
            case '2':
                myFinance.signInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Try again, no position in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = myFinance.chooseFromUserMenu();

            switch (choice)
            {
            case '1':
                myFinance.writeAllUsers();
                break;
            case '2':
                //myFinance.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //myFinance.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //myFinance.wypiszWszystkichAdresatowZalogowanegoUzytkownika();
                break;
            case '5':
                //myFinance.usunAdresata();
                break;
            case '6':
                myFinance.changePassword();
                break;
            case '9':
                myFinance.signOutUser();
                break;
            }
        }
    }

    return 0;
}
