// FractionMathWorks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "Fraction.h"

void fractionInitializationTesting() {
    std::cout << "Initializing a fraction 2/3 : " << Fraction(2, 3) << std::endl;
    std::cout << "Initializing a fraction using int 1: " << Fraction((long)1) << std::endl;
    std::cout << "Initializing a fraction using double 2.345: " << Fraction(2.345) << std::endl;
    try {
        Fraction a = Fraction(1, 0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error while initializing with denominator 0 : " << e.what() << std::endl;
    }
}

void fractionAdditionTesting() {
    std::cout << "Adding two Fractions 1/2 + 2/3 :" << Fraction(1, 2) + Fraction(2, 3) << std::endl;
    long a = 2;
    std::cout << "Adding two Fractions 1/2 + 2 :" << Fraction(1, 2) + a << std::endl;
    std::cout << "Adding two Fractions 1/2 + 2.5 :" << Fraction(1, 2) + 2.5 << std::endl;
    std::cout << "Adding two fractions 1/2 + 0.0 : " << Fraction(1, 2) + 0.0 << std::endl;
}

void fractionSubtractionTesting() {
    std::cout << "Adding two Fractions 1/2 - 2/3 :" << Fraction(1, 2) - Fraction(2, 3) << std::endl;
    long a = 2;
    std::cout << "Adding two Fractions 1/2 - 2 :" << Fraction(1, 2) - a << std::endl;
    std::cout << "Adding two Fractions 1/2 - 2.5 :" << Fraction(1, 2) - 2.5 << std::endl;
    std::cout << "Adding two Fractions  2.5 - 2/3 :" <<  2.5 - Fraction(2, 3) << std::endl;

}

void fractionMultiplication() {
    std::cout << "Multiplying two fractions 2/3 * 3/2 : " << Fraction(2, 3) * Fraction(3, 2) << std::endl;
    long a = 0;
    std::cout << "Multiplying two fractions 2/3 * 0 : " << Fraction(2, 3) * a << std::endl;
}

void dividingFractions() {
    std::cout << "Dividing two fractions 2/3 / 3/2 :" << Fraction(2, 3) / Fraction(3, 2) << std::endl;
    try {
        Fraction a = Fraction(2, 3) / Fraction(0, 255);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error while dividing with numerator 0 : " << e.what() << std::endl;
    }
}

void comparisonOperations() {
    std::cout << "Comparing 2/3 < 5/6? : "<< (Fraction(2, 3) < Fraction(5, 6)) << std::endl;
    std::cout << "Comparing 2/3 > 5/6? : " << (Fraction(2, 3) > Fraction(5, 6)) << std::endl;
    std::cout << "Comparing 2/3 == 5/6? : " << (Fraction(2, 3) == Fraction(5, 6)) << std::endl;
    std::cout << "Comparing 2/3 != 5/6? : " << (Fraction(2, 3) != Fraction(5, 6)) << std::endl;
    std::cout << "Comparing 2/5 == 44/110? : " << (Fraction(2, 5) == Fraction(44, 110)) << std::endl;
}

int main()
{
    Fraction f = Fraction(0, -2);
    double d = 0.5;
    std::cout << "Hello World!\n" <<f <<"\n";
    fractionInitializationTesting();
    fractionAdditionTesting();
    fractionSubtractionTesting();
    fractionMultiplication();
    dividingFractions();
    comparisonOperations();
    std::cout << "Printing mixed fraction :" <<Fraction(5, 2).toString(true) << std::endl;
}


