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
		Bureaucrat me("me", 1);
		Bureaucrat meno("meno", 149);
		RobotomyRequestForm yoo("yoo");
		PresidentialPardonForm noo("noo");

		me.signForm(yoo);
		me.executeForm(yoo);

		meno.signForm(noo);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}