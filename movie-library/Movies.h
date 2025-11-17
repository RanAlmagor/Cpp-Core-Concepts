#pragma once
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{ private:
	
	std::vector <Movie> movies;
	 


  public: 

	  Movies()=default;

	  ~Movies()=default;

	  bool add_movie(const std::string &name, const std::string &rating, int watched);

	  bool increment_watched(const std::string &name);
    
	  void display() const;


	 

};
