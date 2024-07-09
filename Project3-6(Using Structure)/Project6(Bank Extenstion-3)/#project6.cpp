#include <iostream>
#include <fstream>
using namespace std;

void login();
void mainMenue();

struct stClient
{
    string accountNumber;
    string pinCode;
    string fullName;
    string phone;
    double accountBalance;
};

enum enChoice { QuickWithdraw=1, NormalWithdraw=2, Deposit=3, CheckBalance=4, Logout=5 };

stClient currentClient;

const string clientFileName = "clientRecord.txt";
const string userFileName = "Users.txt";

void loginScreen()
{system("clear");
    cout << "---------------------------------------\n";
    cout << "\t   Login Screen\n";
    cout << "---------------------------------------\n";
}

vector<string> splitString(string record, string seprator="#//#")
{
    vector<string> line;
    string word="";
    short i=0;
    while(i<record.length())
    {
        if(record[i]!=seprator[0])
        {
            word += record[i];
            i++;
        }
        else
        {
            line.push_back(word);
            word="";
            i+=4;
        }
    }
    line.push_back(word);
    return line;
}

stClient convertRecordToData(string record)
{
    vector<string> line = splitString(record);
    stClient client;
    client.accountNumber = line.at(0);
    client.pinCode = line.at(1);
    client.fullName = line.at(2);
    client.phone = line.at(3);
    client.accountBalance = stod(line.at(4));
    return client;
}


vector<stClient> loadDataFromFile()
{
    vector<stClient> vClient;
    stClient client;
    fstream myFile;
    myFile.open(clientFileName,ios::in);
    if(myFile.is_open())
    {
        string record;
        while(getline(myFile,record))
        {
            client = convertRecordToData(record);
            vClient.push_back(client);
        }
        myFile.close();
    }
    return vClient;
}

bool isExist(stClient &client)
{
    vector<stClient> vClient = loadDataFromFile();
    for(stClient &c : vClient)
    {
        if(c.accountNumber==client.accountNumber && c.pinCode == client.pinCode)
        {
            client.fullName = c.fullName;
            client.phone = c.phone;
            client.accountBalance = c.accountBalance;
            return true;
        }
            
    }
    system("clear");
    loginScreen();
    cout << "Invalid Account Number/Pin Code!" << endl;
    return false;
}

stClient readClient()
{
    stClient client;
    do
    {
        cout << "Enter Account Number? ";
        cin >> client.accountNumber;
        cout << "Enter Pin? ";
        cin >> client.pinCode;
    } while (!isExist(client));

    return client;
}

short yourChoice(string message)
{
    short choice;
    do
    {
        cout << message;
        cin >> choice;
        cout << endl;
    } while (choice<1 || choice>5);

    return choice;  
}

void logout()
{
    system("clear");
    login();
}

void balanceScreen()
{
    system("clear");
    cout << "=======================================\n";
    cout << "\t   Check Balance Screen\n";
    cout << "=======================================\n";
}

void yourBalance()
{
    cout << "Your Balance Is " << currentClient.accountBalance << endl << endl;
}

void checkBalane()
{   
    balanceScreen();
    yourBalance();
    system("read -n 1 -s -p \"Press any key to go back to Manage User Main Menue Screen...\"");
    mainMenue();
}

void quickWithdrawScreen()
{
    system("clear");
    cout << "===========================================\n";
    cout << "\t    Quick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20 \t\t[2] 50\n";
    cout << "\t[3] 100 \t[4] 200\n";
    cout << "\t[5] 400 \t[6] 600\n";
    cout << "\t[7] 800 \t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
}

short yourWithdrawChoice(string message)
{
    short choice;
    do
    {
        cout << message;
        cin >> choice;
        cout << endl;
    } while (choice<1 || choice>9);

    return choice;
}

bool areYouSure()
{
    char youSure;
    cout << "Are you sure you want perform this transaction? y/n? ";
    cin >> youSure;
    if(toupper(youSure) == 'Y')
        return true;
    else
        return false;

}

string convertDataFromRecordToLine(stClient client,string dilm="#//#")
{
    string line="";
    line += client.accountNumber + dilm;
    line += client.pinCode + dilm;
    line += client.fullName + dilm;
    line += client.phone + dilm;
    line += to_string(client.accountBalance);
    return line;
    
}

void updateDataToFile(stClient client)
{
    string line = convertDataFromRecordToLine(client);
    string updatedLine = convertDataFromRecordToLine(currentClient);
    fstream myFile,temp;
    myFile.open(clientFileName,ios::in);
    temp.open("temp.txt",ios::out);
    if(myFile.is_open()&&temp.is_open())
    {
        string record;
        while(getline(myFile,record))
        {
            if(record!=line)
            {
                temp << record << endl;
            }
            else
            {
                temp << updatedLine << endl;
            }
        }
        myFile.close();
        temp.close();
    }

    remove(clientFileName.c_str());
    rename("temp.txt",clientFileName.c_str());
}

void decreaseBalance(int number)
{
    if(number<=currentClient.accountBalance)
    {
        stClient client = currentClient;
        currentClient.accountBalance -= number;
        updateDataToFile(client);
        cout << "\nDone Successfully. New balance is : " << currentClient.accountBalance << endl << endl;
    }
    else
        cout << "\nInsufficient balance" << endl << endl;
    
}

void withdrawOption()
{
    short choice = yourWithdrawChoice("Choose what to withdraw from [1] to [9] ? ");
    switch(choice)
    {
        case 1 : {
            if(areYouSure())
                decreaseBalance(20); 
            break;
        }
        
        case 2 : {
            if(areYouSure())
                decreaseBalance(50);
            break;
        }

        case 3 : {
            if(areYouSure())
                decreaseBalance(100);
            break;
        }

        case 4 : {
            if(areYouSure())
                decreaseBalance(200);
            break;
        }

        case 5 : {
            if(areYouSure())
                decreaseBalance(400);
            break;
        }

        case 6 : {
            if(areYouSure())
                decreaseBalance(600);
            break;
        }

        case 7 : {
            if(areYouSure())
                decreaseBalance(800);
            break;
        }

        case 8 : {
            if(areYouSure())
                decreaseBalance(800);
            break;
        }

        case 9 : {
            break;
        }
    }
    cout << endl;
    system("read -n 1 -s -p \"Press any key to go back to Manage User Main Menue Screen...\"");
    mainMenue();

}

void quickWithdraw()
{
    quickWithdrawScreen();
    yourBalance();
    withdrawOption();
}

void normalWithdrawScreen()
{
    system("clear");
    cout << "=======================================\n";
    cout << "\t   Normal Withdraw Screen\n";
    cout << "=======================================\n";
    
}

int readAmount()
{
    int number;
    do
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> number;
        cout << endl;
    } while (number%5!=0);
    return number;
    
}

void normalWithdraw()
{
    normalWithdrawScreen();
    int amount = readAmount();
    if(areYouSure())
    {
        decreaseBalance(amount);
    }
    cout << endl;

    system("read -n 1 -s -p \"Press any key to go back to Manage User Main Menue Screen...\"");
    mainMenue();
}

void depositScreen()
{
    system("clear");
    cout << "=======================================\n";
    cout << "\t   Deposit Screen\n";
    cout << "=======================================\n";
}

void increaseBalance(int amount)
{
    stClient client = currentClient;
    currentClient.accountBalance += amount;
    updateDataToFile(client);
    cout << "\nDone Successfully. New balance is : " << currentClient.accountBalance << endl << endl;
}

void deposit()
{
    depositScreen();
    int amount = readAmount();
    if(areYouSure())
        increaseBalance(amount);
    else
        cout << endl;
    system("read -n 1 -s -p \"Press any key to go back to Manage User Main Menue Screen...\"");
    mainMenue();

}

void performOption(enChoice choice)
{
    switch(choice)
    {
        case QuickWithdraw : {
            quickWithdraw();
            break;
        }

        case NormalWithdraw : {
            normalWithdraw();

        }

        case Deposit : {
            deposit();
            break;
        }

        case CheckBalance : {
            checkBalane();
            break;
        }

        case Logout : {
            logout();
            break;
        } 
    }
}

void mainMenueScreen()
{system("clear");
    cout << "===========================================\n";
    cout << "\t   ATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "[1] Quick Withdraw.\n";
    cout << "[2] Normal Withdraw.\n";
    cout << "[3] Deposit.\n";
    cout << "[4] Check Balance.\n";
    cout << "[5] Logout.\n";
    cout << "===========================================" << endl;
    performOption((enChoice)yourChoice("Choose what do you want to do? [1 to 5]? "));

}

void mainMenue()
{
    mainMenueScreen();
}

void login()
{
    loginScreen();
    stClient client = readClient();
    currentClient = client;
    mainMenue();
}

int main()
{
    login();
cout << "\n\n\n\n\n\n\n\n";
    return 0;
}