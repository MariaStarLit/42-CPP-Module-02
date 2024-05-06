/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:47 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/06 23:27:58 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

//Constructor
Fixed::Fixed() : _value(0)
{}

Fixed::Fixed(const int nbr)
{this->_value = (nbr << this->_bits);}

Fixed::Fixed(const float nbr)
{this->_value = roundf(nbr * (1 << this->_bits));}

Fixed::Fixed(const Fixed &copy)
{*this = copy;}

//Destructor
Fixed::~Fixed()
{}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &copy)
{
	if(this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

//Arithmetic operators
Fixed	Fixed::operator+(const Fixed &plus)
{
	this->_value += plus.getRawBits() >> plus._bits;
	return (*this);
}

Fixed	Fixed::operator-(const Fixed &minus)
{
	this->_value -= minus.getRawBits() >> minus._bits;
	return (*this);
}

Fixed	Fixed::operator*(const Fixed &multiply)
{
	this->_value *= multiply.getRawBits() >> multiply._bits;
	return (*this);
}

Fixed	Fixed::operator/(const Fixed &divide)
{
	this->_value /= divide.getRawBits() >> divide._bits;
	return (*this);
}

//Incrementation operators
Fixed	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int i)
{
	(void)i;
	Fixed	temp(*this);
	this->_value++;
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int i)
{
	(void)i;
	Fixed	temp(*this);
	this->_value--;
	return (temp);
}

//Comparison operators
bool	Fixed::operator>(const Fixed &big)
{
	if (this->_value > big.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &bigger)
{
	if (this->_value >= bigger.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &small)
{
	if (this->_value < small.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &smaller)
{
	if (this->_value <= smaller.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &equal)
{
	if (this->_value == equal.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &diff)
{
	if (this->_value != diff.getRawBits())
		return true;
	return false;
}

//Max & Min Member Functions
Fixed		&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1._value < n2._value)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed		&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1._value > n2._value)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

//More Member Functions
int		Fixed::getRawBits( void ) const
{return (this->_value);}

void	Fixed::setRawBits( int const raw )
{this->_value = raw;}

int		Fixed::toInt( void ) const
{return (_value >> _bits);}

float	Fixed::toFloat( void ) const
{return ((float)_value / (1 << _bits));}

std::ostream	&operator<<(std::ostream &val, const Fixed &fix)
{return (val << fix.toFloat());}
