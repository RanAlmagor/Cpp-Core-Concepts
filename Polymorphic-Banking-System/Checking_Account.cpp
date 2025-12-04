#include "Checking_Account.h"

// --- Constructor ---
Checking_Account::Checking_Account(std::string name,double balance, double fee):Account{name,balance},fee{fee}
{ }

// --- withdraw (Specialized) ---
void Checking_Account::withdraw(double amount)
{
	amount += fee;
    Account::withdraw(amount);
}

// --- Print (Specialized) ---
void Checking_Account::print(std::ostream& os) const
{
	Account::print(os);
	os << " Fee: " << fee << "$";
}