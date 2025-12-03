# Cpp-Core-Concepts

![Language](https://img.shields.io/badge/language-Modern%20C++-blue.svg)
![Status](https://img.shields.io/badge/status-active-success.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## 📖 Overview

This repository serves as a master portfolio of my journey through **Modern C++ Engineering**.
It contains a collection of focused projects, each designed to master specific pillars of the language, ranging from low-level memory mechanics to high-level object-oriented architecture.

**Key Focus Areas:**
* **Object-Oriented Design (OOD)** & Polymorphism.
* **Low-Level Memory Management** (RAII, Pointers, Stack vs Heap).
* **Operator Overloading** & API Design.
* **STL** (Standard Template Library) usage.

---

## 📂 Project Catalog

### 1️⃣ `movie-library`
> **Focus:** Class Basics, Encapsulation & Data Structures

A console-based application designed to manage a personal movie collection. This project establishes the foundations of class design.
* **Key Concepts:** Classes, Objects, Access Modifiers, `std::vector` management.
* **Architecture:** Clean separation of concerns using Header (`.h`) and Source (`.cpp`) files.

> 📂 Folder: `movie-library/`

---

### 2️⃣ `My-String-Operator-Overloading`
> **Focus:** Advanced Memory Management (RAII) & Operator Overloading

A comprehensive, high-performance implementation of a custom String class. This project demonstrates deep understanding of how C++ manages resources "under the hood."

**Architectural Approaches:**
This project explores two different design patterns for operator overloading:
* **V1 (Member Functions):** Standard OOP implementation using `this`.
* **V2 (Global Functions):** Symmetric operator design using `friend` functions for seamless interoperability.

**Core Mechanics Implemented:**
* **Rule of Five:** Copy/Move Constructors & Assignment Operators.
* **Move Semantics:** Efficient resource transfer (r-value references) to prevent unnecessary copying.
* **Deep Copying:** Safe manual heap allocation (`new[]`/`delete[]`).
* **Full Operator Suite:** Arithmetic (`+`, `+=`), Comparison (`==`, `<`), Stream I/O (`<<`, `>>`), and Access (`[]`).

> 📂 Folder: `My-String-Operator-Overloading/`

---

### 3️⃣ `Polymorphic-Banking-System`
> **Focus:** Inheritance, Polymorphism & Complex Business Logic

A scalable financial system simulation designed to manage a hierarchy of bank accounts with varying business rules and behaviors.

**System Architecture:**
* **Inheritance Hierarchy:** A base `Account` class derived into specialized types:
    * **`Savings_Account`:** Implements interest rate logic for deposits.
    * **`Checking_Account`:** Implements transaction fee logic for withdrawals.
    * **`Trust_Account`:** Complex logic including bonus structures and strict withdrawal limits (max 3 per year, max 20% of balance).
* **Polymorphism:** Utilizing `virtual` functions and dynamic binding to manage generic account collections.
* **Design Patterns:** Usage of helper functions to manage account operations uniformly across the hierarchy.

> 📂 Folder: `Polymorphic-Banking-System/`

---

## 🧠 Roadmap & Mastery Goals

This portfolio documents a structured progression from syntax to architecture:

1.  **Basics:** Understanding objects, scope, and containers (`movie-library`).
2.  **The "Guts":** Mastering pointers, references, memory layout, and RAII (`My-String`).
3.  **Architecture:** Building scalable, extensible systems using Inheritance and Polymorphism (`Banking-System`).

---

## 👨‍💻 Author
**Ran Almagor**
*C++ Developer*