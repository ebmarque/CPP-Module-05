/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:26:10 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 23:23:46 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() 
{
	log(GREEN, "Intern object created.");
	this->forms_list = NULL;
}

Intern::Intern(const Intern& other)
{
	this->forms_list = other.forms_list;
	log(GREEN, "Intern copy constructor called.");
}

Intern& Intern::operator=(const Intern& other) 
{
	if (this != &other)
		this->forms_list = other.forms_list;
	log(GREEN, "Intern copy assignment operator called.");
	return (*this);
}

Intern::~Intern() 
{
	log(RED, "Intern object destroyed.");
	t_forms *tmp = NULL;
	while (this->forms_list)
	{
		tmp = this->forms_list->next;
		delete this->forms_list->form;
		delete this->forms_list;
		this->forms_list = tmp;
	}
}

Intern& Intern::getInstance(void)
{
	static Intern intern;
	return (intern);
}

void	Intern::add_front(AForm *form)
{
	t_forms* new_item = new t_forms;
	
	new_item->form = form;
	new_item->next = this->forms_list;
	this->forms_list = new_item;
}

AForm *Intern::makeForm(std::string formType, std::string target) const
{
	formType.erase(std::remove(formType.begin(), formType.end(), ' '), formType.end());
	for (size_t i = 0; i < formType.size(); i++)
		formType[i] = toupper(formType[i]);
	if (!formType.compare("PRESIDENTIALPARDON"))
	{
		PresidentialPardonForm *form = new PresidentialPardonForm(target);
		log(CYAN, "Intern will create a: " + form->getName() + " targeted: " + target);
		getInstance().add_front(form);
		return (form);
	}
	else if (!formType.compare("ROBOTOMYREQUEST"))
	{
		RobotomyRequestForm *form = new RobotomyRequestForm(target);
		log(CYAN, "Intern will create a: " + form->getName() + " targeted: " + target);
		getInstance().add_front(form);
		return (form);
	}
	else if (!formType.compare("SHRUBBERYCREATION"))
	{
		ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
		log(CYAN, "Intern will create a: " + form->getName() + " targeted: " + target);
		getInstance().add_front(form);
		return (form);
	}
	else
		throw Intern::noFormTypeEncountered();
	
}

