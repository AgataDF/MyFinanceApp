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
public:
    IncomeFile(string fileName) : DBFile(fileName){};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomeFromFile();
    void saveAllIncomesToFile(vector <Income> &incomes);
};
#endif
