# Cpp-Core-Concepts

![Language](https://img.shields.io/badge/language-Modern%20C++-blue.svg)
![Status](https://img.shields.io/badge/status-active-success.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## 📖 Overview

This repository serves as a portfolio of my journey through **Modern C++ engineering**.  
It contains a collection of focused projects, each designed to deepen mastery of different pillars of the language – from low-level memory mechanics to high-level object-oriented architecture.

**Key Focus Areas:**
- **Object-Oriented Design (OOD)** & polymorphism  
- **Low-Level Memory Management** (RAII, pointers, stack vs heap)  
- **Operator Overloading** & API design  
- **STL** (Standard Template Library) usage  

---

## 📂 Project Catalog

### 1️⃣ `movie-library`  
> **Focus:** Class Basics, Encapsulation & Data Structures

A console-based application designed to manage a personal movie collection.  
This project establishes the foundations of class design and working with containers.

- **Key Concepts:** Classes, objects, access modifiers, `std::vector` management  
- **Architecture:** Clean separation of concerns using header (`.h`) and source (`.cpp`) files  

> 📂 Folder: `movie-library/`

---

### 2️⃣ `My-String-Operator-Overloading`  
> **Focus:** Advanced Memory Management (RAII) & Operator Overloading

A custom string implementation built from scratch to explore how C++ manages resources “under the hood”.

**Architectural Variants:**
This project explores two different design approaches for operator overloading:

- **V1 – Member Functions**  
  Standard OOP design using member operators and `this`.

- **V2 – Global / Friend Functions**  
  Symmetric operator design implemented as non-member functions with `friend` access.

**Core Mechanics Implemented:**

- **Rule of Five:**  
  Custom copy/move constructors and copy/move assignment operators, plus destructor.
- **Move Semantics:**  
  Efficient resource transfer with rvalue references to avoid unnecessary copies.
- **Deep Copying:**  
  Manual heap management with `new[]` / `delete[]`, no `std::string` used internally.
- **Operator Suite:**  
  Concatenation (`+`, `+=`), comparison (`==`, `<`, `!=`, `>`), stream I/O (`<<`, `>>`), access (`[]`), and additional transformations (e.g. case changes).

> 📂 Folder: `My-String-Operator-Overloading/`  
> – `V1/` → member-based implementation  
> – `V2/` → global/friend-based implementation  

---

### 3️⃣ `Polymorphic-Banking-System`  
> **Focus:** Inheritance, Polymorphism & Business Logic

A small banking system designed to model different types of bank accounts and their behavior.

**Current architecture:**

- **Base class:**  
  `Account` – holds a name and balance, provides `deposit`/`withdraw` with boolean success flags and stream output (`operator<<`).

- **Derived class (current stage):**  
  `Savings_Account` – extends `Account` with an interest rate and a specialized `deposit` that applies interest before delegating to `Account::deposit`.

- **Utility layer:**  
  Free helper functions (in `account_util`) that operate on collections of accounts:
  - `display(accounts)`, `deposit(accounts, amount)`, `withdraw(accounts, amount)`  
  - Overloaded both for `std::vector<Account>` and `std::vector<Savings_Account>`

**Planned extensions (next phases):**

- `Checking_Account` – transaction fee logic  
- `Trust_Account` – bonus rules and stricter withdrawal limits (e.g. max 3 withdrawals, max 20% of balance each)

These steps will introduce true runtime **polymorphism** using `virtual` functions and dynamic binding over a hierarchy of account types.

> 📂 Folder: `Polymorphic-Banking-System/`

---

## 🧠 Roadmap & Mastery Goals

This portfolio documents a structured progression from syntax to architecture:

1. **Basics** – Understanding objects, scope, and containers  
   → `movie-library`

2. **The “Guts”** – Mastering pointers, references, memory layout, and RAII  
   → `My-String-Operator-Overloading`

3. **Architecture** – Building scalable, extensible systems using inheritance and polymorphism  
   → `Polymorphic-Banking-System`

---

## 👨‍💻 Author

**Ran Almagor**  
*C++ Developer *
