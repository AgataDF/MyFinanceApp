#ifndef AUXILIARYMETHOD_H
#define AUXILIARYMETHOD_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

class AuxiliaryMethod
{
    static bool checkYear (string date);
    static bool checkMonth (string date);
    static bool checkDay (string date);
public:
     static string convertIntToString(int number);
     static string getTypedLine();
     static string removeDashFromDate (string date);
     static char getChar();
     static int convertStringToInt(string figure);
     static string convertDoubleToString(double number);
     static double convertStringToDouble(string number);
     static string replaceFirstLetterUppercaseTheRestLowercase(string text);
     static void commaToDot(string number);
     static bool checkDate (string date);


    /* static string pobierzLiczbe(string tekst, int pozycjaZnaku);


+ formatCashAmout (string cashAmount) : double
     static int wczytajLiczbeCalkowita();*/
};
#endif
