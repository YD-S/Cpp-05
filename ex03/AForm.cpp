//
// Created by Yash on 17/1/24.
//

#include "AForm.hpp"

AForm::AForm(const std::string &name) : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false),
																		  _gradeToSign(gradeToSign),
																		  _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign),
							   _gradeToExecute(copy._gradeToExecute) {
	*this = copy;
}

AForm &AForm::operator=(AForm const &rhs) {
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

AForm::~AForm() {}

std::string const &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormNotSigned::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute "
		<< form.getGradeToExecute() << ", form is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << std::endl;
	return out;
}
