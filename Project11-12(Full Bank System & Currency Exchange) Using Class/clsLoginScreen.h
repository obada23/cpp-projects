#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
    private:
        static bool _Login()
        {
            short trialsToLogin=2;
            string UserName = clsInputValidate::ReadString("Enter Username? ");
            string Password = clsInputValidate::ReadString("Enter Password? ");

            while(!(clsUser::IsUserAndPasswordExist(UserName,Password) && trialsToLogin>=0))
            {
                if(trialsToLogin == 0)
                {
                    cout << "\nInvalid UserName/Password!\n";
                    cout << "You have " << trialsToLogin << " Trials to login.\n\n";
                    cout << "\nYou are Locked after 3 faild trails " << endl;
                    return false;
                }
                cout << "\nInvalid UserName/Password!\n";
                cout << "You have " << trialsToLogin << " Trials to login.\n\n";
                UserName = clsInputValidate::ReadString("Enter Username? ");
                Password = clsInputValidate::ReadString("Enter Password? ");
                trialsToLogin--;
            }
            CurrentUser = clsUser::Find(UserName);
            CurrentUser.clsUser::LoginRegister();
            clsMainScreen::ShowMainMenue();
            
        }
    
    
    public:
        static bool ShowLoginScreen()
        {
            system("clear");
            _DrawScreenHeader("\t   Login Screen");
            return _Login();
        }
        
};
