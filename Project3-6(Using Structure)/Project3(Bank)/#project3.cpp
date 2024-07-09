#include <iostream>
#include <fstream>
//Bank 1
using namespace std;

const string clientFileName = "clientRecord.txt";

enum enUpdateClient { PinCode=1, FullName=2, Phone=3, AccountBalane=4 };

enum enMainMenueOption { Show=1, Add=2, Delete=3, Update=4, Find=5, Exit=6 };

struct stClient
{
    string accountNumber;
    string pinCode;
    string fullName;
    string phone;
    double accountBalance;
};

string Tabs(short);

vector<string> spiltString(string, string);

stClient convertLineToRecord(string);

short readYourChoose(string);

void printClientRecord(stClient);

void showClientList(vector<stClient>);

vector<stClient> LoadClientDataFromFile();

void performOption(enMainMenueOption);

void showMainMenueScreen();

void addNewClientsScreen();

void addClientToFile(string);

stClient readNewClient();

bool accountNumberIsExist(string);

void addClients();

void addNewClient();

string convertRecordToLine(stClient,string);

void deleteScreen();

string readAccountNumber(string);

bool findClientToDelete(string,stClient&);

void deleteClientFromFile(string);

void printClientDetails(stClient);

bool findClientAccountNumber(vector<stClient>,stClient&,string);

bool deleteClient();

void updateClient(stClient,string);

void updateClientFromFile(stClient);

string updateClientFromStructure(stClient&,string);

void findScreen();

void exitScreen();


int main()
{system("clear");

    showMainMenueScreen();

    return 0;
}

void performOption(enMainMenueOption choice)
{
    switch(choice)
    {
        case Show : {system("clear");
            stClient client;
            vector<stClient> vClients = LoadClientDataFromFile();
            showClientList(vClients);
            showMainMenueScreen();
            break;
        } 

        case Add : {system("clear");
            addNewClientsScreen();
            addClients();
            showMainMenueScreen();
            break;
        }
        
        case Delete : {system("clear");
            stClient client;
            deleteScreen(); cout << endl;
            string accountNumber = readAccountNumber("Please Enter AccountNumber? "); cout << endl;
            if(findClientToDelete(accountNumber,client))
            {
                string line = convertRecordToLine(client,"#//#");
                printClientDetails(client);
                if(deleteClient())
                    deleteClientFromFile(line);
            }
            else
                cout << "Client With Account Number (" << accountNumber << ") Is Not Fount!" << endl << endl;
            
            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break;
        }
        case Update : {system("clear");
            stClient client;
            vector<stClient> vClients = LoadClientDataFromFile();
            string accountNumber = readAccountNumber("Please Enter AccountNumber? "); cout << endl;
            if(findClientAccountNumber(vClients,client,accountNumber))
            {
                printClientDetails(client);
                updateClient(client,accountNumber);
            }
            else
                cout << "Client With Account Number (" << accountNumber << ") Is Not Found!" << endl;

            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break; 

        }
        case Find : {
            system("clear");
            findScreen();
            stClient client;
            string accountNumber = readAccountNumber("Please Enter AccountNumber? "); cout << endl;
            vector<stClient> vClients = LoadClientDataFromFile();
            if(findClientAccountNumber(vClients,client,accountNumber))
                printClientDetails(client);
            else
                cout << "Client With Account Number[" << accountNumber <<"] Is Not Found!" << endl << endl;
            
            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break; 

        }

        case Exit : {system("clear");
            exitScreen();
            break;
        }

        
    }

}

void addClients()
{
    char addMore;
    do
    {
        system("clear");
        cout << "\nAdding New Client:\n\n";
        addNewClient();

        cout << "Do you want to add another client? Y/N? ";
        cin >> addMore;
        cout << endl;

    } while (toupper(addMore)=='Y');
    system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
    
}

void addNewClientsScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "Add New Clinets Screen\n";
    cout << "----------------------------------------\n";
}

void addClientToFile(string line)
{

    fstream myFile;
    myFile.open("clientRecord.txt",ios::out|ios::app);
    if(myFile.is_open())
    {
        myFile << line << endl;
    }
    myFile.close();

}

stClient readNewClient()
{
    cout << "Enter Account Number ? ";
    stClient client;
    do
    {
        getline(cin >> ws,client.accountNumber);
        if(!accountNumberIsExist(client.accountNumber))
            continue;
        else
        {
            cout << "Enter Pin Code ? ";
            getline(cin,client.pinCode);
            cout << "Enter Name? ";
            getline(cin,client.fullName);
            cout << "Enter Phone? ";
            getline(cin,client.phone);
            cout << "Enter Account Balance? ";
            cin >> client.accountBalance;
            cout << endl;
            return client;
        }
    
    } while (true);
    

}

bool accountNumberIsExist(string accountNumber)
{
    vector<stClient> vClient = LoadClientDataFromFile();
    for(stClient &c : vClient)
    {
        if(accountNumber == c.accountNumber)
        {
            cout << "Client with [" << accountNumber << "] already exisits, Enter another account Number? ";
            return false; 
        }
    }
    return true;
}

void addNewClient()
{
    stClient client;
    client = readNewClient();
    addClientToFile(convertRecordToLine(client,"#//#"));
}

string convertRecordToLine(stClient client, string delim)
{
    string line ="";
    line += client.accountNumber + delim;
    line += client.pinCode + delim;
    line += client.fullName + delim;
    line += client.phone + delim;
    line += to_string(client.accountBalance);
    return line;

}

vector<string> spiltString(string line, string seprator="#//#")
{
    vector<string> vClient;
    string word="";
    int i=0;
    while(i<line.length())
    {
        if(line[i] != seprator[0])
        {
            word += line[i];
            i++;
        }
        else
        {
            vClient.push_back(word);
            word="";
            i+=seprator.length();
        }
    }
    vClient.push_back(word);
    word="";
    return vClient;
}

string Tabs(short numberOfTabs)
{
    string tab="";
    for(int i=0;i<numberOfTabs;i++)
    {
        tab+="\t";
    }
    return tab;
}

stClient convertLineToRecord(string line)
{
    vector<string> vClient = spiltString(line);
    stClient client;
    client.accountNumber = vClient.at(0);
    client.pinCode = vClient.at(1);
    client.fullName = vClient.at(2);
    client.phone = vClient.at(3);
    client.accountBalance = stod(vClient.at(4));
    return client;

}

short readYourChoose(string message)
{
    short choose;
    do
    {
        cout << message;
        cin >> choose;
        cout << endl;
    } while (choose<1&&choose>6);
    cout  << endl;
    return choose;
    
}

void printClientRecord(stClient client)
{
    cout << Tabs(1) << setw(8) << client.accountNumber << Tabs(2) << "|";
    cout << Tabs(1) << setw(8) << client.pinCode << Tabs(1) << "|";
    cout << Tabs(2) << setw(16) << client.fullName << Tabs(2) << "|";
    cout << Tabs(1) << setw(8) << client.phone << Tabs(1) << "|";
    cout << "   " <<  client.accountBalance << Tabs(1);
}

void showClientList(vector<stClient> vClients)
{system("clear");
    cout << Tabs(7) << "  Client List (" << vClients.size() << ") Client(s)." << endl;
    cout << Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
    cout << Tabs(1) << "Account Number" << Tabs(2) << "|" << Tabs(1) << "Pin Code" << Tabs(1) << "|" << Tabs(2) << "Client Name" << Tabs(3) << "|" << Tabs(1) << "  Phone" << Tabs(2) << "|   " <<  "Balance" << endl;
    cout << Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
    for(stClient &client : vClients)
    {
        printClientRecord(client);
        cout << endl;
    }
    cout << Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
    system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
}

vector<stClient> LoadClientDataFromFile()
{
    stClient client;
    vector<stClient> vClient;
    fstream myFile;
    myFile.open("clientRecord.txt",ios::in);
    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            client = convertLineToRecord(line);
            vClient.push_back(client);
        }
        myFile.close();

    }
    return vClient;

}

void showMainMenueScreen()
{
    system("clear");
    cout <<"=================================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout <<"=================================================\n";
    cout << "[1] Show Client List." << endl;
    cout << "[2] Add New Client." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client Info." << endl;
    cout << "[5] Find Client." << endl;
    cout << "[6] Exit." << endl;
    cout <<"=================================================\n";
    performOption((enMainMenueOption)readYourChoose("Choose what do you want to do? [1 to 6]? "));

}

void deleteScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "Delete Client Screen\n";
    cout << "----------------------------------------\n";
}

string readAccountNumber(string message)
{
    string accountNumber;
    cout << message;    
    cin >> accountNumber;
    return accountNumber;
    
}

bool findClientToDelete(string accountNumber,stClient &client)
{
    vector<stClient> vClient = LoadClientDataFromFile();
    for(stClient &c :vClient)
    {
        if(accountNumber==c.accountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}

void deleteClientFromFile(string line)
{
    fstream myFile;
    fstream temp;
    myFile.open("clientRecord.txt",ios::in);
    temp.open("temp.txt",ios::out|ios::app);
    if(myFile.is_open()&&temp.is_open())
    {
        string record;
        while(getline(myFile,record))
        {
            if(record!=line)
            {
                temp << record << endl;
            }
        }
        myFile.close();
        temp.close();

        remove(clientFileName.c_str());
        rename("temp.txt",clientFileName.c_str());
    }


}

void printClientDetails(stClient client)
{
    cout << "The following are the client details:\n";
    cout << "-------------------------------------\n";
    cout << "Account Number  : " << client.accountNumber << endl;
    cout << "Pin Code        : " << client.pinCode << endl;
    cout << "Name            : " << client.fullName << endl;
    cout << "Phone           : " << client.phone << endl;
    cout << "Account Balance : " << client.accountBalance << endl;
    cout << "-------------------------------------\n\n";


}

bool deleteClient()
{
    char deleteC;
    cout << "Are you sure you want delete this client? Y/N? ";
    cin >> deleteC;
    if(toupper(deleteC) == 'Y')
    {
        cout << "\nClient Deleted Successfully." << endl << endl;
        return true;
    }
    return false;

}

bool findClientAccountNumber(vector<stClient> vClient,stClient &client,string accountNumber)
{
    for(stClient &c : vClient)
    {
        if(c.accountNumber == accountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}

void updateClient(stClient client,string accountNumber)
{
    char uClient;
    cout << "\nAre you sure you want update this client? Y/N? ";
    cin >> uClient;
    if(toupper(uClient)=='Y')
    {
        updateClientFromFile(client);
        cout << "\nClient Updated Successfuly." << endl;
    }

}

void updateClientFromFile(stClient client)
{
    string line = convertRecordToLine(client,"#//#");
    string updatedLine = updateClientFromStructure(client,"#//#");

    fstream myFile,temp;
    myFile.open(clientFileName,ios::in);
    temp.open("temp.txt",ios::out);
    if(myFile.is_open()&&temp.is_open())
    {
        string record;
        while(getline(myFile,record))
        {
            if(record != line)
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

string updateClientFromStructure(stClient &client,string seprator)
{
    char moreUpdate;
    short choose;
    do
    {
        cout << "\nPlease enter what do you want to change " << endl;
        cout << "[1]Pin Code, [2]Full Name, [3]Phone, [4]Account Balance? ";
        cin >> choose;
        switch(choose)
        {
            case PinCode : {
                cout << "Enter PinCode? ";
                cin >> client.pinCode;
                break;
            }

            case FullName : {
                cout << "Enter Name? ";
                cin.ignore(1,'\n');
                getline(cin,client.fullName);
                break;
            }

            case Phone : {
                cout << "Enter Phone? ";
                cin >> client.phone;
                break;
            }

            case AccountBalane : {
                cout << "Enter AccountBalance? ";
                cin >> client.accountBalance;
                break;
            }

            default:{
                cout << "Invalid choice. Please try again." << endl << endl;
                continue;
            }
   
        }
        cout << "Do you want to update more information? Y/N? ";
        cin >> moreUpdate;
    } while (toupper(moreUpdate)=='Y');

    return convertRecordToLine(client,"#//#");
    
    
}

void findScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "Find Client Screen\n";
    cout << "----------------------------------------\n\n";
}

void exitScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "   Program Ends :-)\n";
    cout << "----------------------------------------\n\n";
}