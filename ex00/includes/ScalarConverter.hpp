/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:34:15 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/22 20:24:36 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void	convert(const std::string& str);
};