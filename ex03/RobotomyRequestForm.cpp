//
// Created by Yash on 19/1/24.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

int RobotomyRequestForm::getGradeToSign() const {
	return AForm::getGradeToSign();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		throw AForm::FormNotSigned();
	}
	else
	{
		std::srand(std::time(0));
		int randomNumber = std::rand() % (100 - 1 + 1) + 1;

		if ((randomNumber % 2) == 0)
		{
			std::cout << this->_target << " has been robotomized" << std::endl;
		}
		else
		{
			std::cout << "failed to robotomize " << this->_target << std::endl;
		}
	}
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src) {
	o << src.getName() << " is a RobotomyRequestForm with a grade to sign of " << src.getGradeToSign() << " and a grade to execute of " << src.getGradeToExecute() << "." << std::endl;
	return o;
}
