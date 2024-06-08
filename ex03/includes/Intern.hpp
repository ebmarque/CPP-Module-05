/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:19:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 23:17:07 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <algorithm>
#include <cctype>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <vector>

typedef struct s_forms
{
	AForm *form;
	struct s_forms *next;
}				t_forms;


class Intern
{
	private:
		t_forms *forms_list;
	public:
	
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		
		AForm			*makeForm(std::string formType, std::string target) const;
		void			add_front(AForm *form);
		static Intern&	getInstance(void);

	class noFormTypeEncountered : public std::exception
	{
		public:
			virtual const char *what() const throw() { return ("No Form type was encountered with the provided name.");}
	};
};


#endif // INTERN_HPP