#include "Fraction.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

/// <summary>
/// Creates a new instance of Fraction using the provided value for 
/// numerator and 1 for denominator.
/// </summary>
/// <param name="num"> Any integer value</param>
Fraction::Fraction(long num) : m_numerator(num), m_denominator(1) {}

/// <summary>
/// Creates a new instance of Fraction using the provided values for 
/// numerator and denominator.
/// Note: If Fraction is negative , the negative will only be applied to the 
/// numerator. Also if both the numerator and denominator are negative, both will be converted to 
/// be positive values
/// </summary>
/// <param name="numerator">any integer value</param>
/// <param name="denominator">any integer value apart from zero</param>
Fraction::Fraction(long numerator, long denominator) {
	m_numerator = numerator;
	m_denominator = denominator;
	init();
}


/// <summary>
/// Creates a new Fraction from a given Int. Uses a simple algorithm.
/// Assuming the double is of the form a.xyz it tries to create a fraction
/// of the form axyz/10^(nod), where nod is the number of decimal places in
/// a.xyz. This is then reduced by finding the gcd between the numerator and
/// denominator and dividing each by that.
/// </summary>
/// <param name="num"></param>
Fraction::Fraction(double num) {
	const long precision = 1000000000;
	m_numerator = round(num * precision);
	m_denominator = precision;
	init();
	this->reduce();
}


/// <summary>
/// Reduce the function to its base form. Reducing to the base form
// results in prime factorization of numerator and denominator and 
// removing factors common in the numerator and denominator
/// </summary>
void Fraction::reduce() {
	int64_t g = gcd(m_numerator, m_denominator);
	m_numerator /= g;
	m_denominator /= g;
}


/// <summary>
/// The function prints the string representation of the fraction
/// The fraction will be printed following the format of a/b
/// where a is the numerator and b is the demoinator. In case of a > b
/// and if the boolean passed is true then it returns the fraction in the mixed form
/// of c a/b
/// </summary>
/// <returns>
/// String representation of the fraction in a/b form
/// </returns>
std::string Fraction::toString(bool mixedNumberRepresentation = false) const{
	std::stringstream ss;
	if (m_numerator < m_denominator || !mixedNumberRepresentation) {
		ss << m_numerator << "/" << m_denominator;
	}
	else {
		ss << (m_numerator / m_denominator);
		if (m_numerator % m_denominator > 0)
			ss << " " << (m_numerator % m_denominator) << "/" << m_denominator;
	}
	return ss.str();
}

// Operator overload
Fraction Fraction::operator-() const
{
	return Fraction(-this->m_numerator, this->m_denominator);
}

/// <summary>
/// This lets the fraction be outputted into a stream
/// </summary>
/// <param name="os">The straem into which the object will be outputted to</param>
/// <param name="obj">The fraction that is to be outputted</param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	os << obj.toString(false);
	return os;
}

/// <summary>
/// Adds two fractions  
/// </summary>
/// <param name="other"></param>
/// <returns></returns>

Fraction operator+(Fraction lhs, const Fraction& rhs) {
	// find gcd
	int64_t g = Fraction::lcm(lhs.m_denominator, rhs.m_denominator);
	return Fraction((lhs.m_numerator * (g / lhs.m_denominator)) + rhs.m_numerator * (g / rhs.m_denominator), g);
}


Fraction operator+(Fraction lhs, const long& rhs)
{
	return lhs + Fraction(rhs);
}

Fraction operator+(Fraction lhs, const double& rhs)
{
	return lhs + (Fraction)rhs;
}


//Overloads for - operator
Fraction operator-(Fraction lhs, const Fraction& rhs)
{
	return lhs + -rhs;
}

Fraction operator-(Fraction lhs, const long& rhs)
{
	return lhs - Fraction(rhs);
}

Fraction operator-(Fraction lhs, const double& rhs)
{
	return lhs - Fraction(rhs);
}

// Overloads for * operator
Fraction operator*(Fraction lhs, const Fraction& rhs)
{
	Fraction response =  Fraction(lhs.m_numerator * rhs.m_numerator, lhs.m_denominator * rhs.m_denominator);
	response.reduce();
	return response;
}

Fraction operator*(Fraction lhs, const long& rhs)
{
	return lhs * Fraction(rhs);
}

Fraction operator*(Fraction lhs, const double& rhs)
{
	return lhs * Fraction(rhs);
}

// Overloads for / operator
Fraction operator/(Fraction lhs, const Fraction& rhs)
{
	if (rhs.m_numerator == 0)
		throw std::invalid_argument("Cannot divide by 0");
	return lhs * Fraction(rhs.m_denominator, rhs.m_numerator);
}

Fraction operator/(Fraction lhs, const long& rhs)
{
	return lhs / Fraction(rhs);
}

Fraction operator/(Fraction lhs, const double& rhs)
{
	return lhs/Fraction(rhs);
}










