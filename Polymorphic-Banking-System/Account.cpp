#include "Account.h"

// --- Constructor ---
Account::Account(std::string name, double balance):name{name},balance{balance}
{
	if (balance < 0.0)
	{
		throw IllegalBalanceException();
	}
    if (name.empty())
    {
        
        throw IllegalNameException();
    }
}

// --- Deposit Base Logic ---
void Account::deposit(double amount)
{
    if (amount < 0)
        throw IllegalAmountException();
    else
    {
        balance += amount;
       
    }

}

// --- Withdraw Base Logic ---
void Account::withdraw(double amount)
{
    if (amount < 0)
    {
        throw IllegalAmountException();
    }
    if (balance >= amount)
    {
        balance -= amount;
       
    }
    else
    {
        throw InsufficientFundsException();
    }

}

// --- Print Base Logic ---
void Account::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}


