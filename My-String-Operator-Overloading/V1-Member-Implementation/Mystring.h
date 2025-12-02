#pragma once


class Mystring
{
	// --- Stream Operators ---
	friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
	friend std::istream& operator>>(std::istream& in,  Mystring &rhs);


private:
	char* str;

public: 

	
	// ---constructors---
	Mystring(); 

	Mystring(const char* s);

	Mystring(const Mystring &source);

	Mystring(Mystring&& source);

	~Mystring();

	
	// ---copy and move assignment---
	Mystring& operator=(const Mystring &rhs);
	Mystring& operator=( Mystring &&rhs);


	//---gettes---
	const char* get_str() const;	
	size_t get_length() const;



	void display() const;


	// ---Unary minus - lowercase---
	Mystring operator-() const;   

	// --- Equality Operators ---
	bool operator==(const Mystring& rhs) const;
	bool operator!=(const Mystring& rhs) const;

	// --- Relational Operators ---
	bool operator<(const Mystring& rhs) const;
	bool operator>(const Mystring& rhs) const;

	// --- Concatenation ---
	Mystring operator+(const Mystring& rhs) const; 
    Mystring &operator+=(const Mystring& rhs);


	// --- Repetition ---
	Mystring operator*(int n) const;
	Mystring &operator*=(int n);

	// --- Increment (To Uppercase) ---
	Mystring &operator++(); 
	Mystring operator++(int); 

	// --- Subscript Operator ([]) ---
	char &operator[]( size_t index); 
   const char &operator[]( size_t index) const;



};
