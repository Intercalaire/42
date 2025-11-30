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

class	Bureaucrat
{
    public:
    // Constructors
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(std::string name, size_t grade);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

    // Member functions
        std::string getName(void) const;
        size_t getGrade(void) const;
        void    promote();
        void    demote();
        void    incrementGrade();
        void    decrementGrade();

    // Exceptions
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
    
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

    private:
        const std::string _name;
        size_t _grade;
};


std::ostream	&operator<<(std::ostream &o, const Bureaucrat& copy);

#endif

