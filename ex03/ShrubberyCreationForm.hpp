//
// Created by Yash on 19/1/24.
//

#ifndef CPP_05_SHRUBBERYCREATIONFORM_HPP
#define CPP_05_SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &execute) const;
	int getGradeToExecute() const;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src);


#endif //CPP_05_SHRUBBERYCREATIONFORM_HPP
