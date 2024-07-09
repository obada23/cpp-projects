#include <iostream>
#include "clsScreen.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
    private:
        static void PrintTransferLogRecordLine(clsBankClient::stTrasferLogRecord TransferLogRecord)
        {

            cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateAndTime;
            cout << "| " << setw(8) << left << TransferLogRecord.SourceAccount;
            cout << "| " << setw(8) << left << TransferLogRecord.DestenationAccount;
            cout << "| " << setw(8) << left << TransferLogRecord.Amount;
            cout << "| " << setw(10) << left << TransferLogRecord.SourceBalance;
            cout << "| " << setw(10) << left << TransferLogRecord.DestenationBalance;
            cout << "| " << setw(8) << left << TransferLogRecord.CurrentUser;

        
        }
    public:
        static void ShowTransferLogScreen()
        {
            vector<clsBankClient::stTrasferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
            string Title = "\t Transfer Log List Screen";
            string SubTitle =  "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";
            _DrawScreenHeader(Title, SubTitle);

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
            cout << "| " << left << setw(8) << "s.Acct";
            cout << "| " << left << setw(8) << "d.Acct";
            cout << "| " << left << setw(8) << "Amount";
            cout << "| " << left << setw(10) << "s.Balance";
            cout << "| " << left << setw(10) << "d.Balance";
            cout << "| " << left << setw(8) << "User";

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vTransferLogRecord.size() == 0)
                cout << "\t\t\t\tNo Transfers Available In the System!";
            else

                for (clsBankClient::stTrasferLogRecord Record : vTransferLogRecord)
                {

                    PrintTransferLogRecordLine(Record);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }


};
