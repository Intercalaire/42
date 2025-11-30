/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 01:54:45 by vgodart           #+#    #+#             */
/*   Updated: 2025/06/25 01:54:47 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (target.empty())
		throw std::invalid_argument("Target cannot be an empty string");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw std::ios_base::failure("Failed to open file for writing");
	ofs << "         .         \n"
		   "        .         ;        \n"
		   " .              .              ;%     ;;   \n"
		   "   ,           ,                :;%  %;   \n"
		   "    :         ;                   :;%;'     .,   \n"
		   ",.        %;     %;            ;        %;'    ,;\n"
		   "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		   "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
		   "    ;%;      %;        ;%;        % ;%;  ,%;'\n"
		   "     `%;.     ;%;     %;'         `;%%;.%;'\n"
		   "      `:;%.    ;%%. %@;        %; ;@%;%'\n"
		   "        `:%;.  :;bd%;          %;@%;'\n"
		   "          `@%:.  :;%.         ;@@%;'\n"
		   "            `@%.  `;@%.      ;@@%;\n"
		   "              `@%%. `@%%    ;@@%;\n"
		   "                ;@%. :@%%  %@@%;\n"
		   "                  %@bd%%%bd%%:;\n"
		   "                    #@%%%%%:;;\n"
		   "                    %@@%%%::;\n"
		   "                    %@@@%(o);  . '\n"
		   "                    %@@@o%;:(.,'\n"
		   "                `.. %@@@o%::;\n"
		   "                   `)@@@o%::;\n"
		   "                    %@@(o)::;\n"
		   "                   .%@@@@%::;\n"
		   "                   ;%@@@@%::;.\n"
		   "                  ;%@@@@%%:;;.\n"
		   "              ...;%@@@@@%%:;;;;,..   \n";
	ofs.close();
	std::cout << "Shrubbery created at " << _target << "_shrubbery" << std::endl;
}
