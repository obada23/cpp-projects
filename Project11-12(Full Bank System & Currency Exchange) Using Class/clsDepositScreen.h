#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
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

        static void ShowDepositScreen()
        {
            _DrawScreenHeader("\t Deposit Screen");

            string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");

            while(!clsBankClient::isClientExist(AccountNumber))
            {
                cout << "Client with [" << AccountNumber << "] does not exist.\n" << endl;
                AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");
            }
            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            _Print(Client1);

            double Amount = 0;
            cout << "Please enter deposit amount? ";
            Amount = clsInputValidate::ReadDblNumber();

            cout << "\nAre you sure you want to perform this transaction? y/n? ";
            char Answer;
            cin >> Answer;
            if(toupper(Answer) == 'Y')
            {
                Client1.Deposit(Amount);
                cout << "\nAmount Deposited Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance() << endl << endl;
            }
            else
                cout << "Operation was cancelled.\n";

            

        }
};
