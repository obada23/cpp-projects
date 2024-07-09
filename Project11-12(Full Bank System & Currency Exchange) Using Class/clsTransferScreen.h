#include <iostream>
#include "clsUser.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
    private:
        static void Print(clsBankClient Client1)
        {
            cout << "\nClient Card: \n";
            cout << "------------------------------\n\n";
            cout << "Full Name   : " << Client1.FullName() << endl;
            cout << "Acc. Number : " << Client1.AccountNumber() << endl;
            cout << "Balance     : " << Client1.AccountBalance() << endl;
            cout << "------------------------------\n\n";
        }
    
    public:
        static void ShowTransferScreen()
        {
            _DrawScreenHeader("\t Transfer Screen");
          
            string AccountNumber = clsInputValidate::ReadString("Please Enter Account Number To Transfer From: ");
            while(!clsBankClient::isClientExist(AccountNumber))
            {   
                AccountNumber = clsInputValidate::ReadString("Account Number is not found, Please Enter Account Number To Transfer From: ");
            }
            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            Print(Client1);

            AccountNumber = clsInputValidate::ReadString("Please Enter Account Number To Transfer To: ");
            while(!clsBankClient::isClientExist(AccountNumber))
            {   
                AccountNumber = clsInputValidate::ReadString("Account Number is not found, Please Enter Account Number To Transfer From: ");
            }
            clsBankClient Client2 = clsBankClient::Find(AccountNumber);
            Print(Client2);

            int Amount;
            cout << "Enter Transfer Amount? ";
            cin >> Amount;
            while (Amount>Client1.AccountBalance())
            {
                cout << "Amount Exceeds the available Balance, Enter another Amount? ";
                cin >> Amount;
            }

            char Answer;
            cout << "Are you sure you want to perform this operation? y/n? ";
            cin >> Answer;
            if(toupper(Answer) == 'Y')
            {
                if(Client1.Withdraw(Amount))
                {
                    Client2.Deposit(Amount);
                }

                cout << "Transfer done Successfully" << endl << endl;
                Print(Client1);
                Print(Client2);

                Client1.TransferLog(Client2,Amount);
            }


           

            
        }

};