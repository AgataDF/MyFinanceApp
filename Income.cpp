#include "Income.h"

void Income::setIncomeId (int newId)
{
    if (newId >=0)
        incomeId = newId;
}
void Income::setUserId (int newId)
{
    if (newId >=0)
        userId = newId;
}
void Income::setIncomeDate (int newDate)
{
    if (newDate >=0)
        incomeDate = newDate;
}
void Income::setItem (string newItem)
{
    item = newItem;
}
void Income::setAmount (double newAmount)
{
    amount = newAmount;
}

int Income::getIncomeId()
{
    return incomeId;
}
int Income::getUserId()
{
    return userId;
}
int Income::getIncomeDate()
{
    return incomeDate;
}
string Income::getItem()
{
    return item;
}
double Income::getAmount()
{
    return amount;
}
