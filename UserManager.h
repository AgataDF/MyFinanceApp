#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "UserFile.h"
#include "User.h"

using namespace std;

class UserManager
{
    UserFile userFile;
    vector <User> users;
    int loggedUserId;

    User typeNewUserData();
    int getNewUserId();
    bool ifLoginExists(string login);

public:
    UserManager (string userFileName):userFile(userFileName){
    loggedUserId = 0;
    users = userFile.loadUsersFromFile();
    };

    void signUpUser();
    void signInUser();
    void signOutUser();
    void writeAllUsers();
    void changePassword();
    bool isUserLoggedIn();

};


#endif
