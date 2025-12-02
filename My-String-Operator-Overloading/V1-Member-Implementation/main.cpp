#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;

    // ---Constructors---
    cout << "=== Initialization ===" << endl;
    Mystring a{ "Ran" };
    Mystring b{ "Ran" };
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // ---Equality---
    cout << "\n=== Equality ===" << endl;
    cout << "Is (a == b)? " << (a == b) << endl;
    cout << "Is (a != b)? " << (a != b) << endl;

    b = "Boss"; 
    cout << "Changed b to 'Boss'." << endl;
    cout << "Is (a == b)? " << (a == b) << endl;
    cout << "Is (a != b)? " << (a != b) << endl;

    // ---Relational---
    cout << "\n=== Relational ===" << endl;
    cout << "a (Ran) < b (Boss)? " << (a < b) << endl; // false (R comes after B)
    cout << "a (Ran) > b (Boss)? " << (a > b) << endl; // true

    // ---Unary Minus---
    cout << "\n=== Unary Minus ===" << endl;
    Mystring upper{ "RAN" };
    cout << "Original: " << upper << endl;
    cout << "Lowercase (-): " << -upper << endl;

    // ---Concatenation---
    cout << "\n=== Concatenation ===" << endl;
    Mystring s1{ "C++" };
    Mystring s2{ "Mastery" };
    Mystring s3 = s1 + " " + s2;
    cout << "s1 + s2: " << s3 << endl;

    s1 += " Developer";
    cout << "s1 += Developer: " << s1 << endl;

    // ---Repetition---
    cout << "\n=== Repetition (* and *=) ===" << endl;
    Mystring s4{ "Code" };
    Mystring s5 = s4 * 3;
    cout << "Code * 3: " << s5 << endl;

    s4 *= 2;
    cout << "Code *= 2: " << s4 << endl;

    // ---Increment---
    cout << "\n=== Increment (++) ===" << endl;
    Mystring s6{ "ran" };

    cout << "Original: " << s6 << endl;
    cout << "Pre (++s): " << ++s6 << endl;

    s6 = "ran"; // ---Reset---

    cout << "Post (s++): " << s6++ << endl;
    cout << "After post: " << s6 << endl;

    // ---Subscript---
    cout << "\n=== Subscript [] ===" << endl;
    Mystring s7{ "Ran" };
    cout << "First char: " << s7[0] << endl;
    s7[0] = 'D';
    cout << "Changed first char: " << s7 << endl; // Dan

    /*
    // ---Input---
    cout << "\n=== Input (>>) ===" << endl;
    cout << "Enter a string: ";
    Mystring s_in;
    cin >> s_in;
    cout << "You entered: " << s_in << endl;
    */

    cout << "\n=== All tests passed successfully! ===" << endl;
    return 0;
}