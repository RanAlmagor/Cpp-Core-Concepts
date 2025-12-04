# 🌟 Polymorphic Banking System

![Language](https://img.shields.io/badge/language-Modern%20C%2B%2B-blue.svg)
![Architecture](https://img.shields.io/badge/architecture-OOD%20%26%20Polymorphism-orange.svg)
![Safety](https://img.shields.io/badge/safety-Exception%20Handling-green.svg)
![Memory](https://img.shields.io/badge/memory-RAII%20%7C%20Smart%20Pointers-9cf.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

> A robust **financial system** in modern C++ simulating a banking environment. It features **runtime polymorphism**, a clean **Printable** interface, **RAII** memory management using `std::unique_ptr`, and a comprehensive **Exception Handling** system replacing legacy error codes.

---

## 🧭 Overview

This repository models a banking domain with strict business rules. The design favors **safety** and **predictability**:
- **Abstract Base Class:** `Account` defines the contract with pure-virtual `deposit`/`withdraw` methods returning `void` (failures throw exceptions).
- **Interface Segregation:** `I_Printable` allows uniform object streaming via `operator<<`.
- **Robust Error Handling:** Custom exceptions derived from `std::exception` (e.g., `IllegalAmount`, `InsufficientFunds`, `IllegalName`).
- **Modern Memory Management:** Full usage of `std::unique_ptr` and `std::make_unique` to prevent memory leaks.

---

## 🏗️ System Architecture (UML)

The diagram illustrates the inheritance hierarchy and the dependency on custom exceptions. Note that transaction methods return `void` and rely on the stack unwinding mechanism for error reporting.

```mermaid
classDiagram
    direction TB

    %% --- Core Abstractions ---
    class I_Printable {
        <<Interface>>
        +print(ostream) void*
    }

    class Account {
        <<Abstract Base>>
        #string name
        #double balance
        +deposit(double) void
        +withdraw(double) void
        +virtual ~Account()
    }

    %% --- Concrete Implementations ---
    class Checking_Account {
        -double fee
        +withdraw(double) void
    }

    class Savings_Account {
        #double interest_rate
        +deposit(double) void
    }

    class Trust_Account {
        <<Specialized>>
        -int num_withdrawals
        -int max_withdrawals
        +deposit(double) void
        +withdraw(double) void
    }

    %% --- Exception Handling ---
    class IllegalBalanceException { <<Exception>> }
    class InsufficientFundsException { <<Exception>> }
    class IllegalAmountException { <<Exception>> }
    class IllegalNameException { <<Exception>> }

    %% --- Relationships ---
    I_Printable <|.. Account : Implements
    Account <|-- Checking_Account
    Account <|-- Savings_Account
    Savings_Account <|-- Trust_Account : Extends

    %% --- Dependencies (Who throws what?) ---
    Account ..> IllegalBalanceException : Throws (Ctor)
    Account ..> IllegalNameException : Throws (Ctor)
    Account ..> IllegalAmountException : Throws (Validation)
    Account ..> InsufficientFundsException : Throws (Logic)
    Trust_Account ..> InsufficientFundsException : Throws (Limits)
    Trust_Account ..> IllegalAmountException : Throws (20% Rule)

    %% --- Styling ---
    style I_Printable fill:#2d3436,stroke:#b2bec3,stroke-width:2px,color:#fff
    style Account fill:#2d3436,stroke:#b2bec3,stroke-width:2px,color:#fff
    style Checking_Account fill:#00b894,stroke:#006266,color:#fff
    style Savings_Account fill:#00b894,stroke:#006266,color:#fff
    style Trust_Account fill:#0984e3,stroke:#2980b9,stroke-width:2px,color:#fff
    
    %% Red styling for Exceptions
    style IllegalBalanceException fill:#d63031,stroke:#c0392b,color:#fff,stroke-dasharray: 5 5
    style InsufficientFundsException fill:#d63031,stroke:#c0392b,color:#fff,stroke-dasharray: 5 5
    style IllegalAmountException fill:#d63031,stroke:#c0392b,color:#fff,stroke-dasharray: 5 5
    style IllegalNameException fill:#d63031,stroke:#c0392b,color:#fff,stroke-dasharray: 5 5