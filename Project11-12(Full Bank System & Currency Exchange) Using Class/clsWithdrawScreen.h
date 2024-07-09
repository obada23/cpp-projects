#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{
    private:
        static void _Print(clsBankClient Client)
        {
            cout << "\nClient Card:";
            cout << "\n----------------------------\n";
            cout << "First Name    : " << Client.FirstName() << endl;
            cout << "Last Name     : " << Client.LastName() << endl;
            cout << "Full Name     : " << Client.FullName() << endl;
            cout << "Email         : " << Client.Email() << endl;
            cout << "Phone         : " << Client.Phone() << endl;
            cout << "Acc. Number   : " << Client.AccountNumber() << endl;
            cout << "Password      : " << Client.PinCode() << endl;
            cout << "Acc. Balance  : " << Client.AccountBalance() << endl;
            cout << "\n----------------------------\n";

        }

    public:  

        static void ShowWithdrawScreen()
        {
            _DrawScreenHeader("\t Withdraw Screen");

            string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");

            while(!clsBankClient::isClientExist(AccountNumber))
            {
                cout << "Client with [" << AccountNumber << "] does not exist.\n" << endl;
                AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");
            }
            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            _Print(Client1);
            

            double Amount;
            cout << "Please enter withdraw amount? ";
            Amount = clsInputValidate::ReadDblNumber();

            cout << "\nAre you sure you want to perform this transaction? y/n? ";
            char Answer;
            cin >> Answer;
            if(toupper(Answer) == 'Y')
            {
                if(Client1.Withdraw(Amount))
                {
                    cout << "\nAmount Withdraw Successfully.\n";
                    cout << "\nNew Balance Is: " << Client1.AccountBalance() << endl << endl;
                }

                else
                {
                    cout << "\nCannot withdraw, Insuffecient Balance!.\n";
                    cout << "\nAmount to withdraw is: " << Amount << endl;
                    cout << "\nYour Balance is: " << Client1.AccountBalance() << endl << endl;
                    
                }
                
            }
            
        

        }
};
