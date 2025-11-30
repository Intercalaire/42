/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:11 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:13 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;

	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(std::string name, unsigned long grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Member functions
        std::string getName(void) const;
        int      getGrade(void) const;
        void        promote();
        void        demote();
		void		signForm(AForm &form);
		void		executeForm(const AForm &form);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);

#endif