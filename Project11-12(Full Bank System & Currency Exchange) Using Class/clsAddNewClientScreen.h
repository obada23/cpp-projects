#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
    private:
        static void _ReadClientInfo(clsBankClient &Client)
        {
            Client.setFirstName(clsInputValidate::ReadString("Enter FirstName: "));
            Client.setLastName(clsInputValidate::ReadString("Enter LastName: "));
            Client.setEmail(clsInputValidate::ReadString("Enter Email: "));
            Client.setPhone(clsInputValidate::ReadString("Enter Phone: "));
            Client.setPinCode(clsInputValidate::ReadString("Enter PinCode: "));
            Client.setAccountBalance(clsInputValidate::ReadFloatNumber("Enter AccountBalance: "));
        }

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

        static void ShowAddNewClientScreen()
        {
            if(!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
            {
                return;
            }
            
            _DrawScreenHeader("\t Add New Client Screen");
            
            string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");
            while(clsBankClient::isClientExist(AccountNumber))
            {
                AccountNumber = clsInputValidate::ReadString("\nAccount number is already exist, try again: ");
            }
            clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

            _ReadClientInfo(NewClient);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = NewClient.Save();
            
            switch(SaveResult)
            {
                case clsBankClient::svSucceeded :
                {
                    cout << "\nAccount Addeded Successfully :-)\n";
                    _Print(NewClient);
                    break;
                }

                case clsBankClient::svFaildEmptyObject :
                {
                    cout << "\nError account was not saved becuase it's Empty\n";
                    break;
                }

                case clsBankClient::svFaildAccountNumberExisit :
                {
                    cout << "\nError account was not saved because account number is already exist\n";
                    break;
                }
            }
        }

};