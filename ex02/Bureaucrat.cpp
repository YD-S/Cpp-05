
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

void Bureaucrat::signForm(AForm &form) {
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " signed form " << form.getName() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << "Bureaucrat " << this->getName() << " couldn't sign form " << form.getName() << " because grade it's too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try
	{
		form.execute( *this );
		std::cout << "Bureaucrat " << this->getName() << " executed form " << form.getName() << std::endl;
	} catch (AForm::FormNotSigned &ex)
	{
		std::cout <<  "Bureaucrat " << this->getName() << " couldn't execute form " << form.getName()  << std::endl;
	}
}
