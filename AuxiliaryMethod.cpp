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

string AuxiliaryMethod::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
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
