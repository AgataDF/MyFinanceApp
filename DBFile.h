#ifndef DBFILE_H
#define DBFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class DBFile
{
    const string FILE_NAME;

public:
    DBFile (string fileName):  FILE_NAME(fileName) {};
    string getFileName();
    bool isFileEmpty();
};
#endif
