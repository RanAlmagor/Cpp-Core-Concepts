#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "Mystring.h"

// --- Stream Operators ---
 std::ostream& operator<<(std::ostream &os, const Mystring& obj)
{
	 os << obj.get_str();
	 return os;
}

 std::istream& operator>>(std::istream& is, Mystring& obj)
 {
	 char buff [1000];
	 is >> buff;
	 if (!is)
	 {
		 return is;
	 }
	 obj = Mystring{buff};
	 return is;
 }

 // ---Unary minus - lowercase---
 Mystring operator-(const Mystring& obj)
 {
	 char* buff = new char[strlen(obj.str) + 1];
	 strcpy(buff, obj.str);

	 for (size_t i{ 0 }; i < strlen(buff); i++)
	 {
		 buff[i] = tolower(buff[i]);
	 }
	 Mystring temp{ buff };
	 delete[]buff;
	 return temp;
	
  }

 // --- Equality Operators ---
 bool operator==(const Mystring& lhs, const Mystring& rhs)
 {
	 return strcmp(lhs.str, rhs.str)==0;
 }
 bool operator!=(const Mystring& lhs, const Mystring& rhs)
 {
	 return !(lhs == rhs);
 }

 // --- Relational Operators ---
 bool operator<(const Mystring& lhs, const Mystring& rhs)
 {
	 return strcmp(lhs.str, rhs.str)< 0;
 }
 bool operator>(const Mystring& lhs, const Mystring& rhs)
 {
	 return rhs < lhs;
	 
 }

 // --- Concatenation ---
 Mystring operator+(const Mystring& lhs, const Mystring& rhs)
 {
	 char* buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
	 strcpy(buff, lhs.str);
	 strcat(buff, rhs.str);
	 Mystring temp{ buff };
	 delete[]buff;
	 return temp;

 }
 Mystring &operator+=( Mystring& lhs, const Mystring& rhs)
 {
	 lhs = lhs + rhs;
	 return lhs;


 }
 // --- Repetition ---
 Mystring operator*(const Mystring& obj, int num)
 {   
	 size_t buff_length = strlen(obj.str) * num + 1;
	 char* buff = new char[buff_length];
	 strcpy(buff, "");
	 for (size_t i{ 0 }; i < num; i++)
	 {
		 strcat(buff, obj.str);
	 }
	 Mystring temp{ buff };
	 delete []buff;
	 return temp;
 }

 Mystring& operator*=(Mystring& obj, int num)
 {
	 obj = obj * num;
	 return obj;
 }

 // --- Increment (To Uppercase) ---
 Mystring& operator++(Mystring& obj)
 {
	 for (size_t i{ 0 }; i < strlen(obj.str); i++)
	 {
		 obj.str[i] = toupper(obj.str[i]);
		
	 }
	 return obj;
 }
 Mystring operator++(Mystring&obj, int)
 {
	 Mystring temp{ obj };
	 ++obj;
	 return temp;
	 
 }

 // ---constructors---
 Mystring::Mystring() :str{ new char[1] }
 {
	 str[0] = '\0';
 }

 Mystring::Mystring(const char* s)
 {
	 if (s == nullptr)
	 {
		 str = new char[1];
		 str[0] = '\0';
	 }
	 else
	 {
		 size_t len = strlen(s);
		 str = new char[len + 1];
		strcpy(str, s);
	 }
 }

 Mystring::Mystring(const Mystring& source):Mystring(source.str)
 {}

 Mystring::Mystring (Mystring&& source):str{source.str}
 {    
	 source.str = nullptr;
 }
 Mystring::~Mystring()
 {
	 delete[]str;
 }

 //---gettes---
 const char* Mystring::get_str() const
 {
	 return (str == nullptr) ? "" : str;
 }

 size_t Mystring::get_length() const
 {
	 return strlen(this->get_str());
 }

 // ---copy and move assignment---
 Mystring& Mystring::operator=(const Mystring &source)
 {
	 if (this == &source)
	 {
		 return *this;
	 }
	 delete[]str;
	 str = new char[strlen(source.str) + 1];
	 strcpy(str, source.str);
	return *this;
 }
 Mystring& Mystring::operator=(Mystring&& source)
 {
	 if (this == &source)
	 {
		 return *this;
	 }
	 delete[] str;
	 str = source.str;
	 source.str = nullptr;
	 return *this;
 }

 // --- Subscript Operator ([]) ---
 char& Mystring::operator[](size_t index)
 {
	 if (index >= strlen(str))
	 {
		 return str[strlen(str)];
	 }
	 else
	 {
		 return str[index];
	 }
 }

 const char& Mystring::operator[](size_t index) const
 {
	 return(index >= strlen(str)) ? str[strlen(str)] : str[index];
 }