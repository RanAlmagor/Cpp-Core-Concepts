# Cpp-Core-Concepts

![Language](https://img.shields.io/badge/language-C++14-blue.svg)
![Status](https://img.shields.io/badge/status-active-success.svg)

This repository serves as a master portfolio of my journey through **Modern C++**.
It contains a collection of focused projects, each designed to master specific pillars of the language:
**Object-Oriented Design (OOD)**, **Low-Level Memory Management**, **Operator Overloading**, and **Polymorphism**.

---

## 📂 Project Catalog

### 1️⃣ `movie-library`
> **Focus:** Class Basics & Encapsulation

A console-based application for managing a personal movie collection.
* **Key Concepts:** Classes, Objects, Access Modifiers, `std::vector` usage.
* **Architecture:** Separation of concerns using header/source files.

> 📂 Folder: `movie-library/`

---

### 2️⃣ `My-String-Operator-Overloading`
> **Focus:** Low-Level Memory Management (RAII) & Operator Overloading

A comprehensive implementation of a custom String class, built from scratch to demonstrate mastery of raw pointers and memory handling.

This project includes **two architectural approaches**:
* **V1 (Member Functions):** Standard OOP implementation using `this`.
* **V2 (Global Functions):** Symmetric operator design using `friend` functions.

**Core Mechanics:**
* **Rule of Five:** Copy/Move Constructors & Assignment Operators.
* **Deep Copying:** Safe manual heap allocation (`new[]`/`delete[]`).
* **Full Operator Suite:** Arithmetic (`+`, `+=`), Comparison (`==`, `<`), and Stream I/O.

> 📂 Folder: `My-String-Operator-Overloading/`

---

### 3️⃣ `Polymorphic-Banking-System`
> **Focus:** Inheritance, Polymorphism & Business Logic

A financial system simulation designed to manage a hierarchy of bank accounts with varying business rules.

**Current Architecture:**
* **Inheritance Hierarchy:** A base `Account` class derived into specialized types:
    * `Savings_Account` (Interest logic)
    * `Checking_Account` (Transaction fees)
    * `Trust_Account` (Bonus structures & withdrawal limits)
* **Design Patterns:** Usage of helper functions to manage account operations uniformly.
* **Goal:** To demonstrate how specialized behavior is achieved through class derivation and overriding.

> 📂 Folder: `Polymorphic-Banking-System/`

---

## 🧠 Roadmap & Mastery Goals

This repository documents the progression from syntax to architecture:
1.  **Basics:** Understanding objects and containers (`movie-library`).
2.  **The "Guts":** Mastering pointers, references, and memory layout (`My-String`).
3.  **Architecture:** Building scalable systems using Inheritance and Polymorphism (`Banking-System`).

---

## 👨‍💻 Author
**Ran Almagor** - *C++ Developer*