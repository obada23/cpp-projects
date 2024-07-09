#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
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
        static void ShowDeleteClientScreen()
        {

            if(!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
            {
                return;
            }

            _DrawScreenHeader("\t Delete Client Screen");
            string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");
            while(!clsBankClient::isClientExist(AccountNumber))
            {
                AccountNumber = clsInputValidate::ReadString("\nAccount number is not found, choose another one: ");
            }
            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            _Print(Client1);

            cout << "Are you sure you want to delete this client y/n? ";
            char Answer;
            cin >> Answer;

            if(toupper(Answer)=='Y')
            {
                if(Client1.Delete())
                {
                    cout << "\nClient Deleted Successfully :-)\n";
                    _Print(Client1);
                }
                else
                    cout << "\nError Client Was not Deleted\n";
            }


        }

};
