//
// Created by Yashdev Singh on 1/16/24.
//

#include "Form.hpp"

int main(){
	Form foorm("foooorm");
	std::cout << foorm;


	Bureaucrat john("John", 5);
	Bureaucrat jaaax("Jaaax", 1);
	std::cout << john;
	std::cout << jaaax;

	try
	{
		john.signForm(foorm);
		jaaax.signForm(foorm);
		foorm.beSigned(john);
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}