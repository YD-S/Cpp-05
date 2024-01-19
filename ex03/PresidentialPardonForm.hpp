//
// Created by Yash on 19/1/24.
//

#ifndef CPP_05_PRESIDENTIALPARDONFORM_HPP
#define CPP_05_PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm();

	PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

	void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src);

#endif //CPP_05_PRESIDENTIALPARDONFORM_HPP
