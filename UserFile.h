#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "DBFile.h"
#include "AuxiliaryMethod.h"
#include "User.h"
#include "Markup.h"

using namespace std;

class UserFile : public DBFile
{
    CMarkup xml;

public:
    UserFile(string fileName) : DBFile(fileName){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);

};
#endif
