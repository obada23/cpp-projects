#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
    protected:
        static void _DrawScreenHeader(string Title,string SubTitle ="")
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  " << Title;
            if (SubTitle != "")
            {
                cout << "\n\t\t\t\t\t  " << SubTitle;
            }
            cout << "\n\t\t\t\t\t______________________________________\n\n";

            cout << "\t\t\t\t\tUser: " << CurrentUser.getUserName() << endl;

            clsDate date = clsDate::getSystemDate();
            cout << "\t\t\t\t\tDate: ";
            date.Print();
            cout << endl;
        }

        

        static bool CheckAccessRights(clsUser::enPermissions Permission)
        {
            if(!CurrentUser.CheckAccessPermission(Permission))
            {
                cout << "\t\t\t\t\t______________________________________";
                cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin\n";
                cout << "\t\t\t\t\t______________________________________\n\n";
                return false;
            }
            else 
                return true;
        }
        
};