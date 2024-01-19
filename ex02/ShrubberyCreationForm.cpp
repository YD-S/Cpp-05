//
// Created by Yash on 19/1/24.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137),
																		 _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs)
		_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

int ShrubberyCreationForm::getGradeToExecute() const {
	return AForm::getGradeToExecute();
}

void ShrubberyCreationForm::execute(Bureaucrat const &execute) const {
	if (execute.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		std::ofstream file;
		file.open(_target + "_shrubbery");
		file << "      /\\\n"
				"     /\\*\\\n"
				"    /\\O\\*\\\n"
				"   /*/\\/\\/\\\n"
				"  /\\O\\/\\*\\/\\\n"
				" /\\*\\/\\*\\/\\/\\\n"
				"/\\O\\/\\/*/\\/O/\\\n"
				"      ||\n"
				"      ||\n"
				"      ||\n";
		file.close();
	}
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &src) {
	o << src.getName() << " is a ShrubberyCreationForm with a grade to sign of " << src.getGradeToSign()
	  << " and a grade to execute of " << src.getGradeToExecute() << "." << std::endl;
	return o;
}