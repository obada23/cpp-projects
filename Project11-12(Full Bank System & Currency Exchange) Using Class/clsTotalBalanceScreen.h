#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
    private:
        static void _PrintClientRecordBalanceLine(clsBankClient Client)
        {

            cout << "| " << setw(15) << left << Client.AccountNumber();
            cout << "| " << setw(40) << left << Client.FullName();
            cout << "| " << setw(12) << left << Client.AccountBalance();

        }

    public:
        static void ShowTotalBalanceScreen()
        {
            _DrawScreenHeader("\t Total Balance Screen");

            vector <clsBankClient> vClients = clsBankClient::GetClientsList();

            cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(40) << "Client Name";
            cout << "| " << left << setw(12) << "Balance";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            double TotalBalances = clsBankClient::GetTotalBalances();

            if (vClients.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else

                for (clsBankClient Client : vClients)
                {
                    _PrintClientRecordBalanceLine(Client);
                    cout << endl;
                }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
            cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
        }
};
