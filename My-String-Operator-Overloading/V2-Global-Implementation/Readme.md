# 🌟 Mystring – Custom C++ String Class  
### **Version 2 – Global / Friend Operators Implementation**

A focused implementation of a custom C++ string class that demonstrates  
**manual memory management**, **Rule of 5**, and especially  
**non-member (global) operator overloading using `friend` functions**.

This version builds on Version 1 (member-based operators) and reimplements  
the core operators as **free functions** for better flexibility and clearer separation  
between interface and implementation.

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
- Deep copy for safe, isolated ownership of the internal `char*`  
- Move semantics that transfer ownership and null out the source pointer  
- Cleanup handled by `delete[]`  
- `get_str()` never exposes `nullptr` (returns `""` instead)

### 🔷 Global / Friend Operator Overloading
Implemented as **non-member** (global) functions with `friend` access:

- Stream operators: `<<`, `>>`  
- Unary minus: `-` → returns a lowercase copy  
- Comparison: `==`, `!=`, `<`, `>`  
- Concatenation: `+`, `+=`  
- Repetition: `*`, `*=`  
- Increment: `++obj`, `obj++` → uppercase transform  

Member-side:

- Subscript operator `[]` (const and non-const)  
- Utility access via `get_str()` and `get_length()`

---

## 📦 Class Definition (Header)

```cpp
class Mystring
{
    // --- Stream Operators ---
    friend std::ostream& operator<<(std::ostream& os, const Mystring& obj);
    friend std::istream& operator>>(std::istream& is, Mystring& obj);

    // --- Unary minus - lowercase ---
    friend Mystring operator-(const Mystring& obj);

    // --- Equality Operators ---
    friend bool operator==(const Mystring& lhs, const Mystring& rhs);
    friend bool operator!=(const Mystring& lhs, const Mystring& rhs);

    // --- Relational Operators ---
    friend bool operator<(const Mystring& lhs, const Mystring& rhs);
    friend bool operator>(const Mystring& lhs, const Mystring& rhs);

    // --- Concatenation ---
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
    friend Mystring& operator+=(Mystring& lhs, const Mystring& rhs);

    // --- Repetition ---
    friend Mystring operator*(const Mystring& obj, int num);
    friend Mystring& operator*=(Mystring& obj, int num);

    // --- Increment (To Uppercase) ---
    friend Mystring& operator++(Mystring& obj);      // Prefix
    friend Mystring operator++(Mystring& obj, int);  // Postfix

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
    Mystring& operator=(const Mystring& source);
    Mystring& operator=(Mystring&& source);

    // Getters
    const char* get_str() const;
    size_t get_length() const;

    // Subscript operator
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
};
