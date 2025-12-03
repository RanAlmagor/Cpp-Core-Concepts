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
* **Smart Pointers** & Modern Syntax (C++14/17).
* **Operator Overloading** & API Design.

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
> **Focus:** Low-Level Memory Management (RAII) & Operator Overloading

A comprehensive implementation of a custom String class, built from scratch to demonstrate mastery of raw pointers and manual memory handling.

**Core Mechanics:**
* **Rule of Five:** Manual implementation of Copy/Move Constructors & Assignment Operators.
* **Deep Copying:** Safe manual heap allocation (`new[]`/`delete[]`).
* **Operator Suite:** Arithmetic (`+`, `+=`), Comparison (`==`, `<`), Stream I/O (`<<`, `>>`), and Access (`[]`).

> 📂 Folder: `My-String-Operator-Overloading/`

---

### 3️⃣ `Smart-Pointers-Lab`
> **Focus:** Modern Memory Safety & Ownership Semantics

A technical laboratory focused on mastering C++ Smart Pointers, eliminating the need for manual `new`/`delete`.
This project demonstrates how to build complex data structures using **RAII** containers.

**Key Concepts:**
* **`std::unique_ptr`:** Exclusive ownership and `std::make_unique`.
* **`std::shared_ptr`:** Shared ownership and reference counting mechanics.
* **Complex Types:** Managing nested structures like `std::unique_ptr<std::vector<std::shared_ptr<T>>>`.
* **Functions:** Passing smart pointers correctly (by reference vs by value).

> 📂 Folder: `Smart-Pointers-Lab/`

---

### 4️⃣ `Polymorphic-Banking-System`
> **Focus:** Inheritance, Polymorphism & Business Logic

A scalable financial system simulation designed to manage a hierarchy of bank accounts with varying business rules. This is the "Flagship Project" that combines all previous concepts.

**System Architecture:**
* **Inheritance Hierarchy:** A base `Account` class derived into specialized types:
    * **`Savings_Account`:** Implements interest rate logic.
    * **`Checking_Account`:** Implements transaction fees.
    * **`Trust_Account`:** Complex logic with bonus structures and withdrawal limits.
* **Polymorphism:** Utilizing `virtual` functions and dynamic binding to manage generic account collections.
* **Safety:** Exception handling for illegal operations (Insufficent Funds).

> 📂 Folder: `Polymorphic-Banking-System/`

---

## 🧠 Roadmap & Mastery Goals

This portfolio documents a structured progression from syntax to architecture:

1.  **Basics:** Understanding objects and containers (`movie-library`).
2.  **The "Guts":** Mastering pointers, references, and memory layout (`My-String`).
3.  **Modern Safety:** Moving from manual memory management to Smart Pointers (`Smart-Pointers-Lab`).
4.  **Architecture:** Building scalable systems using Inheritance and Polymorphism (`Banking-System`).

---

## 👨‍💻 Author
**Ran Almagor**
*Computer Science Graduate & C++ Developer*