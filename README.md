# Cpp-Core-Concepts

This repository contains a collection of small C++ projects that I use to practice and demonstrate core C++ concepts:
object-oriented design, operator overloading, STL usage, and manual memory management (Rule of 5).

---

## 📂 Projects

### 1️⃣ `movie-library`

A small console application that manages a collection of movies.  
Key concepts:

- Classes & objects (`Movie`, `Movies`)
- Encapsulation with `public` / `private`
- Constructors, destructors, and const-correctness
- `std::vector<Movie>` as the underlying container
- Clean separation into `.h` / `.cpp` files

> Folder: `movie-library/`

---

### 2️⃣ `My-String-Operator-Overloading`

A custom string class implementation that focuses on operator overloading and memory management.

> Folder: `My-String-Operator-Overloading/`

This project currently has **two versions**:

#### 🔹 V1 – Member Implementation  
> Folder: `My-String-Operator-Overloading/V1-Member-Implementation/`

A member-based implementation of a `Mystring` class that demonstrates:

- Full Rule of 5 (ctor, dtor, copy/move ctor, copy/move assignment)
- Manual `new[]` / `delete[]` management
- Deep copy & move semantics
- Rich operator overloading:  
  `<<`, `>>`, `==`, `!=`, `<`, `>`, `+`, `+=`, `*`, `*=`, `++` (prefix & postfix), `operator[]`, unary `-` (lowercase)
- Null-safe getters and a small display helper

#### 🔹 V2 – Global Implementation  
> Folder: `My-String-Operator-Overloading/V2-Global-Implementation/`

A second version of the same idea, using more **non-member / friend** operators and a slightly different design approach, to contrast member-based vs. global operator implementations.

---

## 🧠 Goals of This Repository

- Practice **modern C++ fundamentals** on small, focused projects  
- Demonstrate understanding of:
  - OOP (encapsulation, classes, interfaces)
  - Resource management and Rule of 5
  - STL containers (`std::vector`, etc.)
  - Operator overloading and clean API design
- Build a portfolio of clear, well-structured C++ examples.
