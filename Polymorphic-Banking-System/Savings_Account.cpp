#include "Savings_Account.h"

// --- Constructor ---
Savings_Account::Savings_Account(std::string name, double balance, double int_rate):Account(name,balance),int_rate{int_rate}
{ }

// --- Deposit (Specialized) ---
void Savings_Account::deposit(double amount)
{
    
    amount += amount * (int_rate / 100);

   
    Account::deposit(amount);
}
void Savings_Account::withdraw(double amount)
{
     Account::withdraw(amount);
}

// --- Print (Specialized) ---
void Savings_Account::print(std::ostream& os) const
{
    Account::print(os);
    os << " Interest: " << int_rate << "%";
}