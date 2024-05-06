/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:47 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/06 20:44:25 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (nbr << this->_bits);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(nbr * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
		this->_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{std::cout << "Destructor called" << std::endl;}

int		Fixed::getRawBits( void ) const
{return (this->_value);}

void	Fixed::setRawBits( int const raw )
{this->_value = raw;}

int		Fixed::toInt( void ) const
{return _value >> _bits;}

float	Fixed::toFloat( void ) const
{return ((float)_value / (1 << _bits));}

std::ostream	&operator<<(std::ostream &val, const Fixed &fix)
{return (val << fix.toFloat());}
