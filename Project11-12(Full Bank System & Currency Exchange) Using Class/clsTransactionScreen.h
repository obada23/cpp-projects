#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionScreen : protected clsScreen
{
    private:
        enum _enTransactionMenue { Deposit = 1, Withdraw = 2, TotalBalances = 3, Transfer = 4, TransferLog = 5, TMainMenue = 6 };

        static short _ReadTransactionOption()
        {
            short choice;
            do
            {
                cout << "\t\t\t\t      Choose what do you want to do? [1 to 6]? ";
                cin >> choice;

            } while (choice<1&&choice>6);
            return (_enTransactionMenue)choice;
            
        }

        static void _GoBackToTransactionMenue()
        {
           system("read -n 1 -s -p \"Press any key to go back to Transaction Menue...\"");
           ShowTransactionsMenue(); 
        }

        static void _ShowDepositScreen()
        {
            clsDepositScreen::ShowDepositScreen();
        }

        static void _ShowWithdrawScreen()
        {
            clsWithdrawScreen::ShowWithdrawScreen();
        }

        static void _ShowTotalBalanceScreen()
        {
            clsTotalBalanceScreen::ShowTotalBalanceScreen();
        }

        static void _ShowTransferScreen()
        {
            clsTransferScreen::ShowTransferScreen();
        }

        static void _ShowTransferLogScreen()
        {
            clsTransferLogScreen::ShowTransferLogScreen();
        }

        static void _PerformTransactionOption(_enTransactionMenue yourChoice)
        {
            switch(yourChoice)
            {
                case Deposit :
                {   
                    system("clear");
                    _ShowDepositScreen();
                    _GoBackToTransactionMenue();
                    break;
                }

                case Withdraw :
                {
                    system("clear");
                    _ShowWithdrawScreen();
                    _GoBackToTransactionMenue();
                    break;
                }

                case TotalBalances :
                {
                    system("clear");
                    _ShowTotalBalanceScreen();
                    _GoBackToTransactionMenue();
                    break;
                }

                case Transfer :
                {
                    system("clear");
                    _ShowTransferScreen();
                    _GoBackToTransactionMenue();
                    break;
                }

                case TransferLog :
                {
                    system("clear");
                    _ShowTransferLogScreen();
                    _GoBackToTransactionMenue();
                    break;
                }

                case TMainMenue :
                {
                    system("clear");
                    break;
                }
            }
        }

    public:
        static void ShowTransactionsMenue()
        {
            if(!CheckAccessRights(clsUser::enPermissions::pTransactions))
            {
                return;
            }

            system("clear");
            _DrawScreenHeader("\t Transactions Screen");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] TotalBalance.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer.\n";
            cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
            cout << setw(37) << left << "" << "\t[6] MainMenue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _PerformTransactionOption((_enTransactionMenue)_ReadTransactionOption());

        }
};