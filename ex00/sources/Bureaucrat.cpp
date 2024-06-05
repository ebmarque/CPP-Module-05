/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:54:08 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/05 13:57:10 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	log(const char *color, std::string text)
{
	std::cout << color << text << RESET << std::endl;
}

Bureaucrat::Bureaucrat() 
{
	log(GREEN, "Bureaucrat default constructor called.");
	this->grade = 0;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
{
	// Copy constructor implementation
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other) 
	{
		// Copy assignment operator implementation
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() 
{
	// Destructor implementation
}

