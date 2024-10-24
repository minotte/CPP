/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:45:58 by nminotte          #+#    #+#             */
/*   Updated: 2023/09/11 15:13:44 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>

class PhoneBook
{
	 public:
		PhoneBook ( void );
		~PhoneBook ( void );
		void add( void );
		void search( void );
		void close();
	 private:
		int		_indexMax;
		int		_index;
		Contact	_instanceContact[8];
};

#endif
