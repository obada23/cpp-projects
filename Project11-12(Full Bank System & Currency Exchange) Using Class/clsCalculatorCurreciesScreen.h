#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCalculatorCurreciesScreen : protected clsScreen
{
    private:

        static void _Print(clsCurrency Currency)
        {
            cout << "\nConvert Form:\n";
            cout << "________________________________\n\n";
            cout << "Country       : " << Currency.getCountry() << endl;
            cout << "Code          : " << Currency.getCode() << endl;
            cout << "Name          : " << Currency.getName() << endl;
            cout << "Rate(1$)      : " << Currency.getRate() << endl;
            cout << "________________________________\n\n";
        }
        static clsCurrency _getCurrencyInformation(short iteration)
        {
            string Code;
            do
            {
                cout << "Please Enter Currency" << iteration << " Code: ";
                Code = clsInputValidate::ReadString("");
                Code = clsString::convertLettersToUpperCase(Code);
                cout << endl;

            }while(!clsCurrency::IsCurrencyCodeExist(Code));

            clsCurrency Currency = clsCurrency::FindCode(Code);
            return Currency;
        }

    public:
        static void ShowCurrencyCalculatorScreen()
        {
            _DrawScreenHeader("Update Currency Screen");
            clsCurrency Currency1 = _getCurrencyInformation(1);
            clsCurrency Currency2 = _getCurrencyInformation(2);

            float Amount;
            cout << "Enter Amount To Exchange: ";
            cin >> Amount;
            if(Currency1.getCode() != "USD" && Currency2.getCode() == "USD")
                cout << endl << Amount << " " << Currency1.getCode() << " = " << Amount/(Currency1.getRate()) << " " << Currency2.getCode() << endl << endl;

            else if(Currency1.getCode() != "USD" && Currency2.getCode() != "USD")
                cout << endl << Amount << " " << Currency1.getCode() << " = " << (Amount/(Currency1.getRate()))*Currency2.getRate() << " " << Currency2.getCode() << endl << endl;

            cout << endl;
            

            
        }

};
