#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "Global.h"
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson
{

    public:
        enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

        clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName,LastName,Email,Phone)
        {
            this->_Mode = Mode;
            this->_AccountNumber = AccountNumber;
            this->_PinCode = PinCode;
            this->_AccountBalance = AccountBalance;
        }

        bool IsEmpty()
        {
            return (this->_Mode == EmptyMode);
        }

        string AccountNumber()
        {
            return this->_AccountNumber;
        }

        void setPinCode(string PinCode)
        {
            this->_PinCode = PinCode;
        }

        string PinCode()
        {
            return this->_PinCode;
        }

        void setAccountBalance(float AccountBalance)
        {
            this->_AccountBalance = AccountBalance;
        }

        float AccountBalance()
        {
            return this->_AccountBalance;
        }

        void setcurrentDateATime(string currentDateATime)
        {
            this->_CurrentDateATime = currentDateATime;
        }

        string getcurrentDateATime()
        {
            return _CurrentDateATime;
        }

        // No Ui Related code inside object
        /* void Print()
        {
            cout << "\nClient Card:";
            cout << "\n----------------------------\n";
            cout << "First Name    : " << this->FirstName() << endl;
            cout << "Last Name     : " << this->LastName() << endl;
            cout << "Full Name     : " << this->FullName() << endl;
            cout << "Email         : " << this->Email() << endl;
            cout << "Phone         : " << this->Phone() << endl;
            cout << "Acc. Number   : " << this->_AccountNumber << endl;
            cout << "Password      : " << this->_PinCode << endl;
            cout << "Acc. Balance  : " << this->_AccountBalance << endl;
            cout << "\n----------------------------\n";

        } */


        static clsBankClient Find(string AccountNumber)
        {
            vector <clsBankClient> vClients;
            fstream myFile;
            myFile.open("Clients.txt",ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(line);
                    if(Client.AccountNumber() == AccountNumber)
                    {
                        myFile.close();
                        return Client;
                    }
                    vClients.push_back(Client);
                }
                myFile.close();
            }
            return _GetEmptyClientObject();
        }

        static clsBankClient Find(string AccountNumber,string PinCode)
        {
            //vector <clsBankClient> vClients;
            fstream myFile;
            myFile.open("Clients.txt",ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(line);
                    if(Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode)
                    {
                        myFile.close();
                        return Client;
                    }
                    //vClients.push_back(Client);
                }
                myFile.close();
            }
            return _GetEmptyClientObject();
        }

        static bool isClientExist(string AccountNumber)
        {
            clsBankClient Client1 = Find(AccountNumber);
            return (!Client1.IsEmpty());
        }

        enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExisit = 2 };

        enSaveResults Save()
        {
            switch(this->_Mode)
            {
                case EmptyMode:
                {
                    return svFaildEmptyObject;
                    break;
                }

                case UpdateMode:
                {
                    this->_Update();
                    return svSucceeded;
                    break;
                }

                case AddNewMode:
                {
                    if(clsBankClient::isClientExist(_AccountNumber))
                        return svFaildAccountNumberExisit;

                    else
                    {
                        _AddNew();
                        _Mode = UpdateMode;
                        return svSucceeded;
                    }
                }
            }

        }

        static clsBankClient GetAddNewClientObject(string AccountNumber)
        {
            return clsBankClient(AddNewMode,"","","","",AccountNumber,"",0);
        }

        bool Delete()
        {
            vector<clsBankClient> _vClients = _loadClientDataFromFile();
            for(clsBankClient &C : _vClients)
            {
                if(C.AccountNumber() == this->_AccountNumber)
                {
                    C._MarkedForDelete = true;
                    break;
                }
            }            
            
            _SaveClientsDataToFile(_vClients);

            *this = _GetEmptyClientObject();
            return true;
        }

        static vector<clsBankClient> GetClientsList()
        {
            return _loadClientDataFromFile();
        }

        static double GetTotalBalances()
        {
            vector<clsBankClient> vClients = _loadClientDataFromFile();
            double TotalBalances=0;
            for(int i=0;i<vClients.size();i++)
                TotalBalances+=vClients.at(i)._AccountBalance;
            return TotalBalances;
        }
 
        void Deposit(double Amount)
        {
           _AccountBalance += Amount;
           Save();
        }

        bool Withdraw(double Amount)
        {
            if(Amount > _AccountBalance)
                return false;
            else
            {
                _AccountBalance -= Amount;
                Save();
            }
            return true;
           
        }

        void TransferLog(clsBankClient Client2, int Amount)
        {
            string line = _PrepareTransferInRecord(Client2,Amount);
            _AddDataTransferLineToFile(line);
        }
        struct stTrasferLogRecord
        {
            string DateAndTime;
            string SourceAccount;
            string DestenationAccount;
            int Amount;
            int SourceBalance;
            int DestenationBalance;
            string CurrentUser;

        };

        static vector<stTrasferLogRecord> GetTransferLogList()
        {
            vector<stTrasferLogRecord> vTransferLogRecord;
            fstream myFile;
            myFile.open("TransferLog.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                stTrasferLogRecord TrasferLogRecord;
                while(getline(myFile,line))
                {
                    TrasferLogRecord = _ConvertTransferLogLineToRecord(line);
                    vTransferLogRecord.push_back(TrasferLogRecord);
                }
                myFile.close();
            }
            return vTransferLogRecord;
        }
    private:
        enMode _Mode;
        string _AccountNumber;
        string _PinCode;
        float _AccountBalance;
        bool _MarkedForDelete = false;
        string _CurrentDateATime;

        static clsBankClient _ConvertLineToClientObject(string line, string Seperator ="#//#")
        {
            vector<string> vClientData = clsString::splitString(line,Seperator);
            return clsBankClient(UpdateMode,vClientData[0],vClientData[1],vClientData[2],vClientData[3],vClientData[4],vClientData[5],stof(vClientData[6]));
        }

        static clsBankClient _GetEmptyClientObject()
        {
            return clsBankClient(EmptyMode,"","","","","","",0);
        }

        string _PrepareTransferInRecord(clsBankClient Client2, int Amount, string dilm = "#//#")
        {
            string line="";
            line += (clsDate::dateToString(clsDate::getSystemDate()) + " - " + clsDate::getSystemTime()) + dilm;
            line += AccountNumber() + dilm;
            line += Client2.AccountNumber() + dilm;
            line += to_string(Amount) + dilm;
            line += to_string(AccountBalance()) + dilm;
            line += to_string(Client2.AccountBalance()) + dilm;
            line += CurrentUser.getUserName();
            return line;

        }


        static stTrasferLogRecord _ConvertTransferLogLineToRecord(string line, string Seprator ="#//#")
        {
            stTrasferLogRecord TransferLog;
            vector<string> vString = clsString::splitString(line,Seprator);
            TransferLog.DateAndTime = vString.at(0);
            TransferLog.SourceAccount = vString.at(1);
            TransferLog.DestenationAccount = vString.at(2);
            TransferLog.Amount = stoi(vString.at(3));
            TransferLog.SourceBalance = stoi(vString.at(4));
            TransferLog.DestenationBalance = stoi(vString.at(5));
            TransferLog.CurrentUser = vString.at(6);
            return TransferLog;
        }

        static vector<clsBankClient> _loadClientDataFromFile()
        {
            vector<clsBankClient> vClients;
            fstream myFile;
            myFile.open("Clients.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(line);
                    vClients.push_back(Client);
                }
                myFile.close();
            }
            return vClients;
        }

        string _ConvertClientObjectToLine(clsBankClient Client, string dilm = "#//#")
        {
            string line = "";
            line += Client.FirstName() + dilm;
            line += Client.LastName() + dilm;
            line += Client.Email() + dilm;
            line += Client.Phone() + dilm;
            line += Client._AccountNumber + dilm;
            line += Client._PinCode + dilm;
            line += to_string(Client._AccountBalance);
            return line;
            
        }

        void  _SaveClientsDataToFile(vector<clsBankClient> vClients)
        {
            fstream myFile;
            myFile.open("Clients.txt",ios::out);
            if(myFile.is_open())
            {
                string dataLine;
                for(clsBankClient &C : vClients)
                {
                    if(C._MarkedForDelete == false)
                    {
                        dataLine = _ConvertClientObjectToLine(C);
                        myFile << dataLine << endl;
                    }
                    
                }
                myFile.close();
            }
        }

        void _Update()
        {
            vector <clsBankClient> _vClients = _loadClientDataFromFile();
            for(clsBankClient& C: _vClients)
            {
                if(C.AccountNumber()==AccountNumber())
                {
                    C = *this;
                    break;
                }
            
            }
            _SaveClientsDataToFile(_vClients);
        }

        void _AddDataLineToFile(string NewLine)
        {
            fstream myFile;
            myFile.open("Clients.txt",ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << NewLine << endl;
            }
            myFile.close();
        }

        void _AddNew()
        {
            _AddDataLineToFile(_ConvertClientObjectToLine(*this));
        }

        void _AddDataTransferLineToFile(string line)
        {
            fstream myFile;
            myFile.open("TransferLog.txt",ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << line << endl;
            }
            myFile.close();
        }
           
 

};
