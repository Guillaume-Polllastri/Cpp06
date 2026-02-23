/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:06:51 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/23 14:10:53 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cerrno>

/* ************************************************************************** */

// Canonical Form

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void) copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/* ************************************************************************** */

// Method

// Check_limits

static bool	check_overflow(const std::string& str)
{
	char	*endptr;
	double	doubleValue = std::strtod(str.c_str(), &endptr);

	if (errno == ERANGE || *endptr != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return true;
	}

	if (doubleValue < FLT_MIN || doubleValue > FLT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
		return true;
	}

	if (doubleValue < INT_MIN || doubleValue > INT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
		return true;
	}
	return false;
}

static bool	check_special(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}
	return false;
}

// Print Types

static void	printChar(char c)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: \'" << c << "\'"  << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void	printInt(const std::string& str)
{
	if (check_overflow(str))
		return ;
	
	int intValue = std::atoi(str.c_str());
	
	if (intValue < 32 || intValue > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
	}
	else
	{
		std::cout << "char: \'" << static_cast<char>(intValue) << "\'"  << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
	}
}

static void	printDouble(const std::string& str)
{
	if (check_special(str))
		return ;
	if (check_overflow(str))
		return ;
	double doubleValue = std::strtod(str.c_str(), NULL);
	
	if (doubleValue < 32 || doubleValue > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	}
	else
	{
		std::cout << "char: \'" << static_cast<char>(doubleValue) << "\'"  << std::endl;
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	}
}

static void	printFloat(const std::string& str)
{
	if (check_special(str))
		return ;
	if (check_overflow(str))
		return ;
	float floatValue = std::strtof(str.c_str(), NULL);
	
	if (floatValue < 32 || floatValue > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(floatValue) << std::endl;
	}
	else
	{
		std::cout << "char: \'" << static_cast<char>(floatValue) << "\'"  << std::endl;
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(floatValue) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(floatValue) << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	e_type	type = getType(str);

	switch (type)
	{
		case CHAR:
		{
			if (str.length() == 1)
				printChar(str[0]);
			else
				printChar(str[1]);
			break;
		}
		case INT:
		{
			printInt(str);
			break;
		}
		case FLOAT:
		{
			std::string str2 = str.substr(0, static_cast<int>(str.length()) - 1);
			printFloat(str2);
			break;
		}
		case DOUBLE:
		{
			printDouble(str);
			break;
		}
		case NOTHING:
			break;
	}
}

/* ************************************************************************** */
