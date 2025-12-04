#pragma once
#include "Account.h"

class Savings_Account : public Account
{
private:
    static constexpr const char* def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    double int_rate;

public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

   void deposit(double amount) override;
   void withdraw(double amount) override;

   void print(std::ostream& os) const override;
   ~Savings_Account() = default;

};