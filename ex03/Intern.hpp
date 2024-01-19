//
// Created by Yash on 19/1/24.
//

#ifndef CPP_05_INTERN_HPP
#define CPP_05_INTERN_HPP
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	Intern(Intern const &copy);
	Intern &operator=(Intern const &rhs);
	~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target);

	class InvalidFormException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif //CPP_05_INTERN_HPP
