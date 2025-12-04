#include "Trust_Account.h"

// --- Constructor ---
Trust_Account::Trust_Account(std::string name, double balance, double  int_rate) :Savings_Account(name, balance, int_rate)
{ }

// --- Deposit (Specialized) ---
void Trust_Account::deposit(double amount)
{
	
    if (amount >= 10000.0)
    {
        amount += 100.0;
    }
     Savings_Account::deposit(amount);

	
}
// --- withdraw (Specialized) ---
void Trust_Account::withdraw(double amount)
{

    if (num_withdrawals >= max_withdrawals)
    {
        throw InsufficientFundsException();
    }
    if (amount > (balance * max_withdraw_percent))
    {
        throw IllegalAmountException();
    }

    Savings_Account::withdraw(amount);
    num_withdrawals++;
    
                    
}

void Trust_Account::print(std::ostream& os) const 
{
    Savings_Account::print(os);
    os << " [Withdrawals: " << num_withdrawals << "/" << max_withdrawals << "]"; 
}