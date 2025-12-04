#pragma once


#include <exception>

class IllegalAmountException : public std::exception
{
public:
    IllegalAmountException() noexcept = default;
    ~IllegalAmountException() = default;

    virtual const char* what() const noexcept override
    {
        return "Illegal amount exception: Amount must be positive.";
    }
};

