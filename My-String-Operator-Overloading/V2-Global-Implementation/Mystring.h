#pragma once
#include<iostream>
class Mystring
{
	// --- Stream Operators ---
	friend std::ostream &operator<<(std::ostream &os,const Mystring &obj);
	friend std::istream& operator>>(std::istream &is, Mystring &obj);

	// ---Unary minus - lowercase---
	friend Mystring operator-(const Mystring &obj);

	// --- Equality Operators ---
	friend bool operator==(const Mystring& lhs, const Mystring& rhs);
	friend bool operator!=(const Mystring& lhs, const Mystring& rhs);

	// --- Relational Operators ---
	friend bool operator<(const Mystring& lhs, const Mystring& rhs);
	friend bool operator>(const Mystring& lhs, const Mystring& rhs);

	// --- Concatenation ---
	friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
	friend Mystring &operator+=(Mystring& lhs, const Mystring& rhs);

	// --- Repetition ---
	friend Mystring operator*(const Mystring& obj, int n);
	friend Mystring& operator*=(Mystring& obj, int n);

	// --- Increment (To Uppercase) ---
	friend Mystring &operator++(Mystring& obj);
	friend Mystring operator++(Mystring& obj,int);


private:

	char* str;
public:


	// ---constructors---
	Mystring();
	Mystring(const char* s);
	Mystring(const Mystring& source);
	Mystring(Mystring&& source);
	~Mystring();

	//---gettes---
	const char* get_str() const;
	size_t get_length() const;

	void display() const;

	// ---copy and move assignment---
	Mystring &operator=(const Mystring& source);
	Mystring& operator=(Mystring&& source);
	
	// --- Subscript Operator ([]) ---
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	

};
