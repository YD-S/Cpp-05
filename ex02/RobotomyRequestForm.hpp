//
// Created by Yash on 19/1/24.
//

#ifndef CPP_05_ROBOTOMYREQUESTFORM_HPP
#define CPP_05_ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm();
	RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

	int getGradeToSign() const;

	void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src);

#endif //CPP_05_ROBOTOMYREQUESTFORM_HPP
