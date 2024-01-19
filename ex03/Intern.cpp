//
// Created by Yash on 19/1/24.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &copy) {
	*this = copy;
}

Intern &Intern::operator=(Intern const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	AForm *form = NULL;

	if (formName == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else
		throw Intern::InvalidFormException();
	std::cout << "Intern creates " << formName << std::endl;
	return form;
}

const char *Intern::InvalidFormException::what() const throw() {
	return "Invalid form name";
}