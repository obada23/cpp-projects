#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include <fstream>
using namespace std;

class clsUser : public clsPerson
{

    public:
        enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

        struct stLoginRegisterRecord
        {
            string DateTime;
            string UserName;
            string Password;
            int Permissions;
        };

        enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegister = 128 , pCurrancyExchange = 256 };

        clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
        : clsPerson(FirstName,LastName,Email,Phone)
        {
            this->_Mode = Mode;
            this->_UserName = UserName;
            this->_Password = Password;
            this->_Permissions = Permissions;
        }

        bool isEmpty()
        {
            return (this->_Mode == EmptyMode);
        }

        void setUserName(string UserName)
        {
            this->_UserName = UserName;
        }

        string getUserName()
        {
            return this->_UserName;
        }

        void setPassword(string Password)
        {
            this->_Password = Password;
        }

        string getPassword()
        {
            return this->_Password;
        }

        void setPermissions(int Permissions)
        {
            this->_Permissions = Permissions;
        }

        int getPermissions()
        {
            return this->_Permissions;
        }

        void setcurrentDateATime(string currentDateATime)
        {
            this->_CurrentDateATime = currentDateATime;
        }

        string getcurrentDateATime()
        {
            return _CurrentDateATime;
        }

        static clsUser Find(string UserName)
        {
            vector<clsUser> vUser;
            fstream myFile;
            myFile.open("Users.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsUser User = _ConvertLineToUserObject(line);
                    if(User._UserName == UserName)
                    {
                        myFile.close();
                        return User;
                    }
                    
                }
                myFile.close();
            }

            return _GetEmptyUserObject();
        }

        static clsUser Find(string UserName, string Password)
        {
            vector<clsUser> vUser;
            fstream myFile;
            myFile.open("Users.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsUser User = _ConvertLineToUserObject(line);
                    if(User._UserName == UserName && User._Password == Password)
                    {
                        myFile.close();
                        return User;
                    }
                    
                }
                myFile.close();
            }
            return _GetEmptyUserObject();

        }

        enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserIsExists = 2 };

        enSaveResults Save()
        {
            switch(this->_Mode)
            {
                case EmptyMode :
                {
                    if(isEmpty())
                    {
                        return svFaildEmptyObject;
                    }
                    break;
                }

                case UpdateMode :
                {
                    _Update();
                    return svSucceeded;
                    break;
                }

                case AddNewMode : 
                {
                    if(IsUserExist(this->_UserName))
                    {
                        return svFaildUserIsExists;
                    }
                    else
                    {
                        _AddNew();
                        this->_Mode = UpdateMode;
                        return svSucceeded;
                    }
                    break;
                }
            }
        }

        static bool IsUserExist(string UserName)
        {
            clsUser User = Find(UserName);
            return (!User.isEmpty());
        }

        static bool IsUserAndPasswordExist(string UserName,string Password)
        {
            clsUser User = Find(UserName,Password);
            return (!User.isEmpty());
        }

        

        bool Delete()
        {
            vector<clsUser> vUsers = _LoadUsersDataFromFile();
            for(clsUser &U : vUsers)
            {
                if(U._UserName == this->_UserName)
                {
                    U._MarkedForDelete = true;
                    break;
                }
            }

            _SaveUsersDataToFile(vUsers);
            *this = _GetEmptyUserObject();
            return true;
        }

        static clsUser GetAddNewUserObject(string UserName)
        {
            return clsUser(AddNewMode,"","","","",UserName,"",0);
        }

        static vector<clsUser> GetUsersList()
        {
            return _LoadUsersDataFromFile();
        }

        bool CheckAccessPermission(enPermissions Permission)
        {
            if(this->_Permissions == enPermissions::eAll)
                return true;
            if((this->_Permissions&Permission) == Permission)
                return true;
            else 
                return false;
        }

        void LoginRegister()
        {
            string line = _PrepareLogInRecord();
            _AddDataLogLineToFile(line);
        }


        static vector<stLoginRegisterRecord> getLoginRegisterList()
        {
            vector <stLoginRegisterRecord> vLoginRegisterRecord;
            fstream myFile;
            myFile.open("LoginRegister.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                stLoginRegisterRecord LoginRegisterRecord;

                while(getline(myFile,line))
                {
                    LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
                    vLoginRegisterRecord.push_back(LoginRegisterRecord);
                }
                myFile.close();
            }
            return vLoginRegisterRecord;
        }
    private:
        enMode _Mode;
        string _UserName;
        string _Password;
        int _Permissions;
        bool _MarkedForDelete = false;
        string _CurrentDateATime;

        static clsUser _ConvertLineToUserObject(string line,string Seprator="#//#")
        {
            vector<string> vString = clsString::splitString(line,Seprator);
            return clsUser(UpdateMode,vString.at(0),vString.at(1),vString.at(2),vString.at(3), vString.at(4), clsUtil::DecryptText(vString.at(5),2), stoi(vString.at(6)));
        }

        
        static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line,string seprator="#//#")
        {
            stLoginRegisterRecord LoginRegisterRecord; 
            vector<string> LoginRegisterDataLine = clsString::splitString(line,seprator);
            LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
            LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
            LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2],2);
            LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);
            return LoginRegisterRecord;
            
        }

        static vector<clsUser> _LoadUsersDataFromFile()
        {
            vector<clsUser> vUser;
            fstream myFile;
            myFile.open("Users.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsUser User = _ConvertLineToUserObject(line);
                    vUser.push_back(User);
                }
                myFile.close();
            }
            return vUser;
        }

        static vector<clsUser> _LoadUsersDataFromLogFile()
        {
            vector<clsUser> vUser;
            fstream myFile;
            myFile.open("LoginRegister.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsUser User = _ConvertLineToUserObject(line);
                    vUser.push_back(User);
                }
                myFile.close();
            }
            return vUser;
        }

        void _SaveUsersDataToFile(vector<clsUser> vUsers)
        {
            fstream myFile;
            myFile.open("Users.txt", ios::out);
            if(myFile.is_open())
            {
                string dataLine;
                for(clsUser &U:vUsers)
                {
                    if(U._MarkedForDelete == false)
                    {
                        dataLine = _ConvertUserObjectToLine(U);
                        myFile << dataLine << endl;
                    }
                    myFile.close();
                }
            }
        }

        string _ConvertUserObjectToLine(clsUser User, string dilm = "#//#")
        {
            string line = "";
            line += User.FirstName() + dilm;
            line += User.LastName() + dilm;
            line += User.Email() + dilm;
            line += User.Phone() + dilm;
            line += User._UserName + dilm;
            line += clsUtil::EncryptText(User._Password,2) + dilm;
            line += to_string(User._Permissions);
            
            return line;
        }

        string _PrepareLogInRecord(string dilm = "#//#")
        {

            setcurrentDateATime(clsDate::dateToString(clsDate::getSystemDate()) + " - " + clsDate::getSystemTime());
            string line = "";
            line += getcurrentDateATime() + dilm;
            line += getUserName() + dilm;
            line += clsUtil::EncryptText(getPassword(),2) + dilm;
            line += to_string(getPermissions());
            return line;
        }

        static clsUser _GetEmptyUserObject()
        {
            return clsUser(EmptyMode,"","","","","","",0);
        }

        void _Update()
        {
            vector<clsUser> _vUser = _LoadUsersDataFromFile();
            for(clsUser &U : _vUser)
            {
                if(U.getUserName() == getUserName())
                {
                    U = *this;
                    break;
                }
            }

            _SaveUsersDataToFile(_vUser);
        }

        void _AddDataLineToFile(string NewLine)
        {
            fstream myFile;
            myFile.open("Users.txt",ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << NewLine << endl;
            }
            myFile.close();
        }

        void _AddDataLogLineToFile(string NewLine)
        {
            fstream myFile;
            myFile.open("LoginRegister.txt",ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << NewLine << endl;
            }
            myFile.close();
        }

        void _AddNew()
        {
            _AddDataLineToFile(_ConvertUserObjectToLine(*this));
        }

};
