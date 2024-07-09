#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"
using namespace std;

class clsFindCurrenciesScreen : protected clsScreen
{
    private:
        enum enFindChoice { Code = 1, Country = 2 };

        static void _Print(clsCurrency Currency)
        {
            cout << "\nCurrency Found :-) \n\n";
            cout << "Currency Card:\n";
            cout << "________________________________\n\n";
            cout << "Country       : " << Currency.getCountry() << endl;
            cout << "Code          : " << Currency.getCode() << endl;
            cout << "Name          : " << Currency.getName() << endl;
            cout << "Rate(1$)      : " << Currency.getRate() << endl;
            cout << "________________________________\n\n";
        }

    public:
        static void ShowFindCurrencyScreen()
        {
            _DrawScreenHeader("Find Currency Screen");
            short choice;
            cout << "Find By: [1] Code or [2] Country ? ";
            cin >> choice;
            switch((enFindChoice)choice)
            {
                case Code : 
                {
                    string Code;
                    do
                    {
                        Code = clsInputValidate::ReadString("Please Enter CurrencyCode: ");
                        Code = clsString::convertLettersToUpperCase(Code);

                    }while(!clsCurrency::IsCurrencyCodeExist(Code));

                    clsCurrency Currency = clsCurrency::FindCode(Code);
                    _Print(Currency);

                    break;
                }

                case Country :
                {
                    string Country;
                    do
                    {
                        Country = clsInputValidate::ReadString("Please Enter CurrencyCountry: ");
                        Country = clsString::convertLettersToLowerCase(Country);
                        Country = clsString::convertFirstLetterToUpper(Country);

                    }while(!clsCurrency::IsCurrencyCountryExist(Country));

                    clsCurrency Currency = clsCurrency::FindCountry(Country);
                    _Print(Currency);

                    break;
                }
            }
        }

};