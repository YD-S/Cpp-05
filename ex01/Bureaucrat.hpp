//
// Created by Yashdev Singh on 1/16/24.
//

#ifndef CPP_05_BUREAUCRAT_HPP
#define CPP_05_BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat();

	void signForm(Form &form);

	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};


};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif //CPP_05_BUREAUCRAT_HPP
