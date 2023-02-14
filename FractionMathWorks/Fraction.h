#pragma once
#include <string>
#include <iostream>
class Fraction
{
public :
	Fraction(long num);
	Fraction(long num, long denom);
	Fraction(double num);

	std::string toString(bool mixedFractionRep) const;
	void reduce();

	// Operator overloads

	Fraction operator-() const;

	// Defined as friend functions to enable commutative property
	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);

	friend Fraction operator+(Fraction lhs, const Fraction& rhs);
	friend Fraction operator+(Fraction lhs, const long& rhs);
	friend Fraction operator+(Fraction lhs, const double& rhs);

	friend Fraction operator-(Fraction lhs, const Fraction& rhs);
	friend Fraction operator-(Fraction lhs, const long& rhs);
	friend Fraction operator-(Fraction lhs, const double& rhs);

	//Fraction multiplication results in Auto reduction of Fraction
	friend Fraction operator*(Fraction lhs, const Fraction& rhs);
	friend Fraction operator*(Fraction lhs, const long& rhs);
	friend Fraction operator*(Fraction lhs, const double& rhs);

	// Fraction dvision results in Auto reduction of Fraction
	friend Fraction operator/(Fraction lhs, const Fraction& rhs);
	friend Fraction operator/(Fraction lhs, const long& rhs);
	friend Fraction operator/(Fraction lhs, const double& rhs);

	// Overloading the spaceship operator instead of individual 
	// comparison operators
	friend auto operator<=>(const Fraction& lhs, const Fraction& rhs) {
		return lhs.comapre(rhs);
	}
	friend auto operator<=>(const Fraction& lhs, const long& rhs) {
		return lhs.comapre(Fraction(rhs));
	}
	friend auto operator<=>(const Fraction& lhs, const double& rhs) {
		return lhs.comapre(Fraction(rhs));
	}

	friend bool operator==(const Fraction& lhs, const Fraction& rhs) {
		return lhs <=> rhs == 0;
	}

	// Due to space
	friend bool operator==(const Fraction& lhs, const long& rhs) {
		return lhs <=> rhs == 0;
	}

	friend bool operator==(const Fraction& lhs, const double& rhs) {
		return lhs <=> rhs == 0;
	}


private :
	int64_t m_numerator;
	int64_t m_denominator;

	void init() {
		if (m_denominator == 0)
			throw std::invalid_argument("Denominator cannot be zero");

		int factor = pow(-1, m_denominator < 0);
		m_numerator = static_cast<int64_t>(m_numerator) * factor;
		m_denominator = static_cast<int64_t>(m_denominator) * factor;
	}

	std::strong_ordering comapre(const Fraction& b) const {
		int64_t l = lcm(m_denominator,b.m_denominator);
		int64_t a_lcm = m_numerator * (l / m_denominator);
		int64_t b_lcm = b.m_numerator * (l / b.m_denominator);
	
		return a_lcm <=> b_lcm;
	}

	static int64_t lcm(int64_t a, int64_t b) {
		return a * b / gcd(a, b);
	}

	static int64_t gcd(int64_t a, int64_t b) {
		while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	/*static int numberOfDecimalPlaces(double num) {
		int count = 0;
		int precision = pow(10, -10);
		while (num - floor(num) > precision) {
			std::cout << "Num : " << num << "Floor Num : " << floor(num) <<"  " << num - floor(num)<<std::endl;
			count++;
			num *= 10;
		}
		return count;
	}*/
	
};

