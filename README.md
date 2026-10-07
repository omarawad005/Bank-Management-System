# 🏦 Bank Management System

A **console-based Bank Management System** built with **C++** as a practical project for applying structured programming concepts, file handling, client management, CRUD operations, and basic transaction processing.

The application simulates a simple banking environment where users can manage client accounts, perform deposits and withdrawals, and persist client data using a text file.

---

## 📌 About the Project

The **Bank Management System** is a menu-driven C++ application designed to simulate the core operations of a simple banking system.

The system allows users to:

* Manage bank clients
* Add, update, delete, and search for clients
* Perform deposits and withdrawals
* Display client account balances
* Calculate the total balance across all accounts
* Store and retrieve client data from a text file
* Validate user input and transaction amounts

Client data is represented using a custom `struct`, while `enum` types are used to organize menu and transaction states.

---

## ✨ Features

### 👤 Client Management

* Display all clients
* Add new clients
* Prevent duplicate account numbers
* Update client information
* Delete clients
* Search for clients by account number

### 💰 Transactions

* Deposit money
* Withdraw money
* Validate transaction amounts
* Prevent withdrawals exceeding the available balance
* Confirm transactions before execution
* Display the updated account balance

### 📊 Balance Management

* Display individual client balances
* Calculate the total balance of all clients

### 💾 Data Persistence

* Load client data from a text file
* Save changes back to the file
* Convert client records into text lines
* Convert text lines back into client records

---

## 🖥️ Main Menu

```text
=============================================
              Main Menu
=============================================
        [1] Show Clients List
        [2] Add New Client
        [3] Delete Client
        [4] Update Client
        [5] Find Client
        [6] Transactions
        [7] Exit
=============================================
```

---

## 💳 Transactions Menu

```text
==================================================
              Transactions Menu
==================================================
        [1] Deposit
        [2] Withdraw
        [3] Total Balances
        [4] Main Menu
==================================================
```

The transactions menu provides the main financial operations of the system.

---

## 👤 Client Information

Each client is represented using the `stClient` structure:

| Field           | Description                              |
| --------------- | ---------------------------------------- |
| Account Number  | Unique identifier for the client account |
| PIN Code        | Client PIN                               |
| Name            | Client name                              |
| Phone           | Client phone number                      |
| Account Balance | Current account balance                  |

---

## 💾 File Storage

The application uses a text file named:

```text
File.txt
```

Client records are stored using the following separator:

```text
#//#
```

### Example

```text
A1001#//#1234#//#Omar Awad#//#01000000000#//#5000
```

The application includes functions responsible for converting client records to text lines and converting stored text lines back into client records.

---

## 💰 Transaction Logic

### Deposit

The deposit process follows these steps:

1. Enter the client account number.
2. Search for the client.
3. Enter the transaction amount.
4. Validate the amount.
5. Confirm the transaction.
6. Add the amount to the account balance.
7. Save the updated data to the file.

### Withdraw

The withdrawal process follows the same general flow, with an additional balance check to ensure that the requested amount does not exceed the available balance.

Example:

```text
Enter Amount to Transaction: 500

Are you sure you want to perform this Withdraw? y/n ?
```

---

## 📊 Total Balances

The system can display the balances of all clients and calculate the total balance across all accounts.

Example:

```text
| Account Number | Client Name | Balance |
|----------------|-------------|---------|
| A1001          | Omar Awad   | 5000    |
| A1002          | Ahmed Ali   | 7500    |

Total Balance = 12500
```

The total balance is calculated by iterating through the client records and summing their account balances.

---

## 🛡️ Input Validation

The application handles invalid numeric input using standard C++ stream functions:

* `cin.fail()`
* `cin.clear()`
* `cin.ignore()`
* `numeric_limits<streamsize>`

Transaction amounts are also validated to ensure they are greater than zero.

---

## 🛠️ Technologies

* **C++**
* `iostream`
* `fstream`
* `string`
* `vector`
* `iomanip`
* `limits`

---

## 🧠 Concepts Practiced

This project demonstrates practical use of:

* Structures (`struct`)
* Enumerations (`enum`)
* Functions
* Vectors
* References
* File I/O
* String manipulation
* Searching
* CRUD operations
* Input validation
* Data conversion
* Menu-driven applications
* Basic transaction processing

---

## 📂 Project Structure

```text
Bank-Management-System/
│
├── .gitignore
├── Project_1_My_Solution.sln
│
└── Project_1_My_Solution/
    │
    ├── Project_1_My_Solution.cpp
    ├── Project_1_My_Solution.vcxproj
    └── Project_1_My_Solution.vcxproj.filters
```

---

## 🚀 How to Run

### Using Visual Studio

1. Clone the repository.
2. Open `Project_1_My_Solution.sln` in Visual Studio.
3. Build the solution.
4. Run the application.
5. Use the console menu to manage clients and perform transactions.

The application uses `File.txt` for local client data storage.

> **Note:** This project is intended for educational purposes only. Do not use real banking information, account numbers, or PIN codes.

---

## 📚 What I Practiced

Building this project helped strengthen my understanding of:

* Designing a complete console-based application
* Breaking a large problem into reusable functions
* Managing structured data using `struct`
* Using `enum` for menu and transaction states
* Working with vectors of custom structures
* Reading and writing files
* Converting records between objects and strings
* Implementing CRUD operations
* Searching and updating records
* Processing deposits and withdrawals
* Validating user input
* Implementing transaction rules
* Calculating aggregate data
* Building multi-level console menus

---

## 🔮 Future Improvements

Possible improvements for future versions include:

* [ ] Add user authentication and login
* [ ] Hide PIN input
* [ ] Add transaction history
* [ ] Add transfers between accounts
* [ ] Add account creation dates
* [ ] Add transaction timestamps
* [ ] Improve error handling
* [ ] Separate the project into header and source files
* [ ] Replace text-file storage with a database
* [ ] Add a graphical user interface
* [ ] Improve security and data protection

---

## 👨‍💻 Author

**Omar Awad**

GitHub: [@omarawad005](https://github.com/omarawad005)

---

> ⚠️ **Educational Project**
>
> This project is a learning exercise and is **not intended for real-world banking or financial use**.
