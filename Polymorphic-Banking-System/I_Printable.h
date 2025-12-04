#pragma once
#include<iostream>
class I_printable
{
	friend std::ostream& operator<<(std::ostream& os, const I_printable& obj);
public:
	virtual void print(std::ostream& os) const = 0;
	virtual ~I_printable()=default;
};