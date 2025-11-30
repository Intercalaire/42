/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:11 by vgodart           #+#    #+#             */
/*   Updated: 2025/06/25 01:54:33 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		// Constructors
		AForm();
		AForm(const std::string name, const int sign_grade, const int execute_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		// Member fonctions
		void		beSigned(const Bureaucrat &bureaucrat);
		std::string getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		virtual void execute(const Bureaucrat &executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os,  AForm const &form);

#endif
