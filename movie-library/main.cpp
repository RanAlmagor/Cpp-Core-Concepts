#include <iostream>
#include <string>
#include "Movies.h"

// Helper function prototypes
void add_movie(Movies& movies,
    const std::string& name,
    const std::string& rating,
    int watched);

void increment_watched(Movies& movies,
    const std::string& name);


int main() {
    Movies my_movies;   // Our movie collection


    // 1) Display movies when collection is still empty

    my_movies.display();

    // 2) Add some movies to the collection

    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);

    // 3) Display after adding 3 movies

    my_movies.display();

    // 4) Try to add a duplicate movie + a new movie

    add_movie(my_movies, "Cinderella", "PG", 7);   // duplicate – should fail

    add_movie(my_movies, "Ice Age", "PG", 12);   // new movie – should succeed

    // 5) Display again (we expect: Big, Star Wars, Cinderella, Ice Age)

    my_movies.display();

    // 6) Increment watch count for existing movies

    increment_watched(my_movies, "Big");      // was 2 -> should become 3
    increment_watched(my_movies, "Ice Age");  // was 12 -> should become 13

    // 7) Display again to verify updated watch counts

    my_movies.display();

    // 8) Try to increment a movie that does not exist

    increment_watched(my_movies, "XXX");      // should print an error message

    return 0;
}

// -------------------------
// Helper function definitions
// -------------------------

// Try to add a movie to the collection and print a clear message

void add_movie(Movies& movies,
    const std::string& name,
    const std::string& rating,
    int watched)
{
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << " added" << std::endl;
    }
    else {
        std::cout << name << " already exists" << std::endl;
    }
}

// Try to increment watch count for a given movie name

void increment_watched(Movies& movies,
    const std::string& name)
{
    if (movies.increment_watched(name)) {
        std::cout << name << " watch count incremented" << std::endl;
    }
    else {
        std::cout << name << " not found" << std::endl;
    }
}
