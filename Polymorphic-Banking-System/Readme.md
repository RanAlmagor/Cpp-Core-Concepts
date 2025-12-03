

````markdown
# Polymorphic Banking System

![Language](https://img.shields.io/badge/language-Modern%20C++-blue.svg)
![Architecture](https://img.shields.io/badge/architecture-OOD%20%26%20Polymorphism-orange.svg)
![Safety](https://img.shields.io/badge/safety-Exception%20Handling-green.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

## 📖 Overview

This project is a comprehensive **Financial System Simulation** designed to demonstrate advanced Object-Oriented Design (OOD) in C++.

It models a banking environment with diverse account types, enforcing complex business rules via **Runtime Polymorphism**, while ensuring memory safety with **Smart Pointers** (RAII) and robust error handling with **Custom Exceptions**.

---

## 🏗️ System Architecture (UML)

The following diagram visualizes the inheritance hierarchy. Note that `Trust_Account` is a specialized version of `Savings_Account`, inheriting its interest logic while adding stricter regulations.

```mermaid
classDiagram
    direction BT
    %% Interface
    class I_Printable {
        <<Interface>>
        +print(ostream) void*
    }

    %% Abstract Base
    class Account {
        <<Abstract>>
        #string name
        #double balance
        +deposit(double)* bool
        +withdraw(double)* bool
        +virtual ~Account()
    }

    %% Concrete Classes
    class Checking_Account {
        -double fee
        +withdraw(double) bool
    }

    class Savings_Account {
        #double interest_rate
        +deposit(double) bool
    }

    class Trust_Account {
        -int withdrawals_left
        +deposit(double) bool
        +withdraw(double) bool
    }

    %% Exceptions
    class std_exception {
        <<Standard Lib>>
    }
    class IllegalBalanceException
    class InsufficientFundsException

    %% Relationships
    Account --|> I_Printable
    Checking_Account --|> Account
    Savings_Account --|> Account
    Trust_Account --|> Savings_Account

    IllegalBalanceException --|> std_exception
    InsufficientFundsException --|> std_exception

    %% Styling
    style Account fill:#2d3436,stroke:#fff,stroke-width:2px,color:#fff
    style Trust_Account fill:#0984e3,stroke:#333,color:#fff
    style Checking_Account fill:#00b894,stroke:#333,color:#fff
````

-----

## 🚀 Business Logic & Rules

### 1\. `Account` (Abstract Base)

  * **Role:** Defines the core contract (`deposit`, `withdraw`) for all accounts.
  * **Safety:** Prevents creation of accounts with negative balances via `IllegalBalanceException`.

### 2\. `Savings_Account`

  * **Base:** Inherits from `Account`.
  * **Logic:** Adds an **interest rate** (%) to every deposit.
  * **Calculation:** `Deposit Amount += (Amount * Interest_Rate / 100)`.

### 3\. `Checking_Account`

  * **Base:** Inherits from `Account`.
  * **Logic:** Applies a fixed **transaction fee** ($1.50) for every withdrawal.
  * **Mechanism:** Overrides `withdraw()` to deduct the fee automatically.

### 4\. `Trust_Account` (The "Power" Account)

  * **Base:** Inherits from `Savings_Account` (extends interest logic).
  * **Bonus Rule:** Deposits over **$5000** receive a **$50.00** bonus immediately.
  * **Restriction 1:** Maximum **3 withdrawals** allowed per year.
  * **Restriction 2:** Maximum withdrawal amount is capped at **20%** of the current balance.
  * **Safety:** Throws `InsufficientFundsException` if limits are breached.

-----

## 🛠️ Technical Concepts Demonstrated

### 🔹 Dynamic Polymorphism

The system utilizes **Virtual Functions** (`vtable`) to allow generic processing.

  * **Mechanism:** A `std::vector<std::unique_ptr<Account>>` holds mixed account types.
  * **Result:** Calling `acc->withdraw()` invokes the correct derived method at runtime based on the actual object type.

### 🔹 Interface Segregation

The `I_Printable` interface (Pure Abstract Class) decouples the printing logic from the account logic.

  * **Benefit:** Enables `std::cout << *account` for any account type seamlessly via a single friend operator.

### 🔹 Modern Memory Management (RAII)

  * **Smart Pointers:** Usage of `std::unique_ptr` ensures zero memory leaks.
  * **No `new`/`delete`:** Manual memory management is replaced by factory functions (`std::make_unique`).

### 🔹 Exception Safety

Custom exceptions ensure the system fails gracefully and provides meaningful error messages rather than undefined behavior.

-----

## 📂 Project Structure

```text
Polymorphic-Banking-System/
├── Account.h / .cpp                // Abstract Base Class
├── Savings_Account.h / .cpp        // Derived Class
├── Checking_Account.h / .cpp       // Derived Class
├── Trust_Account.h / .cpp          // Derived from Savings
├── I_Printable.h / .cpp            // Interface
├── IllegalBalanceException.h       // Custom Exception
├── InsufficientFundsException.h    // Custom Exception
└── main.cpp                        // Driver Code (Polymorphic Vector)
```

-----

## 💻 Usage Example

```cpp
try {
    // 1. Create a polymorphic container
    std::vector<std::unique_ptr<Account>> accounts;

    // 2. Inject different account types
    accounts.push_back(std::make_unique<Checking_Account>("Ran", 2000));
    accounts.push_back(std::make_unique<Trust_Account>("Boss", 10000, 5.0));

    // 3. Polymorphic iteration
    for (const auto &acc : accounts) {
        acc->withdraw(500); // Dynamically calls the correct withdraw logic!
        std::cout << *acc << std::endl; // Uses I_Printable interface
    }
}
catch (const std::exception &ex) {
    std::cerr << "Transaction Failed: " << ex.what() << std::endl;
}
```

-----

## 👨‍💻 Author

**Ran Almagor**
*Computer Science Graduate & C++ Developer*

```
