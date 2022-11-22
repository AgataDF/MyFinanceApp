#include "AuxiliaryMethod.h"

string AuxiliaryMethod::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethod::getTypedLine()
{
    string line = "";
    getline(cin, line);
    return line;
}

char AuxiliaryMethod::getChar()
{
    string line = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, line);

        if (line.length() == 1)
        {
            sign = line[0];
            break;
        }
        cout << "You need to type single char." << endl;
    }
    return sign;
}

int AuxiliaryMethod::convertStringToInt(string figure)
{
    int figureInt;
    istringstream iss(figure);
    iss >> figureInt;

    return figureInt;
}

string AuxiliaryMethod::convertDoubleToString(double number)
{
   return to_string(number);
}

double AuxiliaryMethod::convertStringToDouble(string number)
{
    double num = stod(number);
   return num;
}

string AuxiliaryMethod::replaceFirstLetterUppercaseTheRestLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

void AuxiliaryMethod::commaToDot(string number)
{
    //number.replace(number.begin(), number.end(), '.', ',');
    for (int i=0; i<number.length(); i++)
    {
        if (number[i] == ',')
        {
            number[i] = '.';
            break;
        }
    }
}

string AuxiliaryMethod::removeDashFromDate (string date)
{
    date.erase(remove(date.begin(), date.end(), '-'), date.end());
    return date;
}

bool AuxiliaryMethod:: checkDate (string date)
{
    if (date.size() == 8)
    {
        if ((checkYear(date)== true)&&(checkMonth(date)== true)&&(checkDay(date)== true))
        {
            return true;
        }
    }
    else
    {
        return false;
    }

}

bool AuxiliaryMethod:: checkYear (string date)
{
    string yearDate = date.substr(0, 4);
    time_t now = time(0);
    struct tm tstruct;
    char year_char[5];
    tstruct = *localtime(&now);
    strftime(year_char, 5, "%Y", &tstruct);
    string yearNow = year_char;

    if ((convertStringToInt(yearDate) >= 2000)&&(convertStringToInt(yearDate) <= (convertStringToInt(yearNow))))
        return true;
    else
        return false;
}
bool AuxiliaryMethod:: checkMonth (string date)
{
    string yearDate = date.substr(0, 4);
    string monthDate = date.substr(4, 2);
    time_t now = time(0);
    struct tm tstruct;
    char year_char[5];
    char month_char[5];
    tstruct = *localtime(&now);
    strftime(year_char, 5, "%Y", &tstruct);
    strftime(month_char, 5, "%m", &tstruct);
    string monthNow = month_char;
    string yearNow = year_char;

    if (yearDate != yearNow)
    {
        if ((convertStringToInt(monthDate) >= 1)&&(convertStringToInt(monthDate) <= 12))
            return true;
        else
            return false;
    }
    else
    {
        if ((convertStringToInt(monthDate) >= 1)&&(convertStringToInt(monthDate) <= (convertStringToInt(monthNow))))
        return true;
    else
        return false;
    }
}
bool AuxiliaryMethod:: checkDay (string date)
{
    string yearDate = date.substr(0, 4);
    string monthDate = date.substr(4, 2);
    string dayDate = date.substr(6, 2);
    time_t now = time(0);
    struct tm tstruct;
    char year_char[5];
    char month_char[5];
    char day_char[5];
    tstruct = *localtime(&now);
    strftime(year_char, 5, "%Y", &tstruct);
    strftime(month_char, 5, "%m", &tstruct);
    strftime(day_char, 5, "%d", &tstruct);
    string dayNow = day_char;
    string monthNow = month_char;
    string yearNow = year_char;

    if (yearDate != yearNow)
    {
        if(convertStringToInt(monthDate)==1 || convertStringToInt(monthDate)==3 || convertStringToInt(monthDate)==5 || convertStringToInt(monthDate)==7 || convertStringToInt(monthDate)==8 || convertStringToInt(monthDate)==10 || convertStringToInt(monthDate)==12)
        {
            if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
            else
                return false;
        }
        else if (convertStringToInt(monthDate)==4 || convertStringToInt(monthDate)==6 || convertStringToInt(monthDate)==9 || convertStringToInt(monthDate)==11)
        {
            if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=30)
                return true;
            else
                return false;
        }
        else if (convertStringToInt(monthDate)==2)
        {
            if((convertStringToInt(yearDate)%4==0 && convertStringToInt(yearDate)%100!=0) || convertStringToInt(yearDate)%400==0)
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=29)
                return true;
                else
                return false;
            }
            else
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=28)
                return true;
                else
                return false;
            }
        }
    }
    else
    {
        switch (convertStringToInt(monthDate))
        {
        case 1:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        case 2:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if((convertStringToInt(yearDate)%4==0 && convertStringToInt(yearDate)%100!=0) || convertStringToInt(yearDate)%400==0)
                {
                    if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=29)
                    return true;
                    else
                    return false;
                }
                else
                {
                    if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=28)
                    return true;
                    else
                    return false;
                }
            }
            else
                return false;
        case 3:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        case 4:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=30)
                return true;
                else
                return false;
            }
            else
                return false;
        case 5:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        case 6:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=30)
                return true;
                else
                return false;
            }
            else
                return false;
        case 7:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        case 8:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        case 9:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=30)
                return true;
                else
                return false;
            }
            else
                return false;
        case 10:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        case 11:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=30)
                return true;
                else
                return false;
            }
            else
                return false;
        case 12:
            if ((convertStringToInt(monthDate)) <= (convertStringToInt(monthNow)))
            {
                if(convertStringToInt(dayDate)>=1 && convertStringToInt(dayDate)<=31)
                return true;
                else
                return false;
            }
            else
                return false;
        }
    }
}





/*

+ replaceFirstLetterUppercaseTheRestLowercase(): string

+ formatCashAmout (string cashAmount) : double
*/



/*
string AuxiliaryMethod::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}



int AuxiliaryMethod::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}*/
