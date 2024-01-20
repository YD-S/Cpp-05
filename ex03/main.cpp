//
// Created by Yashdev Singh on 1/16/24.
//

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(){
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");

	delete rrf;
}