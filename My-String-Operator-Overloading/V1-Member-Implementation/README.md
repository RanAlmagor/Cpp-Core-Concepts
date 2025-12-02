# 🌟 Mystring – Custom C++ String Class  
### **Version 1 – Member Implementation**

A clean and modern implementation of a custom C++ string class that demonstrates full manual memory control, deep copy semantics, move semantics, and rich operator overloading.  
Designed to showcase strong understanding of **low-level memory management**, **object semantics**, and **C++ class design**.

---

## 🚀 Highlights

### 🔷 Rule of 5 — Fully Implemented
- Constructor  
- Destructor  
- Copy constructor  
- Move constructor  
- Copy assignment  
- Move assignment  

### 🔷 Memory Safety & Ownership
- Deep copying ensures isolated ownership  
- Efficient move operations for performance  
- Guaranteed cleanup via `delete[]`  
- Null-safe interface (`get_str()` never returns nullptr)

### ⚙️ Comprehensive Operator Overloading
Includes:

- Stream operators: `<<`, `>>`  
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`  
- Concatenation: `+`, `+=`  
- Unary operations:  
  - `-` → lowercase  
  - `++` (prefix & postfix) → uppercase  
- Repetition: `*`, `*=`  
- Subscript operator `[]`  
- Utility: `display()`

---

## 📦 Class Definition (Header)

```cpp
class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& is, Mystring& rhs);

private:
    char* str;

public:
    // Constructors & Destructor
    Mystring();
    Mystring(const char* s);
    Mystring(const Mystring& source);
    Mystring(Mystring&& source);
    ~Mystring();

    // Assignment
    Mystring& operator=(const Mystring& rhs);
    Mystring& operator=(Mystring&& rhs);

    // Getters
    const char* get_str() const;
    size_t get_length() const;

    // Display
    void display() const;

    // Unary minus (lowercase)
    Mystring operator-() const;

    // Comparison operators
    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;
    bool operator<(const Mystring& rhs) const;
    bool operator>(const Mystring& rhs) const;
    bool operator<=(const Mystring& rhs) const;
    bool operator>=(const Mystring& rhs) const;

    // Concatenation
    Mystring operator+(const Mystring& rhs) const;
    Mystring& operator+=(const Mystring& rhs);

    // Repetition
    Mystring operator*(int n) const;
    Mystring& operator*=(int n);

    // Increment (uppercase)
    Mystring& operator++();      // Prefix
    Mystring operator++(int);    // Postfix

    // Subscript operator
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
};
```

---

## 🧠 Design Principles

- Manual memory management with `new[]` / `delete[]`  
- Strong ownership semantics  
- Minimal code duplication  
- Clean operator chaining (`!=` using `==`, `>` using `<`, etc.)  
- Robust, predictable behavior  
- Modern C++ style with clarity and stability

---

## 📝 Usage Example

```cpp
Mystring a{"Hello"};
Mystring b{" World"};

Mystring c = a + b;
c.display();      // [Hello World] 11

Mystring d = -c;  // lowercase
d.display();

a += b;
++a;              // uppercase
std::cout << a << std::endl;

std::cout << a[0] << '\n';
```

---

## 📚 Purpose

The goal of this implementation is to demonstrate:

- A solid understanding of memory handling in C++  
- How deep copy and move operations behave internally  
- How to design a safe, expressive, and feature-rich custom class  
- A clear grasp of operator overloading and consistent semantics  

---


