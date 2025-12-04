#include <iostream>
#include <vector>
#include <memory> 
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"



using namespace std;

int main() {
    cout << "==================================================" << endl;
    cout << "       THE EMPEROR'S BANK - FULL DIAGNOSTIC       " << endl;
    cout << "==================================================" << endl;

    // --- TEST 1: CONSTRUCTOR FAILURE (Negative Balance) ---
    cout << "\n[TEST 1] Creating account with negative balance..." << endl;
    try {
        // trying to create an account with -500 should fail immediately
        std::unique_ptr<Account> bad_acc = std::make_unique<Checking_Account>("BadActor", -500);
    }
    catch (const IllegalBalanceException& ex) {
        cout << "PASS: Caught expected error: " << ex.what() << endl;
    }
    catch (...) {
        cout << "FAIL: Did account constructor check for negative balance?" << endl;
    }

    // --- Setup for Operational Tests ---
    vector<unique_ptr<Account>> accounts;
    try {
        accounts.push_back(make_unique<Checking_Account>("Batman", 1000));          // Index 0
        accounts.push_back(make_unique<Savings_Account>("Superman", 2000, 5.0));    // Index 1
        accounts.push_back(make_unique<Trust_Account>("Wonder Woman", 20000, 5.0)); // Index 2
    }
    catch (...) { cout << "Critical setup error." << endl; return 1; }

    // --- TEST 2: ILLEGAL DEPOSIT (Negative Amount) ---
    cout << "\n[TEST 2] Testing Negative Deposit (-100)..." << endl;
    try {
        accounts[0]->deposit(-100); // Should throw IllegalAmountException
        cout << "FAIL: Negative deposit was allowed!" << endl;
    }
    catch (const IllegalAmountException& ex) {
        cout << "PASS: Caught expected error: " << ex.what() << endl;
    }

    // --- TEST 3: CHECKING ACCOUNT FEE LOGIC ---
    cout << "\n[TEST 3] Testing Checking Account Fee (1.50$)..." << endl;
    try {
        // Batman has 1000. We withdraw 100.
        // Expectation: Balance should be 898.5 (1000 - 100 - 1.5)
        accounts[0]->withdraw(100);
        cout << "PASS: Withdraw successful. Current state: " << *accounts[0] << endl;
    }
    catch (const std::exception& ex) {
        cout << "FAIL: Unexpected error: " << ex.what() << endl;
    }

    // --- TEST 4: INSUFFICIENT FUNDS (Overdraft) ---
    cout << "\n[TEST 4] Testing Overdraft (Asking for too much)..." << endl;
    try {
        // Superman has 2000. Let's try to take 5000.
        accounts[1]->withdraw(5000);
        cout << "FAIL: Overdraft was allowed!" << endl;
    }
    catch (const InsufficientFundsException& ex) {
        cout << "PASS: Caught expected error: " << ex.what() << endl;
    }

    // --- TEST 5: TRUST ACCOUNT COMPLEX LOGIC ---
    cout << "\n[TEST 5] Trust Account Logic (Bonus, 20% limit, 3-Limit)..." << endl;
    auto& trust = accounts[2]; // Alias for Wonder Woman

    // A. Bonus Test
    cout << "  [5A] Depositing 6000 (Expect +50 bonus)..." << endl;
    trust->deposit(6000);
    cout << "       State: " << *trust << endl; // Check if balance increased by 6050

    // B. 20% Rule Test
    cout << "  [5B] Trying to withdraw > 20% of balance..." << endl;
    try {
        // Balance is ~26,050. 20% is ~5210. Let's try 6000.
        trust->withdraw(6000);
        cout << "FAIL: 20% rule was ignored!" << endl;
    }
    catch (const IllegalAmountException& ex) {
        cout << "PASS: Caught 20% violation: " << ex.what() << endl;
    }

    // C. 3-Withdrawal Limit Test
    cout << "  [5C] Testing 3-Withdrawal Limit..." << endl;
    for (int i = 1; i <= 5; i++) {
        try {
            cout << "       Attempt " << i << " ($10): ";
            trust->withdraw(10);
            cout << "Approved." << endl;
        }
        catch (const InsufficientFundsException& ex) {
            cout << "BLOCKED (" << ex.what() << ")" << endl;
        }
        catch (...) {
            cout << "ERROR: Unknown exception." << endl;
        }
    }

    cout << "\n==================================================" << endl;
    cout << "                 TESTING COMPLETE                 " << endl;
    cout << "==================================================" << endl;
    return 0;
}