#include "Checking_Account.h"

// --- Constructor ---
Checking_Account::Checking_Account(std::string name,double balance, double fee):Account{name,balance},fee{fee}
{ }

bool Checking_Account::withdraw(double amount)
{
	amount += fee;
	return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream& os) const
{
	Account::print(os);
	os << " Fee: " << fee << "$";
}