//James Magana
// Lab 9
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

class FractionException : public exception {
private:
    string errorMessage;
public:
    FractionException(const string& message);
    const string& getErrorMessage() const;
};

class Fraction {
private:
    int numerator = 1;
    int denominator = 1;
    static const int DEFAULT_NUMERATOR = 1;
    static const int DEFAULT_DENOMINATOR = 1;

    void validateFraction() const;

public:
    Fraction(int numeratorValue = DEFAULT_NUMERATOR, int denominatorValue = DEFAULT_DENOMINATOR);
    
    // Base arithmetic operators
    Fraction operator*(const Fraction& otherFraction) const;
    Fraction operator-(const Fraction& otherFraction) const;
    Fraction operator/(const Fraction& otherFraction) const;
    
    // Mixed-type operations
    friend Fraction operator-(int integerValue, const Fraction& fractionValue);
    friend Fraction operator-(const Fraction& fractionValue, int integerValue);
    friend Fraction operator/(int integerValue, const Fraction& fractionValue);
    friend Fraction operator/(const Fraction& fractionValue, int integerValue);
    
    string toString() const;
};

enum MenuOption { 
    DEMO_OPERATORS = 1, 
    QUIT
};

// Function prototypes
void testMultiplication();
void testFractionSubtraction();
void testIntegerSubtraction();
void testDivision();
void testComplexOperations();
void demonstrateOperators();
void printTestHeader(const string& testName);
void printMenu();

int main() {
    int choice;
    
    do {
        printMenu();
        cin >> choice;
        
        switch (choice) {
            case DEMO_OPERATORS:
                demonstrateOperators();
                break;
                
            case QUIT:
                break;
                
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please try again.\n";
        }
    } while (choice != QUIT);

    return 0;
}

// FractionException implementation
FractionException::FractionException(const string& message) : errorMessage(message) {}

const string& FractionException::getErrorMessage() const { 
    return errorMessage; 
}

// Fraction Class member implementations
void Fraction::validateFraction() const {
    if (denominator == 0) throw FractionException("Denominator cannot be zero");
    if (numerator < 0 || denominator < 0) throw FractionException("Fraction cannot be negative");
}

Fraction::Fraction(int numeratorValue, int denominatorValue) 
    : numerator(numeratorValue), denominator(denominatorValue) { 
    validateFraction(); 
}

Fraction Fraction::operator*(const Fraction& otherFraction) const {
    return Fraction(numerator * otherFraction.numerator, denominator * otherFraction.denominator);
}

Fraction Fraction::operator-(const Fraction& otherFraction) const {
    return Fraction(numerator * otherFraction.denominator - otherFraction.numerator * denominator,
        denominator * otherFraction.denominator);
}

Fraction Fraction::operator/(const Fraction& otherFraction) const {
    if (otherFraction.numerator == 0) throw FractionException("Cannot divide by zero");
    return Fraction(numerator * otherFraction.denominator, denominator * otherFraction.numerator);
}

// Mixed-type operations (to handle opposite order)
Fraction operator-(int integerValue, const Fraction& fractionValue) {
    return Fraction(integerValue) - fractionValue;
}

Fraction operator-(const Fraction& fractionValue, int integerValue) {
    return fractionValue - Fraction(integerValue);
}

Fraction operator/(int integerValue, const Fraction& fractionValue) {
    return Fraction(integerValue) / fractionValue;
}

Fraction operator/(const Fraction& fractionValue, int integerValue) {
    return fractionValue / Fraction(integerValue);
}

string Fraction::toString() const {
    return to_string(numerator) + "/" + to_string(denominator);
}

// Test functions
void printTestHeader(const string& testName) {
    cout << "\n--- Testing " << testName << " ---" << endl;
}

void testMultiplication() {
    printTestHeader("multiplication operator (*)");
    Fraction firstFraction(3, 7);
    Fraction secondFraction(5, 9);
    cout << firstFraction.toString() << " * " << secondFraction.toString() 
         << " = " << (firstFraction * secondFraction).toString() << endl;
}

void testFractionSubtraction() {
    printTestHeader("fraction subtraction (-)");
    Fraction largerFraction(5, 6);
    Fraction smallerFraction(1, 3);
    cout << largerFraction.toString() << " - " << smallerFraction.toString() 
         << " = " << (largerFraction - smallerFraction).toString() << endl;
}

void testIntegerSubtraction() {
    printTestHeader("integer subtraction (-)");
    Fraction testFraction(3, 7);
    cout << "5 - " << testFraction.toString() << " = " << (5 - testFraction).toString() << endl;
}

void testDivision() {
    printTestHeader("division operator (/)");
    Fraction firstFraction(3, 7);
    Fraction secondFraction(5, 21);
    cout << firstFraction.toString() << " / " << secondFraction.toString() 
         << " = " << (firstFraction / secondFraction).toString() << endl;
}

void testComplexOperations() {
    printTestHeader("complex operations");
    Fraction firstFraction(5, 6);
    Fraction secondFraction(8, 9);
    cout << "(" << secondFraction.toString() << " - " << firstFraction.toString() << ") / 4 = " 
         << ((secondFraction - firstFraction) / 4).toString() << endl
         << "2 / " << secondFraction.toString() << " * " << firstFraction.toString() << " = " 
         << (2 / secondFraction * firstFraction).toString() << endl;
}

void demonstrateOperators() {
    try {
        testMultiplication();
        testFractionSubtraction();
        testIntegerSubtraction();
        testDivision();
        testComplexOperations();
    } catch (const FractionException& error) {
        cerr << "Error: " << error.getErrorMessage() << endl;
    }
}

void printMenu() {
    cout << "\n1. Demonstrate operator overloading\n"
         << "2. Quit\n"
         << "Enter your choice: ";
}
/*
/*OUTPUT TRIALS:
// Menu Output and error handling:
1. Demonstrate operator overloading
2. Quit
Enter your choice: b
Invalid input. Please try again.   

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1
You've demonstrated the operator overloading.

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

-------------------------------------------------------------------------------------
// Multiplication operator tests:

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

// (seperate test)

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
2/5 * 3/11 = 6/55

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

-------------------------------------------------------------------------------------
// Subtraction operator tests:

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

// (seperate test)

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
7/8 - 2/4 = 12/32

--- Testing integer subtraction (-) ---
5 - 2/3 = 16/3

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

--------------------------------------------------------------------------------------
// Division operator tests:

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

--- Testing division operator (/) ---
3/7 / 5/21 = 63/35

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

// (seperate test)

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

--- Testing division operator (/) ---
3/7 / 5/21 = 63/35

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

// (seperate test)

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

--- Testing division operator (/) ---
2/5 / 3/17 = 34/15

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

--------------------------------------------------------------------------------------
// Complex operations tests:

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

--- Testing division operator (/) ---
3/7 / 5/21 = 63/35

--- Testing complex operations ---
(5/9 - 3/7) / 4 = 8/252
2 / 5/9 * 3/7 = 54/35

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

// (seperate test)

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

--- Testing division operator (/) ---
3/7 / 5/21 = 63/35

--- Testing complex operations ---
(7/9 - 5/6) / 4 = Error: Fraction cannot be negative

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2

// (seperate test)

1. Demonstrate operator overloading
2. Quit
Enter your choice: 1

--- Testing multiplication operator (*) ---
3/7 * 5/9 = 15/63

--- Testing fraction subtraction (-) ---
5/6 - 1/3 = 9/18

--- Testing integer subtraction (-) ---
5 - 3/7 = 32/7

--- Testing division operator (/) ---
3/7 / 5/21 = 63/35

--- Testing complex operations ---
(8/9 - 5/6) / 4 = 3/216
2 / 8/9 * 5/6 = 90/48

1. Demonstrate operator overloading
2. Quit
Enter your choice: 2
*/
