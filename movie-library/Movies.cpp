#include "Movies.h"
#include <iostream>


bool Movies::add_movie(const std::string &name, const std::string &rating, int watched)
{
	for (const auto &movie:movies)
	{
		if (movie.get_name() == name)
		{
			return false;
		}
	}
	Movie new_movie = Movie(name, rating, watched);
	movies.push_back(new_movie);
	return true;
}

bool Movies::increment_watched(const std::string& name)
{
	for (auto &movie:movies)
	{
		if (movie.get_name() == name)
		{
			movie.increment_watched();
			return true;

		}
	}
	return false;
}

void Movies::display() const 
{
	if (movies.size() == 0) {
		std::cout << "Sorry, no movies to display\n" << std::endl;
	}
	else {
		std::cout << "\n===================================" << std::endl;
		for (const auto& movie : movies)
			movie.display();
		std::cout << "\n===================================" << std::endl;
	}
}


