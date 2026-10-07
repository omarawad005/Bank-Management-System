\# 🏦 Bank Management System



A console-based \*\*Bank Management System\*\* built with \*\*C++\*\*.



This project provides a simple banking environment where users can manage client accounts, perform CRUD operations, and execute basic financial transactions such as deposits and withdrawals.



The project focuses on practicing \*\*C++ fundamentals, functions, structures, vectors, file handling, enums, input validation, and modular programming\*\*.



\---



\## 📌 Features



\### 👤 Client Management



\* Display all clients

\* Add new clients

\* Delete existing clients

\* Update client information

\* Search for a client by account number

\* Prevent duplicate account numbers



\### 💰 Transactions



\* Deposit money into an account

\* Withdraw money from an account

\* Prevent withdrawals greater than the available balance

\* Display the balance of all clients

\* Calculate the total balance across all accounts



\### 💾 File Handling



\* Store client information in a text file

\* Load client data when needed

\* Automatically save changes after update, delete, deposit, and withdrawal operations

\* Use a custom delimiter (`#//#`) to separate client fields



\---



\## 🛠️ Technologies \& Concepts



\* \*\*C++\*\*

\* Structures (`struct`)

\* Enumerations (`enum`)

\* Functions

\* Vectors (`vector`)

\* Strings

\* File Handling (`fstream`)

\* Input Validation

\* `iomanip` for formatted output

\* CRUD Operations

\* Pass by Reference

\* Basic modular programming



\---



\## 📂 Data Storage



Client data is stored locally in:



```text

File.txt

```



Each client is stored as one line using the following format:



```text

AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance

```



\### Example



```text

A100#//#1234#//#Omar Awad#//#01000000000#//#5000

```



\---



\## 📋 Main Menu



When the program starts, the following menu is displayed:



```text

=============================================

&#x20;       Main Menue Screen

=============================================

&#x20;   \[1] Show Clients Lists.

&#x20;   \[2] Add New Client.

&#x20;   \[3] Delete Client.

&#x20;   \[4] Update Client.

&#x20;   \[5] Find Client.

&#x20;   \[6] Transactions.

&#x20;   \[7] Exit

=============================================

```



\---



\## 💳 Transactions Menu



The transactions section provides:



```text

==================================================

&#x20;       Transactions Menue Screen

==================================================

&#x20;   \[1] Deposit.

&#x20;   \[2] Withdraw.

&#x20;   \[3] Totale Balances.

&#x20;   \[4] Main Menue.

==================================================

```



\### Deposit



Adds a specified amount to the client's account balance.



\### Withdraw



Subtracts a specified amount from the client's account balance.



The program checks that the withdrawal amount does not exceed the client's available balance.



\### Total Balances



Displays all client balances and calculates the total balance of all accounts.



\---



\## 🔄 CRUD Operations



The project implements the four fundamental data operations:



| Operation  | Description                        |

| ---------- | ---------------------------------- |

| \*\*Create\*\* | Add a new client                   |

| \*\*Read\*\*   | Display and search for clients     |

| \*\*Update\*\* | Modify existing client information |

| \*\*Delete\*\* | Remove a client from the data file |



\---



\## 🧱 Client Structure



Each client is represented using a C++ `struct` containing:



```cpp

struct stClient

{

&#x20;   string AccountNumber;

&#x20;   string PinCode;

&#x20;   string Name;

&#x20;   string Phone;

&#x20;   double AccountBalance;

&#x20;   bool MarkForDelete;

};

```



The `MarkForDelete` flag is used during the delete operation before the updated data is written back to the file.



\---



\## ▶️ How to Run



\### 1. Clone the repository



```bash

git clone <repository-url>

```



\### 2. Open the project



Open the project using a C++ IDE such as:



\* Visual Studio

\* Visual Studio Code

\* Code::Blocks

\* CLion



\### 3. Build and run



Compile and run the program.



The application will create/use:



```text

File.txt

```



to store client information.



\---



\## 🎯 Project Purpose



This project was created as a practical exercise to strengthen understanding of:



\* Working with files in C++

\* Managing data using vectors

\* Using structures to represent real-world entities

\* Building menu-driven console applications

\* Implementing CRUD operations

\* Handling user input and validation

\* Separating a large program into reusable functions

\* Implementing simple banking transactions



\---



\## 📸 Project Preview



\### Main Menu



```text

\[1] Show Clients Lists

\[2] Add New Client

\[3] Delete Client

\[4] Update Client

\[5] Find Client

\[6] Transactions

\[7] Exit

```



\### Transactions



```text

\[1] Deposit

\[2] Withdraw

\[3] Total Balances

\[4] Main Menu

```



\---



\## 🚀 Future Improvements



Possible improvements for future versions:



\* Add stronger input validation

\* Improve error handling for invalid file data

\* Add authentication/login functionality

\* Add transaction history

\* Add transfer between accounts

\* Improve the console user interface

\* Separate the project into multiple `.cpp` and `.h` files

\* Replace text-file storage with a database



\---



\## 👨‍💻 Author



\*\*Omar Awad\*\*



A practical C++ project focused on strengthening programming fundamentals and building real-world console applications.



