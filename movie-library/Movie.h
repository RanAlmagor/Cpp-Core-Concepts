#pragma once
#include <string>
class Movie
{

private:
	std::string name;
	std::string rating;
	int watched{ 0 };

public:
	Movie(const std::string &name, const std::string &rating, int watched);

	Movie(const Movie &source);

	~Movie()=default;

	std::string get_name() const;

	std::string get_rating() const;


	int get_watched() const;
	
	void set_name(const std::string &name);
	
	void set_rating(const std::string &rating);
	
	void set_watched(int watched);

	void increment_watched();

	void display() const;


	


};