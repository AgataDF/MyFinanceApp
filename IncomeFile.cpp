#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Income inc) {
    bool fileExists = xml.Load( getFileName() );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", AuxiliaryMethod::convertIntToString(inc.getIncomeId()));
    xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(inc.getUserId()));
    xml.AddElem("Date", AuxiliaryMethod::convertIntToString(inc.getIncomeDate()));
    xml.AddElem("Item", inc.getItem());
    xml.AddElem("Amount", AuxiliaryMethod::convertDoubleToString(inc.getAmount()));

    xml.Save(getFileName());
}

void IncomeFile::saveAllIncomesToFile(vector <Income> &incomes) {
    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.ResetMainPos();
        while ( xml.FindElem() )
            xml.RemoveElem();

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    for (int i = 0; i < incomes.size(); i++) {
        xml.IntoElem();
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("IncomeId", AuxiliaryMethod::convertIntToString(incomes[i].getIncomeId()));
        xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(incomes[i].getUserId()));
        xml.AddElem("Date", AuxiliaryMethod::convertIntToString(incomes[i].getIncomeDate()));
        xml.AddElem("Item", incomes[i].getItem());
        xml.AddElem("Amount", AuxiliaryMethod::convertDoubleToString(incomes[i].getAmount()));
        xml.OutOfElem();
        xml.OutOfElem();
    }
    xml.Save(getFileName());
}

vector <Income> IncomeFile::loadIncomeFromFile(int currentUserId) {
    Income income;
    vector <Income> incomes;
    int incomeId, userId, date;
    double amount;
    string item;

    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.FindElem(); // root ORDER element
        xml.IntoElem(); // inside ORDER
        while ( xml.FindElem("Income") ) {
            xml.IntoElem();
            xml.FindElem( "UserId" );
            userId = AuxiliaryMethod::convertStringToInt(xml.GetData());
            if  (currentUserId == userId) {
                xml.ResetChildPos();
                xml.FindElem( "IncomeId" );
                incomeId = AuxiliaryMethod::convertStringToInt(xml.GetData());
                xml.FindElem( "Date" );
                date = AuxiliaryMethod::convertStringToInt(xml.GetData());
                xml.FindElem( "Item" );
                item = xml.GetData();
                xml.FindElem( "Amount" );
                amount = AuxiliaryMethod::convertStringToDouble(xml.GetData());
                xml.OutOfElem();

                income.setIncomeId(incomeId);
                income.setUserId(userId);
                income.setIncomeDate(date);
                income.setItem(item);
                income.setAmount(amount);
                incomes.push_back(income);
            }
        }
    }
    return incomes;
}

int IncomeFile::setlastIncomeIdFromFile() {
    int incomeId = 0;
    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.ResetPos(); // top of document
        xml.FindElem(); // ORDER element is root
        xml.IntoElem(); // inside ORDER
        while ( xml.FindElem("Income") ) {
            xml.FindChildElem( "IncomeId" );
            incomeId = AuxiliaryMethod::convertStringToInt(xml.GetChildData());
        }
    };
    return incomeId;
}

int IncomeFile::getlastIncomeId()
{
    return lastIncomeId;
}
