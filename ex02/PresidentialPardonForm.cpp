//
// Created by Yash on 19/1/24.
//

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned()) {
		throw std::exception();
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	} else {
		std::cout << this->_target << " has been pardoned by Joe Biden." << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src) {
	o << src.getName() << " is a form with a grade to sign of " << src.getGradeToSign() << " and a grade to execute of " << src.getGradeToExecute() << ". It is currently " << (src.getSigned() ? "signed." : "not signed.") << std::endl;
	return o;
}