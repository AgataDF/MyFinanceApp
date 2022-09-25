#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include "DBFile.h"

using namespace std;

class UserFile :: public DBFile
{


public:
    UserFile(string fileName) : DBFile(fileName){};
};
#endif
