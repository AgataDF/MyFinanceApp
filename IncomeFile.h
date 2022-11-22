#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "DBFile.h"
#include "AuxiliaryMethod.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomeFile : public DBFile
{
    CMarkup xml;
    int lastIncomeId;
    int setlastIncomeIdFromFile();

public:
    IncomeFile(string fileName) : DBFile(fileName){
    lastIncomeId = setlastIncomeIdFromFile();
    };
    void addIncomeToFile(Income inc);
    vector <Income> loadIncomeFromFile(int currentUserId);
    void saveAllIncomesToFile(vector <Income> &incomes);
    int getlastIncomeId();
};
#endif
