//
// Created by Yashdev Singh on 1/16/24.
//

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
try
	{
		ShrubberyCreationForm home("home");
		Bureaucrat b1("yes", 1);
		Bureaucrat b2("no", 149);
		RobotomyRequestForm r1("yoo");
		PresidentialPardonForm p1("noo");

		b1.signForm(r1);
		b1.executeForm(r1);

		b2.signForm(p1);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}