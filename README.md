# Cpp-Core-Concepts

![Language](https://img.shields.io/badge/language-Modern%20C++-blue.svg)
![Status](https://img.shields.io/badge/status-active-success.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## 📖 Overview

This repository documents my progression in **Modern C++**.
It contains a collection of projects designed to practice specific core concepts, ranging from low-level memory mechanics to object-oriented architecture.

**Key Focus Areas:**
* **Object-Oriented Design (OOD)** & Polymorphism.
* **Low-Level Memory Management** (RAII, Pointers, Stack vs Heap).
* **Smart Pointers** & Modern Syntax (C++14/17/20).
* **Exception Handling.**

---

## 📂 Project Catalog

### 1️⃣ `movie-library`
> **Focus:** Class Basics, Encapsulation & Data Structures

A console-based application designed to manage a personal movie collection.
* **Key Concepts:** Classes, Objects, Access Modifiers, `std::vector`.
* **Architecture:** Separation of concerns using Header (`.h`) and Source (`.cpp`) files.

> 📂 Folder: `movie-library/`

---

### 2️⃣ `My-String-Operator-Overloading`
> **Focus:** Low-Level Memory Management (RAII) & Operator Overloading

A custom String class implementation, built from scratch to understand raw pointers and manual memory handling mechanics.

**Core Mechanics:**
* **Rule of Five:** Implementation of Copy/Move Constructors & Assignment Operators.
* **Deep Copying:** Manual heap allocation (`new[]`/`delete[]`).
* **Operator Suite:** Arithmetic (`+`, `+=`), Comparison (`==`, `<`), Stream I/O (`<<`, `>>`), and Access (`[]`).

> 📂 Folder: `My-String-Operator-Overloading/`

---

### 3️⃣ `Smart-Pointers-Lab`
> **Focus:** Modern Memory Safety

A project focused on practicing C++ Smart Pointers to eliminate the need for manual `new`/`delete`.
Demonstrates how to build data structures using **RAII** containers.

**Key Concepts:**
* **`std::unique_ptr`:** Exclusive ownership.
* **`std::shared_ptr`:** Shared ownership and reference counting.
* **Complex Types:** Managing nested structures (e.g., vectors of pointers).

> 📂 Folder: `Smart-Pointers-Lab/`

---

### 4️⃣ `Polymorphic-Banking-System`
> **Focus:** Polymorphism, Inheritance & Exception Handling

A banking simulation that applies Object-Oriented principles to manage different account types.

**System Architecture:**
* **Polymorphic Container:** Managed via `std::vector<std::unique_ptr<Account>>` for automatic memory cleanup.
* **Inheritance Hierarchy:** Abstract base `Account` → `Savings` → `Checking` → `Trust`.
* **Exception Safety:** Using custom exceptions (`InsufficientFunds`, `IllegalAmount`) instead of error codes.
* **Interface Segregation:** Implements `I_Printable` for uniform stream output.

> 📂 Folder: `Polymorphic-Banking-System/`

---

## 🧠 Learning Path

A structured progression from syntax to architecture:

1.  **Basics:** Objects and containers (`movie-library`).
2.  **The "Guts":** Pointers, references, and memory layout (`My-String`).
3.  **Modern Safety:** Moving to Smart Pointers (`Smart-Pointers-Lab`).
4.  **Architecture:** Inheritance, Polymorphism, and Exceptions (`Banking-System`).

---

## 👨‍💻 Author
**Ran Almagor**
*Computer Science Graduate & C++ Developer*

---
## 💡 Acknowledgements
This repository contains my personal implementations and extended solutions for challenges from **Frank Mitropoulos's C++ Masterclass**.
