#pragma once
#include "Account.h"

class Checking_Account : public Account
{
private:
	static constexpr const char* def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_fee = 1.5;

public:
	Checking_Account(std::string def_name, double balance = def_balance, double fee = def_fee);

	bool deposit(double amount) override;
	bool withdraw(double amount) override;

	void print(std::ostream& os) const override;

	~Checking_Account() = default;

};
