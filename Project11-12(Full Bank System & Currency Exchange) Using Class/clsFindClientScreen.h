#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
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

    static void ShowFindClientScreen()
    {

        if(!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\t Find Client Screen");

        string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number: ");
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("\nAccount number is not found, choose another one: ");
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _Print(Client1);

    }

};
