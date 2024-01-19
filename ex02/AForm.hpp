
#ifndef CPP_05_AFORM_HPP
#define CPP_05_AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	AForm(const std::string &name);
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &copy);
	AForm &operator=(AForm const &rhs);
	~AForm();

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat);

	virtual void    execute(Bureaucrat const & execute) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif //CPP_05_AFORM_HPP
