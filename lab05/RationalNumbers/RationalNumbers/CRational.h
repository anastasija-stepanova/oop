#pragma once
#include <utility>

class CRational
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;
	double ToDouble() const;

	const CRational operator-() const;
	const CRational operator+() const;

	CRational& operator+=(const CRational & rhs);
	CRational& operator-=(const CRational & rhs);
	CRational& operator*=(const CRational & rhs);
	CRational& operator/=(const CRational & rhs);

	std::pair<int, CRational> ToCompoundFraction()const;
private:
	void Normalize();

	int m_numerator;
	int m_denominator;
};

const CRational operator+(const CRational & lhs, const CRational & rhs);
const CRational operator-(const CRational & lhs, const CRational & rhs);
const CRational operator*(const CRational & lhs, const CRational & rhs);
const CRational operator/(const CRational & lhs, const CRational & rhs);

bool operator==(const CRational & lhs, const CRational & rhs);
bool operator!=(const CRational & lhs, const CRational & rhs);
bool operator>(const CRational & lhs, const CRational & rhs);
bool operator>=(const CRational & lhs, const CRational & rhs);
bool operator<(const CRational & lhs, const CRational & rhs);
bool operator<=(const CRational & lhs, const CRational & rhs);

std::istream& operator>>(std::istream& stream, CRational & rhs);
std::ostream& operator<<(std::ostream& stream, const CRational & rhs);
