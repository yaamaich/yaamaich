#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{
}

Fixed::Fixed(const float f) : _fixedPointValue(roundf(f * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return _fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return _fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return _fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return _fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return _fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return _fixedPointValue != rhs._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed result;
	result._fixedPointValue = _fixedPointValue + rhs._fixedPointValue;
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed result;
	result._fixedPointValue = _fixedPointValue - rhs._fixedPointValue;
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed result;
	result._fixedPointValue = (_fixedPointValue * rhs._fixedPointValue) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed result;
	result._fixedPointValue = (_fixedPointValue << _fractionalBits) / rhs._fixedPointValue;
	return result;
}

Fixed& Fixed::operator++()
{
	++_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_fixedPointValue;
	return tmp;
}

Fixed& Fixed::operator--()
{
	--_fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_fixedPointValue;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
