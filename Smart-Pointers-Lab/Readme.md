# 🌟 Smart Pointers – Vector-Based Test Store  
### Modern C++ Smart Pointer Composition

A focused Modern C++ component that demonstrates **smart pointer ownership models**,  
**RAII**, and **STL integration** using the following nested structure:

```cpp
std::unique_ptr<
    std::vector<
        std::shared_ptr<Test>
    >
>
```

All dynamic resources are managed via `std::unique_ptr` and `std::shared_ptr` –  
no raw `new` / `delete` appear in the implementation.

---

## 🚀 Highlights

### 🔷 Ownership & Lifetime

- **`std::unique_ptr<std::vector<std::shared_ptr<Test>>>`**  
  - The container (`std::vector`) is allocated on the **heap**.  
  - A single `std::unique_ptr` on the **stack** owns the vector exclusively.  
  - Destruction of the `unique_ptr` automatically frees the vector.

- **`std::shared_ptr<Test>`**  
  - Each element in the vector is a smart pointer managing a `Test` instance.  
  - Reference counting ensures every `Test` is destroyed exactly once,  
    when the last `shared_ptr` owning it is released.

Conceptually:

```text
[stack] vec_ptr  (std::unique_ptr)
   |
   v
[heap] std::vector< std::shared_ptr<Test> >
           |
           +--> [heap] Test(10)
           +--> [heap] Test(20)
           +--> [heap] Test(30)
           ...
```

The destruction chain is deterministic and fully automatic.

---

## 🧱 Core API

### 🏗️ Factory – `make`

```cpp
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
```

- Allocates a `std::vector<std::shared_ptr<Test>>` on the heap.  
- Returns ownership to the caller via `std::unique_ptr`.  
- Uses `std::make_unique` for clarity and exception safety.

**Implementation:**

```cpp
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    auto ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
    return ptr;
}
```

---

### ✍️ Population – `fill`

```cpp
void fill(std::vector<std::shared_ptr<Test>>& vec, size_t num);
```

- Accepts the vector **by non-const reference** so it can be modified.  
- Reads `num` integer values from `std::cin`.  
- For each value:
  - Constructs a `std::shared_ptr<Test>` with `std::make_shared<Test>(value)`.  
  - Appends it to the vector via `push_back`.

**Implementation:**

```cpp
void fill(std::vector<std::shared_ptr<Test>>& vec, size_t num) {
    int temp_data{0};

    for (size_t i{ 0 }; i < num; i++) {
        std::cout << "Enter data point [" << i << "]: ";
        std::cin >> temp_data;
        vec.push_back(std::make_shared<Test>(temp_data));
    }
}
```

---

### 👁️ Read-Only View – `display`

```cpp
void display(const std::vector<std::shared_ptr<Test>>& vec);
```

- Accepts the vector **by const reference** (no copy, no modification).  
- Iterates over the vector and prints each `Test`’s data via `ptr->get_data()`.

**Implementation:**

```cpp
void display(const std::vector<std::shared_ptr<Test>>& vec) {
    std::cout << "\nDisplaying vector data\n";
    std::cout << "=======================\n";
    for (const auto& ptr : vec) {
        std::cout << ptr->get_data() << std::endl;
    }
}
```

---

## 🧪 Usage Example

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include "Test.h"

// Prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>>& vec, size_t num);
void display(const std::vector<std::shared_ptr<Test>>& vec);

int main() {
    // Unique ownership of the vector on the heap
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;

    vec_ptr = make();

    std::cout << "How many data points do you want to enter: ";
    size_t num{};
    std::cin >> num;

    // Work directly with the underlying vector
    fill(*vec_ptr, num);
    display(*vec_ptr);
}
```

When `main` returns:

- `vec_ptr` goes out of scope → the `std::unique_ptr` destructor deletes the vector.  
- Destroying the vector destroys all `std::shared_ptr<Test>` elements.  
- Each `shared_ptr` reaches reference count zero → the corresponding `Test` objects are destroyed.

No explicit cleanup code is required.

---

## 🧠 Design Principles

- **RAII Everywhere** – resource lifetime is bound to object lifetime.  
- **No Raw Ownership** – all allocation via `std::make_unique` / `std::make_shared`.  
- **Const-Correctness** – read-only functions take `const std::vector<...>&`.  
- **STL Integration** – smart pointers stored and iterated using `std::vector` and range-based `for` loops.  

---

## 👨‍💻 Author

**Ran Almagor**  
*C++ Developer*
