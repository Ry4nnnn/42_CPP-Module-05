#include "Bureaucrat.hpp"

int main(void)
{
	std::string name;
	int grade;
	int symbol;
	std::string form_name;
	int g_sign;
	int g_exec;

	while (1)
	{
		std::cout << "---------- Bureaucrat Info----------" << std::endl;
		std::cout << "Enter name: ";
		std::cin >> name;
		std::cout << "Enter grade: ";
		std::cin >> grade;
		std::cout << "---------- Form Info ----------" << std::endl;
		std::cout << "Enter name: ";
		std::cin >> form_name;
		std::cout << "Enter grade for sign: ";
		std::cin >> g_sign;
		std::cout << "Enter grade for execute: ";
		std::cin >> g_exec;
		try{
			Bureaucrat user(name, grade);
			std::cout << user << std::endl;
			Form form(form_name, g_sign, g_exec);
			std::cout << form;
			try {
				std::cout << "Enter 1 to sign: ";
				std::cin >> symbol;
				if (symbol == 1)
					user.signForm(form);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
			std::cout << form;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}