//
// Created by Yashdev Singh on 1/16/24.
//

#include "Bureaucrat.hpp"

int main(){
	try {
		Bureaucrat bureaucrat("Yash", 52);
		std::cout << bureaucrat;
		while(bureaucrat.getGrade() > 1){
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}