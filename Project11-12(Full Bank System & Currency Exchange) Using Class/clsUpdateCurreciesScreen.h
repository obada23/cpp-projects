#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
using namespace std;

class clsUpdateCurreciesScreen : protected clsScreen
{
    private:
        static void _Print(clsCurrency Currency)
        {
            cout << "Currency Card:\n";
            cout << "________________________________\n\n";
            cout << "Country       : " << Currency.getCountry() << endl;
            cout << "Code          : " << Currency.getCode() << endl;
            cout << "Name          : " << Currency.getName() << endl;
            cout << "Rate(1$)      : " << Currency.getRate() << endl;
            cout << "________________________________\n\n";
        }

        static void _UpdateCurrecnyRate(clsCurrency Currency)
        {
            cout << "Update Currency Rate:\n";
            cout << "_______________________\n\n";
            Currency.setRate(clsInputValidate::ReadFloatNumber("Enter New Rate: "));
            Currency.Update();
            cout << "Currency Rate Updated Successfuly :-) \n\n";
            _Print(Currency);
            
        }

    public:
        static void ShowUpdateRateScreen()
        {
            _DrawScreenHeader("Update Currency Screen");

            string Code;
            do
            {
                Code = clsInputValidate::ReadString("Please Enter Currency Code: ");
                Code = clsString::convertLettersToUpperCase(Code);

            } while (!clsCurrency::IsCurrencyCodeExist(Code));

            clsCurrency Currency = clsCurrency::FindCode(Code);
            _Print(Currency);

            cout << "Are you Sure you want to update the rate of this Currency? y/n? ";
            char Answer;
            cin >> Answer;
            if(toupper(Answer) == 'Y')
            {
                _UpdateCurrecnyRate(Currency);
            }
            

            
            
        }
};