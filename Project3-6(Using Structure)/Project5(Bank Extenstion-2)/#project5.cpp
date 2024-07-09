#include <iostream>
#include <fstream>

using namespace std;

const string clientFileName = "clientRecord.txt";

const string userFileName = "Users.txt";

enum enUpdateClient { PinCode=1, FullName=2, Phone=3, AccountBalane=4 };

enum enMainMenueOption { Show=1, Add=2, Delete=3, Update=4, Find=5, Transactions=6, ManageUsers=7, Logout=8 };

enum enTransactionMenueOption { Deposit=1, Withdraw=2, TotalBalance=3, MainMenue=4 };

enum enUpdateUser { Password=1, Permession=2 };

enum enManageUsersMainMenue { ListUser=1, AddUser=2, DeleteUser=3, UpdateUser=4, FindUser=5, MainMenueS=6 };

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

void logoutScreen();

void transactionMenueScreen();

void performOptionTransactions(enTransactionMenueOption);

void depositScreen();

bool checkAccountNumber(string,vector<stClient>);

void updateBalance(stClient &,string);

void updateClientFromFileDeposit(stClient);

void depositOperations();

void withdrawScreen();

void withdrawOperations();

void updateBalanceW(stClient &,string);

void showTotalBalancedList(vector<stClient> );

void printTotalBalancedList(stClient );

void manageUsersMainMenue();

struct stUser
{
    string userName;
    string password;
    short permission;
};

stUser convertLineToRecordUser(string );

vector<stUser> LoadUserDataFromFile();

bool isExist(stUser);

void loginScreen();

stUser readUser();

void login();

void manageUsersMainMenue();

void performOptionManageUsers(enManageUsersMainMenue);

void showUserList();

void printUserRecord(stUser);

void addUser();

void addNewUserScreen();

bool isExistUserName(string);

string convertUserRecordToLine(stUser,string);

void addUserToFile(string);

void readNewUser();

void readNewUserStep2(stUser &);

void giveAccess(string,stUser &,short);

void deleteUser();

void deleteUserScreen();

void deleteUsername();

bool isExistUserName(string ,stUser& );

void printUserDetails(stUser);

bool sureAboutDeleteUser();

void deleteUserFromFile(string);

void updateUser();

void updateUserScreen();

bool sureAboutUpdateUser();

void updateUserFromFile(string,stUser);

void updateUserFromStructure(stUser &);

void findUser();

void findUserScreen();

void currentUserInfo(stUser);

bool checkAccessPermission(short);

void showAccessDeniedMessage();

stUser currentUser;

int main()
{system("clear");

    login();

    return 0;
}

void performOption(enMainMenueOption choice)
{
    stUser user;
    
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
            if(!checkAccessPermission(2))
            {
                showAccessDeniedMessage();
            }
            else
            {
                addNewClientsScreen();
                addClients();
            }

            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break;
        }
        
        case Delete : {system("clear");
            if(!checkAccessPermission(4))
            {
                showAccessDeniedMessage();
            }
            else
            {
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
            
            
            }
            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break;
        }
        case Update : {system("clear");
            if(!checkAccessPermission(8))
            {
                showAccessDeniedMessage();
            }
            else
            {
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
            }

            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break; 

        }
        case Find : {
            system("clear");
            if(!checkAccessPermission(16))
            {
                showAccessDeniedMessage();
            }
            else
            {
                findScreen();
                stClient client;
                string accountNumber = readAccountNumber("Please Enter AccountNumber? "); cout << endl;
                vector<stClient> vClients = LoadClientDataFromFile();
                if(findClientAccountNumber(vClients,client,accountNumber))
                    printClientDetails(client);
                else
                    cout << "Client With Account Number[" << accountNumber <<"] Is Not Found!" << endl << endl;
            }
            
            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break; 

        }

        case Transactions :{
            if(!checkAccessPermission(32))
            {
                system("clear");
                showAccessDeniedMessage();
                system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
                showMainMenueScreen();
            }
            else
                transactionMenueScreen();
            
            break;

        }

        case ManageUsers :{
            if(!checkAccessPermission(64))
            {
                system("clear");
                showAccessDeniedMessage();
                system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
                showMainMenueScreen();
            }
            else
                manageUsersMainMenue();
            break;
        }

        case Logout : {system("clear");
            logoutScreen();
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
    } while (choose<1&&choose>8);
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

bool checkAccessPermission(short permissionNumber)
{
    if(currentUser.permission==-1)
        return true;
    else if((permissionNumber&currentUser.permission) == permissionNumber)
        return true;
    else
        return false;
}

void showAccessDeniedMessage()
{
    cout << "------------------------------------" << endl;
    cout << "\tAccess Denied,\n";
    cout << "You Dont Have Permission To Do This,\n";
    cout << "Please Conact Your Admin.\n";
    cout << "------------------------------------" << endl << endl;
}

void showClientList(vector<stClient> vClients)
{system("clear");

    if(!checkAccessPermission(1))
    {
        showAccessDeniedMessage();
        system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
        return;

    }

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
    cout << "[6] Transactions." << endl;
    cout << "[7] Manage Users." << endl;
    cout << "[8] Logout." << endl;
    cout <<"=================================================\n";
    performOption((enMainMenueOption)readYourChoose("Choose what do you want to do? [1 to 8]? "));

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

void logoutScreen()
{
    login();
}

void transactionMenueScreen()
{
    system("clear");
    cout <<"=================================================\n";
    cout << "\t   Transactions Menue Screen\n";
    cout <<"=================================================\n";
    cout << "[1] Deposit" << endl;
    cout << "[2] Withdraw." << endl;
    cout << "[3] Total Balance." << endl;
    cout << "[4] Main Menue." << endl;
    cout <<"=================================================\n";
    performOptionTransactions((enTransactionMenueOption)readYourChoose("Choose what do you want to do? [1 to 4]? "));
}

void performOptionTransactions(enTransactionMenueOption choice)
{
    system("clear");
    switch(choice)
    {
        case Deposit :{
            depositScreen();
            depositOperations();
            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break; 
        }

        case Withdraw :{
            withdrawScreen();
            withdrawOperations();
            system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
            showMainMenueScreen();
            break; 
        }

        case TotalBalance :{
            vector<stClient> vClient = LoadClientDataFromFile();
            showTotalBalancedList(vClient);
            showMainMenueScreen();
            break; 
        }
        
        case MainMenue :{
            showMainMenueScreen();
            break; 
        }
    }
}

void depositScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "   Deposit Screen\n";
    cout << "----------------------------------------\n\n";
}

void updateBalance(stClient &client,string message)
{
    char areYouSure;
    int amount;
    cout << message;
    cin >> amount;
    client.accountBalance += amount;
    cout << "Are you sure you want perform this transaction? Y/N? ";
    cin >> areYouSure;
    if(toupper(areYouSure)!='Y')
    {
        system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
        showMainMenueScreen();
    }

}

void updateClientFromFileDeposit(stClient client)
{
    stClient client1;
    vector<stClient> vClient = LoadClientDataFromFile();
    if(findClientAccountNumber(vClient,client1,client.accountNumber));
        string line = convertRecordToLine(client1,"#//#");
    
    string updatedLine = convertRecordToLine(client,"#//#");

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

void depositOperations()
{
    string accountNumber = readAccountNumber("Please Enter AccountNumber? ");
    vector<stClient> vClient = LoadClientDataFromFile();
    stClient client;
    if(findClientAccountNumber(vClient,client,accountNumber))
    {cout << endl;
        printClientDetails(client); cout << endl;
        updateBalance(client,"Please enter deposit amount? ");
        updateClientFromFileDeposit(client);
                
    }
    else
    {
        cout << "Client With Account Number[" << accountNumber <<"] Is Not Found!" << endl << endl;    
    }
}

void withdrawScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "   Withdraw Screen\n";
    cout << "----------------------------------------\n\n";
}

void withdrawOperations()
{
    string accountNumber = readAccountNumber("Please Enter AccountNumber? ");
    vector<stClient> vClient = LoadClientDataFromFile();
    stClient client;
    if(findClientAccountNumber(vClient,client,accountNumber))
    {cout << endl;
        printClientDetails(client); cout << endl;
        updateBalanceW(client,"Please enter withdraw amount? ");
        updateClientFromFileDeposit(client);
                
    }
    else
    {
        cout << "Client With Account Number[" << accountNumber <<"] Is Not Found!" << endl << endl;    
    }

}

void updateBalanceW(stClient &client,string message)
{
    char areYouSure;
    int amount;
    do
    {
        cout << message;
        cin >> amount;
        if(amount>client.accountBalance)
            cout << "\nAmount Exceeds the balance, you can withdraw up to : " << client.accountBalance << endl;
        

    } while (amount>client.accountBalance);

    client.accountBalance += (amount*-1);
    cout << "\nAre you sure you want perform this transaction? Y/N? ";
    cin >> areYouSure;
    if(toupper(areYouSure)!='Y')
    {
        system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
        showMainMenueScreen();
    }

}

void showTotalBalancedList(vector<stClient> vClients)
{system("clear");
    cout << Tabs(7) << "  Balances List (" << vClients.size() << ") Client(s)." << endl;
    cout << Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
    cout << Tabs(2) << "Account Number" << Tabs(2)  << "|" << Tabs(3) << "Client Name" << Tabs(4) << "|   " <<  "Balance" << endl;
    cout << Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
    for(stClient &client : vClients)
    {
        printTotalBalancedList(client);
        cout << endl;
    }
    cout << Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
    double balance=0.0;
    for(stClient& c :vClients)
        balance+=c.accountBalance;
    cout << Tabs(13) << " Total Balances = " << balance << endl;
    system("read -n 1 -s -p \"Press any key to go back to Main Menue...\"");
}

void printTotalBalancedList(stClient client)
{
    cout << Tabs(2) << setw(8) << client.accountNumber << Tabs(2) << "|";
    cout << Tabs(3) << setw(16) << client.fullName << Tabs(3) << "|";
    cout << Tabs(1) <<  client.accountBalance << Tabs(1);
}


stUser convertLineToRecordUser(string line)
{
    vector<string> vUser = spiltString(line);
    stUser user;
    user.userName = vUser.at(0);
    user.password = vUser.at(1);
    user.permission = stoi(vUser.at(2));
    return user;

}

vector<stUser> LoadUserDataFromFile()
{
    stUser user;
    vector<stUser> vUser;
    fstream myFile;
    myFile.open(userFileName,ios::in);
    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            user = convertLineToRecordUser(line);
            vUser.push_back(user);
        }
        myFile.close();

    }
    return vUser;

}

bool isExist(stUser user)
{
    vector<stUser> vUser = LoadUserDataFromFile();
    for(stUser & u : vUser)
    { 
        if(u.userName==user.userName&&u.password==user.password)
            return true;
    }
    system("clear");
    loginScreen();
    cout << "Invalid Username/Password!" << endl;
    return false;
}

void loginScreen()
{
    cout << "----------------------------------------\n";
    cout << "\t\tLogin Screen\n";
    cout << "----------------------------------------\n";
}

stUser readUser()
{
    stUser user;
    do
    {
        cout << "Enter Username? ";
        getline(cin >> ws,user.userName);
        cout << "Enter Password? ";
        cin >> user.password;

    } while (!isExist(user));
    return user;
    
    
}

void login()
{
    
    loginScreen();
    stUser user = readUser();
    currentUserInfo(user);
    showMainMenueScreen();
    
}

void currentUserInfo(stUser user)
{
    currentUser.userName = user.userName;
    currentUser.password = user.password;
    vector<stUser> vUser = LoadUserDataFromFile();
    for(stUser &u : vUser)
    {
        if(u.userName==currentUser.userName)
            currentUser.permission = u.permission;
    }
}

void mangaeUsersMainMenueScreen()
{
    system("clear");
    cout <<"=================================================\n";
    cout << "\t   Manage Users Main Menue Screen\n";
    cout <<"=================================================\n";
    cout << "[1] List Users." << endl;
    cout << "[2] Add New User.\n";
    cout << "[3] Delete User.\n";
    cout << "[4] Update User.\n";
    cout << "[5] Find User.\n";
    cout << "[6] Main Menue." << endl;
    cout <<"=================================================\n";
    performOptionManageUsers((enManageUsersMainMenue)readYourChoose("Choose what do you want to do? [1 to 6]? "));
}

void manageUsersMainMenue()
{
    mangaeUsersMainMenueScreen();
}

void performOptionManageUsers(enManageUsersMainMenue choice)
{
    system("clear");
    switch(choice)
    {
        case ListUser :{system("clear");
            showUserList();
            manageUsersMainMenue();
            break;
        }

        case AddUser :{system("clear");
            addUser();
            break;
        }

        case DeleteUser :{system("clear");
            deleteUser();
            break;
        }   

        case UpdateUser :{system("clear");
            updateUser();
            break;
        }

        case FindUser :{system("clear");
            findUser();
            break;
        }

        case MainMenueS :{
            showMainMenueScreen();
            break;
        }
    }

}

void showUserList()
{
    stUser user;
    vector<stUser> vUser = LoadUserDataFromFile();
    cout << Tabs(4) << "  User List (" << vUser.size() << ") User(s)." << endl;
    cout << Tabs(1) << "_______________________________________________________________________________________\n\n";
    cout << Tabs(1) << "   User Name" << Tabs(2) << "|" << Tabs(1) << "Password" << Tabs(1) << "|" << Tabs(1) << "Permissions\n";
    cout << Tabs(1) << "_______________________________________________________________________________________\n\n";    for(stUser &user : vUser)
    {
        printUserRecord(user);
        cout << endl;
    }
    cout << Tabs(1) << "_______________________________________________________________________________________\n\n";
    system("read -n 1 -s -p \"Press any key to go back to Manage User Main Menue Screen...\"");
}

void printUserRecord(stUser user)
{
    cout << Tabs(1) << setw(8) << user.userName << Tabs(2) << "|";
    cout << Tabs(1) << setw(8) << user.password << Tabs(1) << "|";
    cout << Tabs(1) << setw(2) << user.permission << Tabs(1);
}

void addUser()
{
    addNewUserScreen();
    readNewUser();
}

void addNewUserScreen()
{
    cout << "----------------------------------------\n";
    cout << "\tAdd New User Screen\n";
    cout << "----------------------------------------\n";
}

void readNewUser()
{
    
    cout << "Adding New User:\n\n";
    stUser user;
    cout << "Enter Username? ";
    getline(cin >> ws,user.userName);
    if(!isExistUserName(user.userName))
    {
        readNewUserStep2(user);
    }
    else
    {
        do
        {
            cout << "User with [" << user.userName << "] already exists, Enter another Username? ";
            getline(cin >> ws,user.userName);
        } while (isExistUserName(user.userName));
        
        readNewUserStep2(user);
    }
    
    
}

bool isExistUserName(string userName)
{
    vector<stUser> vUser = LoadUserDataFromFile();
    for(stUser &u : vUser)
    {
        if(u.userName == userName)
            return true;
    }
    return false;
}

bool isExistUserName(string userName,stUser& user)
{
    vector<stUser> vUser = LoadUserDataFromFile();
    for(stUser &u : vUser)
    {
        if(u.userName == userName)
        {
            user = u;
            return true;
        }
    }
    return false;
}

string convertUserRecordToLine(stUser user,string seperator="#//#")
{
    string word="";
    word += user.userName + seperator + user.password + seperator + to_string(user.permission);
    return word;
}

void addUserToFile(string line)
{
    fstream myFile;
    myFile.open( userFileName,ios::out|ios::app );
    if(myFile.is_open())
    {
        myFile << line << endl;
    }
    myFile.close();
}

void readNewUserStep2(stUser &user)
{
    char access;
    cout << "Enter Password? ";
    cin >> user.password;
    cout << "\n";
    cout << "Do you want to give full access? y/n? ";
    cin >> access;

    if(toupper(access)=='Y')
    {
        user.permission = -1;
    }
    else
    {
        user.permission=0;
        cout << "\nDo you want to give access to :\n\n";
        giveAccess("Show Client List? y/n? ",user,0); 
        giveAccess("Add New Client? y/n? ",user,1); 
        giveAccess("Delete Client? y/n? ",user,2); 
        giveAccess("Update Client? y/n? ",user,3); 
        giveAccess("Find Client? y/n? ",user,4); 
        giveAccess("Transactions? y/n? ",user,5); 
        giveAccess("Manage Users? y/n? ",user,6);           

    }
    char more;
    string line = convertUserRecordToLine(user,"#//#");
    addUserToFile(line);
    cout << "\nUser Added Successfully, do you want to add more Users? y/n? ";
    cin >> more;
    if(toupper(more) == 'Y')
    {
        system("clear");
        addUser();
    }
    else
    {
        system("read -n 1 -s -p \"\nPress any key to go back to Manage User Main Menue Screen...\"");
        manageUsersMainMenue();
    }
}

void giveAccess(string message,stUser &user,short permissionNumber)
{
    char access;
    cout << message;
    cin >> access;
    cout << endl;
    if(toupper(access)=='Y')
    {
        user.permission += pow(2,permissionNumber);
    }
    
}

void deleteUser()
{
    deleteUserScreen();
    deleteUsername();
}

void deleteUserScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "Delete Users Screen\n";
    cout << "----------------------------------------\n\n";
}

void deleteUsername()
{
    stUser user;
    string userName;
    cout << "Please enter Username? ";
    getline(cin >> ws,userName);
    cout << endl;
    if(isExistUserName(userName,user))
    {
        string line = convertUserRecordToLine(user,"#//#");
        printUserDetails(user);
        if(sureAboutDeleteUser())
            deleteUserFromFile(line);
    }
    else
        cout << "User with Username (" << userName << ") is Not Found!\n";
    

    system("read -n 1 -s -p \"\nPress any key to go back to Manage User Main Menue Screen...\"");
    manageUsersMainMenue();


}

void printUserDetails(stUser user)
{
    cout << "The following are the user details:\n";
    cout << "-------------------------------------\n";
    cout << "Username   : " << user.userName << endl;
    cout << "Password   : " << user.password << endl;
    cout << "Permission : " << user.permission << endl;
    cout << "-------------------------------------\n\n";
}

bool sureAboutDeleteUser()
{
    char deleteU;
    cout << "Are you sure you want delete this user? Y/N? ";
    cin >> deleteU;
    if(toupper(deleteU) == 'Y')
    {
        cout << "\nUser Deleted Successfully." << endl << endl;
        return true;
    }
    return false;

}

void deleteUserFromFile(string line)
{
    fstream myFile;
    fstream temp;
    myFile.open(userFileName,ios::in);
    temp.open("temp.txt", ios::out|ios::app);
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
    }
    remove(userFileName.c_str());
    rename("temp.txt",userFileName.c_str());
}

void updateUser()
{
    updateUserScreen();
    stUser user;
    string userName;
    cout << "Please enter Username? ";
    getline(cin >> ws,userName);
    cout << endl;
    if(isExistUserName(userName,user))
    {
        string line = convertUserRecordToLine(user,"#//#");
        printUserDetails(user);
        if(sureAboutUpdateUser())
        {
            updateUserFromFile(line,user);
            cout << "\nUser Updatetd Successfully." << endl << endl;
        }
    }
    else
        cout << "User with Username (" << userName << ") is Not Found!\n";
    

    system("read -n 1 -s -p \"\nPress any key to go back to Manage User Main Menue Screen...\"");
    manageUsersMainMenue();
}

void updateUserScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "Update Users Screen\n";
    cout << "----------------------------------------\n\n";
}

bool sureAboutUpdateUser()
{
    char update;
    cout << "Are you sure you want update this user? Y/N? ";
    cin >> update;
    cout << endl;
    if(toupper(update) == 'Y')
    {
        return true;
    }
    return false;
}

void updateUserFromFile(string line,stUser user)
{
    updateUserFromStructure(user);
    string updatedLine = convertUserRecordToLine(user,"#//#");

    fstream myFile,temp;
    myFile.open(userFileName,ios::in);
    temp.open("temp.txt",ios::out);
    if(myFile.is_open()&&myFile.is_open())
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
    remove(userFileName.c_str());
    rename("temp.txt",userFileName.c_str());

}

void updateUserFromStructure(stUser &user)
{
    char access;
    cout << "Enter Password? ";
    cin >> user.password;
    cout << "\n";
    cout << "Do you want to give full access? y/n? ";
    cin >> access;

    if(toupper(access)=='Y')
    {
        user.permission = -1;
    }
    else
    {
        user.permission=0;
        cout << "\nDo you want to give access to :\n\n";
        giveAccess("Show Client List? y/n? ",user,0); 
        giveAccess("Add New Client? y/n? ",user,1); 
        giveAccess("Delete Client? y/n? ",user,2); 
        giveAccess("Update Client? y/n? ",user,3); 
        giveAccess("Find Client? y/n? ",user,4); 
        giveAccess("Transactions? y/n? ",user,5); 
        giveAccess("Manage Users? y/n? ",user,6);           

    }

}

void findUser()
{
    findUserScreen();
    stUser user;
    string userName;
    cout << "Please enter Username? ";
    getline(cin >> ws,userName);
    cout << endl;

    if(isExistUserName(userName,user))
        printUserDetails(user);
    
    else
        cout << "User with Username (" << userName << ") is Not Found!\n";
    

    system("read -n 1 -s -p \"\nPress any key to go back to Manage User Main Menue Screen...\"");
    manageUsersMainMenue();
    

}

void findUserScreen()
{
    cout << "----------------------------------------\n";
    cout << Tabs(1) << "Find Users Screen\n";
    cout << "----------------------------------------\n\n"; 
}


