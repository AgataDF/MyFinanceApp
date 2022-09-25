#include "Expense.h"

void Expense::setExpenseId (int newId)
{
    if (newId >=0)
        expenseId = newId;
}
void Expense::setUserId (int newId)
{
    if (newId >=0)
        userId = newId;
}
void Expense::setExpenseDate (int newDate)
{
    if (newDate >=0)
        expenseDate = newDate;
}
void Expense::setItem (string newItem)
{
    item = newItem;
}
void Expense::setAmount (double newAmount)
{
    amount = newAmount;
}

int Expense::getExpenseId()
{
    return expenseId;
}
int Expense::getUserId()
{
    return userId;
}
int Expense::getExpenseDate()
{
    return expenseDate;
}
string Expense::getItem()
{
    return item;
}
double Expense::getAmount()
{
    return amount;
}
