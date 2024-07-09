#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrenciesScreen.h"
#include "clsUpdateCurreciesScreen.h"
#include "clsCalculatorCurreciesScreen.h"
using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
    private:
        enum _enCurrencyMenue { ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, CurrencyCalculator = 4, CMianMenue = 5 };

        static _enCurrencyMenue _ReadCurrencyExhangeOption()
        {
            short choice;
            do
            {
                cout << "\t\t\t\t      Choose what do you want to do? [1 to 5]? ";
                cin >> choice;

            } while (choice<1 || choice>5);
            return (_enCurrencyMenue)choice;
            
        }

        static void _GoBackToCurrencyExchangeMenue()
        {
            system("read -n 1 -s -p \"Press any key to go back to CurrencyExhange Menue...\"");
            ShowCurrencyExchangeMenue(); 
        }

        static void _ShowListCurrenciesScreen()
        {
            clsListCurrenciesScreen::ShowListCurrenciesScreen();
        }

        static void _ShowFindCurrencyScreen()
        {
            clsFindCurrenciesScreen::ShowFindCurrencyScreen();
        }

        static void _ShowUpdateRateScreen()
        {
            clsUpdateCurreciesScreen::ShowUpdateRateScreen();
        }

        static void _ShowCurrencyCalculatorScreen()
        {
            clsCalculatorCurreciesScreen::ShowCurrencyCalculatorScreen();
        }

        static void _PerformTransactionOption(_enCurrencyMenue choice)
        {
            switch(choice)
            {
                case ListCurrencies :
                {
                    system("clear");
                    _ShowListCurrenciesScreen();
                    _GoBackToCurrencyExchangeMenue();
                    break;
                }

                case FindCurrency :
                {
                    system("clear");
                    _ShowFindCurrencyScreen();
                    _GoBackToCurrencyExchangeMenue();
                    break;
                }

                case UpdateRate :
                {
                    system("clear");
                    _ShowUpdateRateScreen();
                    _GoBackToCurrencyExchangeMenue();
                    break;
                }

                case CurrencyCalculator :
                {
                    system("clear");
                    _ShowCurrencyCalculatorScreen();
                    _GoBackToCurrencyExchangeMenue();
                    break;
                }

                case CMianMenue :
                {
                    system("clear");
                    break;
                }


            }
        }

    public:
        static void ShowCurrencyExchangeMenue()
        {
            if(!CheckAccessRights(clsUser::enPermissions::pCurrancyExchange))
            {
                return;
            }

            system("clear");
            _DrawScreenHeader("\t Currancy Exchange Main Screen");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t   Currency Exchange Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] MainMenue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _PerformTransactionOption((_enCurrencyMenue)_ReadCurrencyExhangeOption());

        }
};