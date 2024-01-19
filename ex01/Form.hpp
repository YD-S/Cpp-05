
#ifndef CPP_05_FORM_HPP
#define CPP_05_FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	Form(const std::string &name);
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &copy);
	Form &operator=(Form const &rhs);
	~Form();

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif //CPP_05_FORM_HPP
