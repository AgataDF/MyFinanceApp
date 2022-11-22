#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(Expense expense) {
    bool fileExists = xml.Load( getFileName() );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", AuxiliaryMethod::convertIntToString(expense.getExpenseId()));
    xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(expense.getUserId()));
    xml.AddElem("Date", AuxiliaryMethod::convertIntToString(expense.getExpenseDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethod::convertDoubleToString(expense.getAmount()));

    xml.Save(getFileName());
}

void ExpenseFile::saveAllExpensesToFile(vector <Expense> &expenses) {
    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.ResetMainPos();
        while ( xml.FindElem() )
            xml.RemoveElem();

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    for (int i = 0; i < expenses.size(); i++) {
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("ExpenseId", AuxiliaryMethod::convertIntToString(expenses[i].getExpenseId()));
        xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(expenses[i].getUserId()));
        xml.AddElem("Date", AuxiliaryMethod::convertIntToString(expenses[i].getExpenseDate()));
        xml.AddElem("Item", expenses[i].getItem());
        xml.AddElem("Amount", AuxiliaryMethod::convertDoubleToString(expenses[i].getAmount()));
        xml.OutOfElem();
        xml.OutOfElem();
    }
    xml.Save(getFileName());
}

vector <Expense> ExpenseFile::loadExpenseFromFile(int currentUserId) {

    Expense exp;
    vector <Expense> expenses;
    int expenseId, userId, date;
    double amount;
    string item;

    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") ) {
            xml.IntoElem();
            xml.FindElem( "UserId" );
            userId = AuxiliaryMethod::convertStringToInt(xml.GetData());
            if  (currentUserId == userId) {
                xml.ResetChildPos();
                xml.FindElem( "ExpenseId" );
                expenseId = AuxiliaryMethod::convertStringToInt(xml.GetData());
                xml.FindElem( "Date" );
                date = AuxiliaryMethod::convertStringToInt(xml.GetData());
                xml.FindElem( "Item" );
                item = xml.GetData();
                xml.FindElem( "Amount" );
                amount = AuxiliaryMethod::convertStringToDouble(xml.GetData());
                xml.OutOfElem();

                exp.setExpenseId(expenseId);
                exp.setUserId(userId);
                exp.setExpenseDate(date);
                exp.setItem(item);
                exp.setAmount(amount);
                expenses.push_back(exp);
            }
        }
    }
    return expenses;
}

int ExpenseFile::setlastExpenseIdFromFile() {
    int expenseId;
    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.ResetPos(); // top of document
        xml.FindElem(); // ORDER element is root
        xml.IntoElem(); // inside ORDER
        while ( xml.FindElem("Expense") ) {
            xml.FindChildElem( "ExpenseId" );
            expenseId = AuxiliaryMethod::convertStringToInt(xml.GetChildData());
        }
    }
    else return 0;
    return expenseId;
}

int ExpenseFile::getlastExpenseId()
{
    return lastExpenseId;
}



