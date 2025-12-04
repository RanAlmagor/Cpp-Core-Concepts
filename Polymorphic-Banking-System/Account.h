#pragma once
#include <iostream>
#include <string>
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"
#include "IllegalAmountException.h"
#include "IllegalNameException.h"

class Account : public I_printable
{
private:
  static constexpr const char *def_name= "Unnamed Account";
  static constexpr double def_balance = 0.0;

protected:
	std::string name;
	double balance;

public:
	Account(std::string name = def_name, double = def_balance);

	virtual void deposit(double amount);
	virtual void withdraw(double amount) = 0;

	void print(std::ostream& os) const override;

	virtual ~Account() = default;

};
