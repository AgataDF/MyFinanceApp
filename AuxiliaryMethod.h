#ifndef AUXILIARYMETHOD_H
#define AUXILIARYMETHOD_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethod
{
public:
     static string convertIntToString(int number);
     static string getTypedLine();
     static char getChar();
     static int convertStringToInt(string figure);
    /* static string pobierzLiczbe(string tekst, int pozycjaZnaku);
     static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
     static int wczytajLiczbeCalkowita();*/
};
#endif
