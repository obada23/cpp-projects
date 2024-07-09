#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
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
        static void ShowFindScreen()
        {
            _DrawScreenHeader("\t Find User Screen");
            string UserName = clsInputValidate::ReadString("Please Enter UserName: ");
            
            while(!clsUser::IsUserExist(UserName))
            {
                UserName = clsInputValidate::ReadString("\nUser is not found, choose another one: ");
            }
            clsUser User1 = clsUser::Find(UserName);
            cout << "\nUser Found :-)" << endl;
            _PrintUser(User1);
        }

};
