## 🧱 Core Concepts Demonstrated

This project is a practical application of foundational C++ OOP concepts:

- **Classes & Objects**  
  Implementation of two distinct classes:
  - `Movie`: models a single movie (name, rating, watch count).
  - `Movies`: manages the entire collection of `Movie` objects.

- **Encapsulation**  
  Correct use of `public` and `private` access specifiers to protect object data.

- **Constructors / Destructors**  
  Proper use of constructors (including a copy constructor) and a destructor for object lifecycle management.

- **const-Correctness**  
  Using the `const` keyword on member functions that do not modify the object's state (e.g. `display()`, getters).

- **STL Containers**  
  Using `std::vector` to hold a collection of custom objects (`std::vector<Movie>`).

- **File Separation**  
  Organizing the project into `.h` (header/specification) and `.cpp` (implementation) files for a clean and maintainable architecture.

---

## ⚙️ Key Features

- **Add Movie**  
  Adds a new `Movie` object to the collection.  
  Includes logic to prevent duplicate movie names.

- **Increment Watch Count**  
  Finds a movie by name and increments its `watch_count`.  
  Includes error handling for cases where the movie is not found.

- **Display All Movies**  
  Iterates through the `std::vector` and delegates the display responsibility to each `Movie` object's `display()` method.
