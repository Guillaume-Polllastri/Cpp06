/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:01:28 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/23 11:04:24 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

static bool	isChar(const std::string& str)
{
	if (str.length() == 1)
		return (true);
	if (str.length() == 3)
	{
		if (str[0] == '\'' && str[2] == '\'')
			return (true);
	}
	return (false);
}

static bool	isInt(const std::string& str)
{
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < static_cast<int>(str.length()))
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	isDouble(const std::string& str)
{
	int i = 0;
	int	count = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '.' || str[static_cast<int>(str.length()) - 1] == '.')
		return (false);
	while (i < static_cast<int>(str.length()))
	{
		if (!std::isdigit(str[i]) && count == 1)
			return (false);
		if (str[i] == '.')
			count++;
		if (count > 1)
			return (false);
		i++;
	}
	if (count == 0)
		return (false);
	return (true);
}

static bool	isFloat(const std::string& str)
{
	std::string	str2;

	if (str[static_cast<int>(str.length()) - 1] != 'f')
		return (false);
	str2 = str.substr(0, static_cast<int>(str.length()) - 1);
	if (!isDouble(str2))
		return (false);
	return (true);
}

static bool	isSpecialFloat(const std::string& str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return (true);
	return false;
}

static bool	isSpecialDouble(const std::string& str)
{
	if (str == "nan" || str == "-inf" || str == "+inf")
		return (true);
	return false;
}

e_type	getType(const std::string& str)
{
	if (isChar(str))
		return (CHAR);
	if (isInt(str))
		return (INT);
	if (isDouble(str) || isSpecialDouble(str))
		return (DOUBLE);
	if (isFloat(str) || isSpecialFloat(str))
		return (FLOAT);
	return (NOTHING);
}