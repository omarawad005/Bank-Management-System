#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

//==========================
// Constants & Declarations
//==========================
const string ClientsFileName = "File.txt";

void ShowMainMenueOption();
void ShowTransactionsMenue();


// Validate numeric input from user
double ValidatedNumber()
{
    double Number = 0;
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Number ? Please enter Amount : ";
        cin >> Number;
    }

    return Number;
}

// Client structure
struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
    bool MarkForDelete = false;
};

// Menu options enumerations
enum enMainMenueOption
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eTransactions = 6,
    eExit = 7
};
enum enTransactionsMenueOption
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalances = 3,
    eMainMenue = 4
};
enum enTransactionType
{
    Deposit = 1,
    Withdraw = 2
};

//==========================
// String Utilities
//==========================

// Split a string by a delimiter into a vector of strings
vector<string> SplitString(string Line, string Delim)
{
    vector<string> vString;
    size_t pos = 0;
    string sWord = "";

    while ((pos = Line.find(Delim)) != string::npos)
    {
        sWord = Line.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        Line.erase(0, pos + Delim.length());
    }
    if (Line != "")
    {
        vString.push_back(Line);
    }

    return vString;
}
// Convert a line from file into a client record
stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    if (vClientData.size() < 5)
        return Client;

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}
// Convert a client record to a string line for file
string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}


//==========================
// File Functions
//==========================

// Add a line to a file
void AddDataLineToFile(string Line, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << Line << endl;
        MyFile.close();
    }
}
// Save all clients data to file
vector<stClient> SaveClientsDataToFile(string FileName, vector<stClient>& vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            if (!C.MarkForDelete)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }

    return vClients;
}
// Load all clients data from file
vector<stClient> LoadClientsDataFromFile(string FileName)
{
    stClient Clients;
    vector<stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line = "";
        while (getline(MyFile, Line))
        {
            Clients = ConvertLineToRecord(Line, "#//#");
            vClients.push_back(Clients);
        }
        MyFile.close();
    }
    return vClients;
}

//==========================
// Print Functions
//==========================
// Print client record in a single line (table format)
void PrintClientRecordLine(stClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}
// Print full client data details
void PrintClientData(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}
// Print client Balance details
void PrintClientsBalance(stClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}


//==========================
// Client Existence & Input
//==========================
// Check if a client exists by account number
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    fstream Myfile;
    Myfile.open(FileName, ios::in);
    if (Myfile.is_open())
    {
        string Line;
        stClient Client;
        while (getline(Myfile, Line))
        {
            Client = ConvertLineToRecord(Line, "#//#");
            if (Client.AccountNumber == AccountNumber)
            {
                Myfile.close();
                return true;
            }
        }
        Myfile.close();
    }
    return false;
}
// Read a new client info from user input
stClient ReadNewClient()
{
    stClient Client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "Client with [" << Client.AccountNumber;
        cout << "] already exists, Enter another Account Number?";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode?";
    getline(cin, Client.PinCode);

    cout << "Enter Name ? ";
    getline(cin, Client.Name);

    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Client;
}

//==========================
// Add New Clients
//==========================
void AddNewClient()
{
    stClient Client = ReadNewClient();
    AddDataLineToFile(ConvertRecordToLine(Client, "#//#"), ClientsFileName);
}
void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        cout << "\nAdding New Client: \n";
        AddNewClient();
        cout << "Client Added Successfully, do you want to add more clients? Y/N?";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

//===========================================
// Find & Delete & Update Clients 
//===========================================
string ReadAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber ? ";
    cin >> AccountNumber;
    return AccountNumber;
}
stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Client;
}
bool FindClientByAccountNumber(string AccountNumber, vector<stClient>& vClients, stClient& Client)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientData(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    return false;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientData(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    return false;
}

//==========================
// Show Screens for CRUD
//==========================
void ShowClientList()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.empty())
        cout << "\t\t\tNo Clients Available In The System!";
    else
    {
        for (stClient& Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}
void ShowAddNewClientsScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n----------------------------------------\n";
    AddNewClients();
}
void ShowDeleteClientScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tDelete Clients Screen";
    cout << "\n----------------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}
void ShowUpdateClientScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tUpdate Clients Screen";
    cout << "\n----------------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}
void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    stClient Client;
    string AccountNumber = ReadAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientData(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}
void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}


//==========================
// Transactions
//==========================
double AskForAmount()
{
    double Amount = 0;
    do
    {
        cout << "\n\nEnter Amount to Transaction: ";
        Amount = ValidatedNumber();

        if (Amount <= 0)
            cout << "Amount must be greater than 0. Try again.\n";
    } while (Amount <= 0);

    return Amount;
}
bool AskForConfirmTransaction(enTransactionType TransactionType)
{
    char Answer;

    string TransactionName = (TransactionType == Deposit) ? "Deposit" : "Withdraw";

    cout << "\nAre you sure you want to perform this " << TransactionName << "? y/n ? ";
    cin >> Answer;

    return toupper(Answer) == 'Y';
}

stClient UpdateClientBalance(string AccountNumber, double Amount, vector<stClient>& vClients)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.AccountBalance += Amount;
            return C;
        }
    }
    return stClient();
}

// Perform Deposit or Withdraw transaction
bool PerformTransaction(string AccountNumber, vector<stClient>& vClients, enTransactionType TransactionType)
{
    stClient Client;

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.";
        cout << "\n\nPlease enter AccountNumber ? ";
        cin >> AccountNumber;
    }

    PrintClientData(Client);

    double Amount;
    do
    {
        Amount = AskForAmount();

        if (TransactionType == Withdraw && Amount > Client.AccountBalance)
            cout << "Not enough balance, enter another amount.\n";

    } while (TransactionType == Withdraw && Client.AccountBalance < Amount);

    if (AskForConfirmTransaction(TransactionType))
    {
        if (TransactionType == Deposit)
        {
            Client = UpdateClientBalance(AccountNumber, Amount, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\nDeposit Successful! New Balance Is : " << Client.AccountBalance;
            return true;
        }
        else if (TransactionType == Withdraw)
        {
            Client = UpdateClientBalance(AccountNumber, -Amount, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\nWithdraw Successful! New Balance Is : " << Client.AccountBalance;
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

double SumAllClientsBalance(vector <stClient>& vClients)
{
    double sum = 0;
    for (stClient &C : vClients)
    {
        sum += C.AccountBalance;
    }
    return sum;
}

//================================
// Show Screens for TransAction
//================================
void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    string AccountNumber = ReadAccountNumber();

    PerformTransaction(AccountNumber, vClients, enTransactionType::Deposit);
}
void ShowWithdrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    PerformTransaction(AccountNumber, vClients, enTransactionType::Withdraw);
}
void ShowTotaleBalance()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.empty())
        cout << "\t\t\tNo Clients Available In The System!";
    else
    {
        for (stClient& Client : vClients)
        {
            PrintClientsBalance(Client);
               
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    double TotaleBalance = SumAllClientsBalance(vClients);
    cout << "\t\t\t\tTotal Balance = " << TotaleBalance << endl;
}

//==========================
// Navigation Helpers
//==========================
void GoBackToMainMenue()
{
    cout << "\n\nPlease enter any key to Back Main Menue...";
    system("pause > 0");
    ShowMainMenueOption();
}
void GoBackToTransactionsMenue()
{
    cout << "\n\nPlease enter any key to Back Transaction Menue...";
    system("pause > 0");
    ShowTransactionsMenue();
}

//==========================
// Menu Options Input
//==========================
short ReadMainMenueOption()
{
    short Choice = 0;

    do
    {
        cout << "Choose what do you want to do [1 to 7] ? ";
        cin >> Choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[Error!!!] Please Choose what do you want to do [1 to 7] ? ";
            cin >> Choice;
        }

    } while (Choice > 7 || Choice < 1);

    return Choice;
}
short ReadTransactionsMenue()
{
    short Choice = 0;

    do
    {
        cout << "Choose what do you want to do [1 to 4] ? ";
        cin >> Choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[Error!!!] Please Choose what do you want to do [1 to 6] ? ";
            cin >> Choice;
        }

    } while (Choice > 4 || Choice < 1);

    return Choice;
}

//==========================
// Perform Menu Actions
//==========================
void PerFormManiMenueOption(enMainMenueOption MainMenueOption)
{
    switch (MainMenueOption)
    {
    case eListClients:
        system("cls");
        ShowClientList();
        GoBackToMainMenue();
        break;
    case eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;
    case eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    case eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;
    case eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    case eTransactions:
        system("cls");
        ShowTransactionsMenue();
        break;
    case eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}
void PerformTransactionsMenue(enTransactionsMenueOption Option)
{
    switch (Option)
    {
    case eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    case eWithdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionsMenue();
        break;
    case eTotalBalances:
        system("cls");
        ShowTotaleBalance();
        GoBackToTransactionsMenue();
        break;
    case eMainMenue:
        ShowMainMenueOption();
        break;
    }
}

//==========================
// Show Menues
//==========================
void ShowMainMenueOption()
{
    system("cls");
    cout << "=============================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "=============================================\n";
    cout << "\t[1] Show Clients Lists. \n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit\n";
    cout << "=============================================\n";
    PerFormManiMenueOption(enMainMenueOption(ReadMainMenueOption()));
}
void ShowTransactionsMenue()
{
    system("cls");
    cout << "\n==================================================\n";
    cout << "\tTransactions Menue Screen";
    cout << "\n==================================================\n";
    cout << "\t[1] Deposit. \n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Totale Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "==================================================\n";
    PerformTransactionsMenue((enTransactionsMenueOption)ReadTransactionsMenue());
}

int main()
{
    ShowMainMenueOption();
    system("pause > 0");
}
