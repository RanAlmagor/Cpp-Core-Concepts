#pragma once
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 4.5;
    static constexpr const int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2; 

    int num_withdrawals=0;

public:
    
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);


    void deposit(double amount) override;

 
    void withdraw(double amount) override;

    void print(std::ostream& os) const override;

    ~Trust_Account() = default;
};