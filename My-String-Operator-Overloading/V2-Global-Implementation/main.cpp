#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    // Enable true/false printing instead of 1/0
    cout << boolalpha << endl;

    // --- 1. Constructors ---
    cout << "=== Initialization ===" << endl;
    Mystring a{ "Ran" };
    Mystring b{ "Boss" };
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // --- 2. Equality Operators ---
    cout << "\n=== Equality (==, !=) ===" << endl;
    cout << "Is (a == b)? " << (a == b) << endl;
    cout << "Is (a != b)? " << (a != b) << endl;

    // --- 3. Relational Operators ---
    cout << "\n=== Relational (<, >) ===" << endl;
    // Lexical comparison: "Boss" comes before "Ran"
    cout << "Is Boss < Ran? " << (b < a) << endl; // true
    cout << "Is Boss > Ran? " << (b > a) << endl; // false

    // --- 4. Concatenation (The Power of Global Functions!) ---
    cout << "\n=== Concatenation (+, +=) ===" << endl;
    Mystring s1{ "C++" };
    Mystring s2{ "Mastery" };

    // Regular concatenation
    Mystring s3 = s1 + " " + s2;
    cout << "s1 + s2: " << s3 << endl;

    // *** SYMMETRY TEST *** // This works ONLY because operator+ is a global friend function!

    // It allows conversion on the left-hand side ("Super " -> Mystring).
    Mystring s4 = "Super " + s1;
    cout << "Symmetry ('Super ' + s1): " << s4 << endl;

    // Compound assignment
    s1 += " Developer";
    cout << "s1 += Developer: " << s1 << endl;

    // --- 5. Repetition (*, *=) ---
    cout << "\n=== Repetition (*, *=) ===" << endl;
    Mystring s5{ "Code" };
    cout << "Code * 3: " << s5 * 3 << endl;

    s5 *= 2;
    cout << "Code *= 2: " << s5 << endl;

    // --- 6. Unary Minus (Lowercase) ---
    cout << "\n=== Unary Minus (-) ===" << endl;
    Mystring upper{ "RAN IS THE EMPEROR" };
    cout << "Original: " << upper << endl;
    cout << "Lowercase: " << -upper << endl;

    // --- 7. Increment (++, Upper) ---
    cout << "\n=== Increment (++, Pre/Post) ===" << endl;
    Mystring s6{ "ran" };

    cout << "Original: " << s6 << endl;
    cout << "Pre (++s): " << ++s6 << endl; // RAN (Immediate)

    s6 = "ran"; // Reset

    cout << "Post (s++): " << s6++ << endl; // ran (Old value)
    cout << "After Post: " << s6 << endl;   // RAN (New value)

    // --- 8. Subscript ([]) ---
    cout << "\n=== Subscript ([]) ===" << endl;
    Mystring s7{ "Ran" };
    cout << "First char: " << s7[0] << endl;
    s7[0] = 'D';
    cout << "Changed first char: " << s7 << endl; // Dan

    // --- 9. Input (Uncomment to test manually) ---
    /*
    cout << "\n=== Input (>>) ===" << endl;
    cout << "Enter a string: ";
    Mystring s_in;
    cin >> s_in;
    cout << "You entered: " << s_in << endl;
    */

    cout << "\n=== SUCCESS! Global Operators Challenge Complete! ===" << endl;
    return 0;
}