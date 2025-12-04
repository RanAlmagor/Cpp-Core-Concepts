#pragma once
#include <exception>

class IllegalNameException : public std::exception
{
public:
    IllegalNameException() noexcept = default;
    ~IllegalNameException() = default;
    virtual const char* what() const noexcept override {
        return "Illegal name exception: Account name cannot be empty.";
    }
};

