#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Mystring.h"

// --- Stream Operators ---
 std::ostream& operator<<(std::ostream& os, const Mystring &rhs)
{
	 
	 os << rhs.get_str();
	 return os;
}

 std::istream& operator>>(std::istream& is, Mystring& rhs)
 {
	 char buff[1000]; 

	 is >> buff;      
	 if (!is) {
		
		 return is;
	 }

	 rhs = Mystring{ buff }; 

	 return is;
 }

 // ---constructors---
 Mystring::Mystring():str{ new char[1]}
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


 Mystring::Mystring(const Mystring &source)
 {   
	 str = new char[strlen(source.str) + 1];
	 strcpy(str, source.get_str());
 }

 Mystring::Mystring(Mystring&& source) :str{ source.str }
 {
	 source.str = nullptr;
 }
 
 Mystring::~Mystring()
 {
	 delete[] str;
 }

 // ---copy and move assignment---
 Mystring& Mystring::operator=(const Mystring &rhs)
 {
	 if (this == &rhs)
	 {
		 return *this;
	 }
	 delete[] str;
	 str = new char[strlen(rhs.str) + 1];
	 strcpy(str, rhs.str);
	 return *this;
 
 }
 Mystring& Mystring::operator=(Mystring&& rhs)
 {
	 if (this == &rhs)
	 {
		 return*this;
	 }
	 delete[] str;
	 str = rhs.str;
	 rhs.str = nullptr;
	 return *this;
	 
 }


 //---gettes--- 
 const char* Mystring::get_str() const
 {

	 return (str==nullptr)?"":str;
 }
 size_t Mystring::get_length() const
 {
	 if (str == nullptr)
	 {
		 return 0;
	 }
	 else
	 {
		 return strlen(str);
	 }
	
 }
 void Mystring::display()const
 {
	 std::cout << "[" << str << "]" << get_length() << std::endl;
 }

 // ---Unary minus - lowercase---
 Mystring Mystring::operator-() const
 {
	 char *buff = new char[std::strlen(str) + 1];
	 strcpy(buff, str);
	 for (size_t i{0}; i < std::strlen(buff); i++)
	 {
		 buff[i] = std::tolower(buff[i]);
	 }
	 Mystring temp{ buff };
	 delete[] buff;
	 return temp;
 }

 // --- Equality Operators ---
 bool Mystring::operator==(const Mystring &rhs) const
 {
	 return (std::strcmp(str, rhs.str)) == 0;
 }
 bool Mystring::operator!=(const Mystring& rhs) const
 {
	 return !(*this == rhs);
 }
 // --- Relational Operators ---
 bool Mystring::operator<(const Mystring& rhs)const
 {
	 return (std::strcmp(str, rhs.str) < 0);
 }
 bool Mystring::operator>(const Mystring& rhs)const
 {
	 return (rhs<*this);
 }


 // --- Concatenation ---
 Mystring Mystring::operator+(const Mystring& rhs) const 
 {
	 char* buff = new char[std::strlen(str)+strlen(rhs.str) + 1];
	 strcpy(buff, str);
	 strcat(buff, rhs.str);
	 Mystring temp{ buff };
	 delete[]buff;
	 return temp;
 }

 Mystring& Mystring::operator+=(const Mystring& rhs) 
 {
	 *this = *this + rhs;
	 return *this;

 }

 // --- Repetition ---
 Mystring Mystring::operator*(int num) const
 {
	 size_t buff_length = std::strlen(str) * num + 1;
	 char* buff = new char[buff_length];
	 strcpy(buff,"");
	 for (size_t i{ 0 }; i < num;i++)
	 {
		 strcat(buff, str);
	 }
	 Mystring temp{ buff };
	 delete []buff;
	 return temp;

 }
 Mystring& Mystring::operator*=(int num)
 {
	 *this = *this * num;
	 return *this;
 }

 // --- Increment (To Uppercase) ---
 Mystring& Mystring::operator++()
 {
	 for (size_t i{ 0 }; i < strlen(str); i++)
	 {
		 str[i] = std::toupper(str[i]); 
	 }
	 return *this;
 }
 Mystring Mystring::operator++(int)
 {
	 Mystring temp{*this};
	 operator++();
	 return temp;

 }

 // --- Subscript Operator ([]) ---
 
 char& Mystring::operator[](size_t index)
 {
	 
	 if (index >= std::strlen(str)) 
	 {
		 return str[std::strlen(str)];
	 }
	 return str[index];
 }
 const char& Mystring::operator[](size_t index) const
 {
	 
	 return (index >= std::strlen(str)) ? str[std::strlen(str)] : str[index];
 }