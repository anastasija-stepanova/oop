#include "stdafx.h"
#include "CRational.h"
#include <iostream>

using namespace std;

unsigned Gcd(unsigned a, unsigned b)
{
	while (b != 0)
	{
		swap(a, b);
		b %= a;
	}
	return (a != 0) ? a : 1;
}

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw invalid_argument("Denominator must not be equal to zero");
	}

	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}

	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

const CRational CRational::operator-() const
{
	return CRational{ -m_numerator, m_denominator };
}

const CRational CRational::operator+() const
{
	return *this;
}

CRational& CRational::operator+=(const CRational& rhs)
{
	*this = *this + rhs;
	return *this;
}

CRational& CRational::operator-=(const CRational& rhs)
{
	*this = *this - rhs;
	return *this;
}

CRational& CRational::operator*=(const CRational& rhs)
{
	*this = *this * rhs;
	return *this;
}

CRational& CRational::operator/=(const CRational& rhs)
{
	*this = *this / rhs;
	return *this;
}

pair<int, CRational> CRational::ToCompoundFraction() const
{
	int integer = static_cast<int>(ToDouble());
	int numerator = m_numerator - (m_denominator * integer);

	return make_pair(integer, CRational(numerator, m_denominator));
}

void CRational::Normalize()
{
	int gcd = Gcd(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

const CRational operator+(const CRational& lhs, const CRational& rhs)
{
	auto numerator = (lhs.GetNumerator() * rhs.GetDenominator()) + (rhs.GetNumerator() * lhs.GetDenominator());
	auto denominator = lhs.GetDenominator() * rhs.GetDenominator();
	return CRational(numerator, denominator);
}

const CRational operator-(const CRational& lhs, const CRational& rhs)
{
	return lhs + (-rhs);
}

const CRational operator*(const CRational& lhs, const CRational& rhs)
{
	auto numerator = lhs.GetNumerator() * rhs.GetNumerator();
	auto denominator = lhs.GetDenominator() * rhs.GetDenominator();
	return CRational(numerator, denominator);
}

const CRational operator/(const CRational& lhs, const CRational& rhs)
{
	return lhs * CRational(rhs.GetDenominator(), rhs.GetNumerator());
}

bool operator==(const CRational& lhs, const CRational& rhs)
{
	return (lhs.GetNumerator() == rhs.GetNumerator()) && (lhs.GetDenominator() == rhs.GetDenominator());
}

bool operator!=(const CRational& lhs, const CRational& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const CRational& lhs, const CRational& rhs)
{
	return ((lhs.GetNumerator() * rhs.GetDenominator()) > (rhs.GetNumerator() * lhs.GetDenominator()));
}

bool operator>=(const CRational& lhs, const CRational& rhs)
{
	return (lhs > rhs) || (lhs == rhs);
}

bool operator<(const CRational& lhs, const CRational& rhs)
{
	return !(lhs >= rhs);
}

bool operator<=(const CRational& lhs, const CRational& rhs)
{
	return (lhs < rhs) || (lhs == rhs);
}

istream& operator>>(istream& stream, CRational& rational)
{
	auto currentPos = stream.tellg();
	unsigned numerator = 0;
	unsigned denominator = 1;
	if (!((stream >> numerator) && (stream.get() == '/') && (stream >> denominator)))
	{
		stream.seekg(currentPos);
	}
	rational = CRational(numerator, denominator);
	return stream;
}

ostream& operator<<(ostream& stream, const CRational& rational)
{
	stream << rational.GetNumerator() << "/" << rational.GetDenominator();
	return stream;
}
