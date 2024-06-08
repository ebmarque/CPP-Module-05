/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 18:06:11 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
	log(GREEN, this->getName() + " Created.");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) \
	: AForm(other.getName(), other.getGradeSign(), other.getGradeExecute()), _target(other._target) 
{
	log(GREEN, this->getName() + " Created by default copy constructor");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
	if (this != &other) 
		this->_target = other._target;
		
	log(GREEN, this->getName() + " Created by copy assignment operator");
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	log(RED, this->getName() + " Destroyed.");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  log(CYAN, this->getName() + ": Execute method called.");
  if (!this->getSigned())
    throw AForm::FormNotSignedException();
  else if (executor.getGrade() > this->getGradeExecute())
    throw AForm::GradeTooLowException();
  
  std::ofstream form((this->getName() + "_Shrubbery").c_str());

  form << "░░░░░░░▄█▄▄▄█▄\n"
      "▄▀░░░░▄▌─▄─▄─▐▄░░░░▀▄\n"
      "█▄▄█░░▀▌─▀─▀─▐▀░░█▄▄█\n"
      "░▐▌░░░░▀▀███▀▀░░░░▐▌\n"
      "████░▄█████████▄░████\n";
  
}

