#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
    private:
        static void _ReadUserInfo(clsUser& User)
        {
            User.setFirstName(clsInputValidate::ReadString("Enter FirstName:"));
            User.setLastName(clsInputValidate::ReadString("Enter LastName:"));
            User.setEmail(clsInputValidate::ReadString("Enter Email:"));
            User.setPhone(clsInputValidate::ReadString("Enter Phone:"));
            User.setPassword(clsInputValidate::ReadString("Enter Password:"));
            cout << "Enter Permissions: ";
            User.setPermissions(_ReadPermissionsToSet());
        
        }

        static void _PrintUser(clsUser User)
        {
            cout << "\nUser Card:";
            cout << "\n___________________"; 
            cout << "\nFirstName   : " << User.FirstName();
            cout << "\nLastName    : " << User.LastName();
            cout << "\nFull Name   : " << User.FullName();
            cout << "\nEmail       : " << User.Email();
            cout << "\nPhone       : " << User.Phone();
            cout << "\nUser Name   : " << User.getUserName();
            cout << "\nPassword    : " << User.getPassword();
            cout << "\nPermissions : " << User.getPermissions();
            cout << "\n___________________\n";
        }

        static int _ReadPermissionsToSet()
        {

            int Permissions = 0;
            char Answer = 'n';


            cout << "\nDo you want to give full access? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                return -1;
            }

            cout << "\nDo you want to give access to : \n ";

            cout << "\nShow Client List? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {


                Permissions += clsUser::enPermissions::pListClients;
            }

            cout << "\nAdd New Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pAddNewClient;
            }

            cout << "\nDelete Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pDeleteClient;
            }

            cout << "\nUpdate Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pUpdateClient;
            }

            cout << "\nFind Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pFindClient;
            }

            cout << "\nTransactions? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pTransactions;
            }

            cout << "\nManage Users? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pManageUsers;
            }

            return Permissions;

        }
    
    public:
        static void ShowUpdateScreen()
        {
            _DrawScreenHeader("\t Update User Screen");
            string UserName = clsInputValidate::ReadString("Please Enter UserName: ");
            
            while(!clsUser::IsUserExist(UserName))
            {
                UserName = clsInputValidate::ReadString("\nUserName Is Not Found, Choose another one: ");
            }
            clsUser UpdateUser = clsUser::Find(UserName);

            _PrintUser(UpdateUser);

            cout << "\nAre you sure you want to update this User? y/n? ";
            char Answer;
            cin >> Answer;
            
            if(toupper(Answer)=='Y')
            {
                cout << "\n\nUpdate User Info:\n";
                _ReadUserInfo(UpdateUser);

                clsUser::enSaveResults SaveResult;

                SaveResult = UpdateUser.Save();

                switch (SaveResult)
                {
                case  clsUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Updated Successfully :-)\n";

                    _PrintUser(UpdateUser);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;

                }

                }
            }

        }
};
