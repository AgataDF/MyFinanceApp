#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Income income) {
    bool fileExists = xml.Load( getFileName() );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", AuxiliaryMethod::convertIntToString(income.getIncomeId()));
    xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(income.getUserId()));
    xml.AddElem("Date", income.getIncomeDate);
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

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
        xml.AddElem("Date", incomes[i].getIncomeDate());
        xml.AddElem("Item", incomes[i].getItem());
        xml.AddElem("Amount", incomes[i].getAmount());
        xml.OutOfElem();
        xml.OutOfElem();
    }
    xml.Save(getFileName());
}

vector <Income> IncomeFile::loadIncomeFromFile() {
    Income income;
    vector <Income> incomes;
    int incomeId, userId;
    string date, amount, item;

    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.FindElem(); // root ORDER element
        xml.IntoElem(); // inside ORDER
        while ( xml.FindElem("Income") ) {
            xml.IntoElem();
            xml.FindElem( "IncomeId" );
            incomeId = AuxiliaryMethod::convertStringToInt(xml.GetData());
            xml.FindElem( "UserId" );
            incomeId = AuxiliaryMethod::convertStringToInt(xml.GetData());
            xml.FindElem( "Date" );
            date = xml.GetData();
            xml.FindElem( "Item" );
            item = xml.GetData();
            xml.FindElem( "Amount" );
            amount = xml.GetData();
            xml.OutOfElem();

            income.setIncomeId(incomeId);
            income.setUserId(userId);
            income.setDate(date);
            income.setItem(Item);
            income.setAmount(amount);
            incomes.push_back(income);
        }
    }
    return incomes;
}

