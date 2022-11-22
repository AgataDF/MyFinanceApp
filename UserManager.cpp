#include "UserManager.h"

void UserManager::signUpUser()
{
    User user = typeNewUserData();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "New account created successfully" << endl << endl;
    system("pause");
}

User UserManager::typeNewUserData()
{
    User u;

    u.setId(getNewUserId());

    string name;
    cout << "Type name: ";
    cin >> name;
    u.setName(AuxiliaryMethod::replaceFirstLetterUppercaseTheRestLowercase(name));

    string surname;
    cout << "Type surname: ";
    cin >> surname;
    u.setSurname(AuxiliaryMethod::replaceFirstLetterUppercaseTheRestLowercase(surname));

    string login;
    do
    {
        cout << "Type login: ";
        cin >> login;
        u.setLogin(login);
    }
    while (ifLoginExists(u.getLogin()) == true);

    string password;
    cout << "Type password: ";
    cin >> password;
    u.setPassword(password);

    return u;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::ifLoginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Login taken." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::writeAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
    system("pause");
}

void UserManager::signInUser()
{
    string login = "", password = "";

    cout << endl << "Type login: ";
    login = AuxiliaryMethod::getTypedLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Type password. Chances " << numberOfAttempts << " left: ";
                password = AuxiliaryMethod::getTypedLine();

                if (itr -> getPassword() == password)
                {
                    loggedUserId = itr -> getId();
                    cout << endl << "You signed in successfully." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Password incorrect No chances left." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return;
}

void UserManager::signOutUser()
{
    loggedUserId = 0;
    cout << "You signed out successfully" << endl << endl;
    system("pause");
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Type new password: ";
    newPassword = AuxiliaryMethod::getTypedLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Password has been changed successfully." << endl << endl;
            system("pause");
        }
    }
    userFile.saveAllUsersToFile(users);
}

bool UserManager::isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}
