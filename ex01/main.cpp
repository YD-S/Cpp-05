//
// Created by Yashdev Singh on 1/16/24.
//

#include "Form.hpp"

int main(){
	Form form("Form1");
	std::cout << form;


	Bureaucrat john("John", 5);
	Bureaucrat jaaax("Jaaax", 1);
	std::cout << john;
	std::cout << jaaax;

	try
	{
		john.signForm(form);
		jaaax.signForm(form);
		form.beSigned(john);
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}