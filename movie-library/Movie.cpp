#include "Movie.h"
#include <string>
#include <iostream>

Movie::Movie(const std::string &name, const std::string &rating, int watched) :name(name), rating(rating), watched(watched){}

Movie::Movie (const Movie &source): Movie{source.name,source.rating,source.watched}{} 



std::string Movie::get_name() const
{
	return name;
}

std::string Movie::get_rating() const
{
	return  rating;
}

int Movie::get_watched() const
{
	return  watched;
}

void Movie::set_name(const std::string &name)
{
	this->name = name;
}
void Movie::set_rating(const std::string &rating)
{
	this->rating = rating;
}
void Movie::set_watched(int watched)
{
	this->watched = watched;
}

void Movie::increment_watched()
{
	this->watched++;
}

void Movie::display() const {
	std::cout << name << ", " << rating << ", " << watched << std::endl;
}


