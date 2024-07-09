#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
        static void ShowUpdateClientsScreen()
        {

            if(!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
            {
                return;
            }

            _DrawScreenHeader("\t Update Client Screen");
            string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number: ");
            while(!clsBankClient::isClientExist(AccountNumber))
            {
                AccountNumber = clsInputValidate::ReadString("\nAccount number is not found, choose another one: ");
            }
            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            _Print(Client1);

            cout << "\n\nUpdate Client Info:";
            cout << "\n----------------------------\n";
            _ReadClientInfo(Client1);
            cout << "\n----------------------------\n\n";

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
                case clsBankClient::svSucceeded :
                {
                    cout << "\nAccount Updated Successfully :-)\n";
                    _Print(Client1);
                    break;
                }
                
                case clsBankClient::svFaildEmptyObject :
                {
                    cout << "\nError account was not saved because it is Empty";
                    break;
                }
            
            }
        }

};
