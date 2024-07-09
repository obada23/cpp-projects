#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
    private:
        static void _PrintCurrenciesList(clsCurrency Currency)
        {
            cout << setw(8) << left << "" << "\t| " << setw(30) << left << Currency.getCountry();
            cout << "\t| " << setw(8) << left << Currency.getCode();
            cout << "\t| " << setw(39) << left << Currency.getName();
            cout << "      \t\t| " << setw(10) << left << Currency.getRate();
            cout << endl;
        }

    public:
        static void ShowListCurrenciesScreen()
        {
            string Title = "\t Currencies List Screen";
            vector<clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();
            string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";
            _DrawScreenHeader(Title,SubTitle);

            cout << "  \t\t____________________________________________________________________________________________________________________________\n\n";
            cout << "  \t\t|" << setw(20) << left << "  Country";
            cout << "  \t\t\t|" << setw(10) << left << "  Code";
            cout << "  \t|" << setw(20) << left << "  Name";
            cout << "     \t\t\t\t|" << setw(0) << left << "  Rate/(1$)\n";
            cout << "  \t\t____________________________________________________________________________________________________________________________\n\n";

            if(vCurrencys.size()==0)
            {
                cout << "\t\t\t\tNo Currencies Available In the System!" << endl << endl;
            }

            else
            {
                for(clsCurrency &Currency : vCurrencys)
                {
                    _PrintCurrenciesList(Currency);
                }
            }

            cout << "  \t\t____________________________________________________________________________________________________________________________\n\n";
        }

};