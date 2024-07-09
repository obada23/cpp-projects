#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsListUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
    private:
        enum _enManageUserMenue { ListUser = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, MMainMenue = 6 };
        
        static short _ReadManageUsersOption()
        {
            short choice;
            do
            {
                cout << "\t\t\t\t      Choose what do you want to do? [1 to 6]? ";
                cin >> choice;

            } while (choice<1||choice>6);
            
            return choice;
        }

        static void _GoBackToManageUsersMenue()
        {
            system("read -n 1 -s -p \"Press any key to go back to Manage Users Menue...\"");
            ShowManageUsersMenue();
        }

        static void _ShowListUserScreen()
        {   
            clsListUserScreen :: ShowUserList();
        }

        static void _ShowAddNewUserScreen()
        {
            clsAddNewUserScreen :: ShowAddUserScreen();
        }

        static void _ShowDeleteUserScreen()
        {
            clsDeleteUserScreen :: ShowDeleteScreen();
        }

        static void _ShowUpdateUserScreen()
        {
            clsUpdateUserScreen :: ShowUpdateScreen();
        }

        static void _ShowFindUserScreen()
        {
            clsFindUserScreen :: ShowFindScreen();
        }

        static void _PerformManageUserOption(_enManageUserMenue yourChoice)
        {
            switch(yourChoice)
            {
                case ListUser :
                {
                    system("clear");
                    _ShowListUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }

                case AddNewUser :
                {
                    system("clear");
                    _ShowAddNewUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }

                case DeleteUser :
                {
                    system("clear");
                    _ShowDeleteUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }

                case UpdateUser :
                {
                    system("clear");
                    _ShowUpdateUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }

                case FindUser :
                {
                    system("clear");
                    _ShowFindUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }

                case MMainMenue :
                {
                    break;
                }
            }
        }

    public:
        static void ShowManageUsersMenue()
        {

            if(!CheckAccessRights(clsUser::enPermissions::pManageUsers))
            {
                return;
            }

            system("clear");
            _DrawScreenHeader("\t Manage Users Screen");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n";
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Delete User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User.\n";
            cout << setw(37) << left << "" << "\t[5] Find User.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _PerformManageUserOption((_enManageUserMenue)_ReadManageUsersOption());
        }

};
