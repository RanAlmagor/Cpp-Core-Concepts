#pragma once
#include<exception>
class IllegalBalanceException : public std::exception
{
public:
	IllegalBalanceException()noexcept = default;
	~IllegalBalanceException()noexcept = default;
	virtual const char* what() const  noexcept   override
	{
		return "Illegal balance exception: Cannot create account with negative balance.";
	}
};