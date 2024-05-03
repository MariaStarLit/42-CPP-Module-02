/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:50 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/03 19:36:08 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	bits = 8;

	public:
		Fixed(void); //Constructor
		//Copy constructor
		//Copy assignment operator
		~Fixed(); //Destructor

		//Member Functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};