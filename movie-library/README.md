## 🧱 Core Concepts Demonstrated

This project is a hands-on implementation of core C++ OOP principles:

- **Classes & Objects**  
  Two cohesive classes:
  - `Movie` – models a single movie (title, rating, watch count).
  - `Movies` – manages a collection of `Movie` instances.

- **Encapsulation**  
  Clear separation of interface and implementation using `public` / `private` members to protect internal state.

- **Constructors & Destructors**  
  Proper use of constructors (including copy construction where needed) and a destructor to manage object lifetime.

- **const-Correctness**  
  Member functions that do not modify the object (such as getters and `display()`) are marked `const` to enforce correctness at compile time.

- **STL Containers**  
  `std::vector<Movie>` is used as the underlying container to store and manage the movie collection efficiently.

- **File Organization**  
  Clean separation into header (`.h`) and implementation (`.cpp`) files for better modularity and maintainability.

---

## ⚙️ Key Features

- **Add Movie**  
  Adds a new `Movie` to the collection, with logic to avoid duplicate titles and keep the dataset consistent.

- **Increment Watch Count**  
  Locates a movie by name and increments its `watch_count`, with handling for cases where the movie does not exist in the collection.

- **Display All Movies**  
  Iterates over the `std::vector<Movie>` and delegates formatting and output to each `Movie::display()` function, keeping responsibilities well-encapsulated.
