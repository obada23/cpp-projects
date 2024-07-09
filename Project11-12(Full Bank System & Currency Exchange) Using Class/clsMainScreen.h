#pragma once
#include <iostream>
//#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
    private:
        enum _enMainMenueOptions { eShowClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransaction = 6, eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9,  eLogout = 10  };
        static short _ReadMainMenueOption()
        {
            short number;
            do
            {
                cout << "\t\t\t\t      Choose what do you want to do? [1 to 10]? ";
                cin >> number;

            } while (number<1 || number>10);

            return number;
            
        }

        static void _ShowAllClientsScreen()
        {
            clsClientListScreen::ShowClientsList();
        }

        static void _ShowAddNewClientsScreen()
        {
            clsAddNewClientScreen::ShowAddNewClientScreen();
        }

        static void _ShowDeleteClientsScreen()
        {
            clsDeleteClientScreen::ShowDeleteClientScreen();
        }

        static void _ShowUpdateClientsScreen()
        {
            clsUpdateClientScreen::ShowUpdateClientsScreen();
        }

        static void _ShowTransactionScreen()
        {
            clsTransactionScreen::ShowTransactionsMenue();
        }

        static void _ShowManageUsersScreen()
        {
            clsManageUsersScreen::ShowManageUsersMenue();
        }

        static void _ShowFindClientsScreen()
        {
            clsFindClientScreen::ShowFindClientScreen();
        }

        static void _ShowLoginRegisterScreen()
        {
            clsLoginRegisterScreen::ShowLoginRegisterScreen();
        }

        static void _ShowCurrencyExchangeScreen()
        {
            clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
        }

        static void _Logout()
        {
            CurrentUser = clsUser::Find("","");
        }

        

        static  void _GoBackToMainMenue()
        {
            system("read -n 1 -s -p \"\t\t\t\t      Press any key to go back to Main Menue...\"");
            ShowMainMenue(); 
        }

        static void _PerfromMainMenueOption(_enMainMenueOptions yourChoice)
        {
            switch(yourChoice)
            {
                case eShowClient :
                {
                    system("clear");
                    
                    _ShowAllClientsScreen();
                    _GoBackToMainMenue();
                    break;

                } 

                case eAddNewClient :
                {
                    system("clear");
                    _ShowAddNewClientsScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eDeleteClient :
                {
                    system("clear");
                    _ShowDeleteClientsScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eUpdateClient :
                {
                    system("clear");
                    _ShowUpdateClientsScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eFindClient :
                {
                    system("clear");
                    _ShowFindClientsScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eTransaction :
                {
                    system("clear");
                    _ShowTransactionScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eManageUsers :
                {
                    system("clear");
                    _ShowManageUsersScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eLoginRegister :
                {
                    system("clear");
                    _ShowLoginRegisterScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eCurrencyExchange :
                {
                    system("clear");
                    _ShowCurrencyExchangeScreen();
                    _GoBackToMainMenue();
                    break;
                }

                case eLogout :
                {
                    system("clear");
                    _Logout();
                    break;
                }
            }
        }

    public:
        static void ShowMainMenue()
        {
           
            system("clear");
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange .\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((_enMainMenueOptions)_ReadMainMenueOption());
        }


};