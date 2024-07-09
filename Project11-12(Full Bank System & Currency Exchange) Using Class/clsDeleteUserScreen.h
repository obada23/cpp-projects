#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
    private:
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

    public:
        static void ShowDeleteScreen()
        {
            _DrawScreenHeader("\t Delete User Screen");

            string UserName = clsInputValidate::ReadString("Please Enter UserName To Delete: ");
            while(!clsUser::IsUserExist(UserName))
            {
                UserName = clsInputValidate::ReadString("\nUserName Is Not Found, Choose another one: ");
            }
            clsUser DeleteUser = clsUser::Find(UserName);
            _PrintUser(DeleteUser);

            cout << "\nAre you sure you want to delete this User? y/n? ";
            char Answer;
            cin >> Answer;
            if(toupper(Answer)=='Y')
            {
                if(DeleteUser.Delete())
                {
                    cout << "\nUser Deleted Successfully :-)\n";
                    _PrintUser(DeleteUser);
                }
                else
                {
                    cout << "\nError User Was Not Deleted\n";
                }
            }

            
        }

};