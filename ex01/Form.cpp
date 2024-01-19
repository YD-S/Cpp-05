//
// Created by Yash on 17/1/24.
//

#include "Form.hpp"

Form::Form(const std::string &name) : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false),
																		  _gradeToSign(gradeToSign),
																		  _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign),
							   _gradeToExecute(copy._gradeToExecute) {
	*this = copy;
}

Form &Form::operator=(Form const &rhs) {
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

Form::~Form() {}

std::string const &Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute "
		<< form.getGradeToExecute() << ", form is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << std::endl;
	return out;
}