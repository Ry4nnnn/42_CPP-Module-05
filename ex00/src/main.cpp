#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "---------- User Test ----------" << std::endl;
	std::string name;
	int grade;
	char symbol;
	while (1)
	{
		std::cout << "Enter name: ";
		std::cin >> name;
		std::cout << "Enter grade: ";
		std::cin >> grade;
		try{
			Bureaucrat user(name, grade);
			std::cout << user;
			try{
				std::cout << "Enter +/-: ";
				std::cin >> symbol;
				if (symbol == '+')
					user.incrementGrade();
				if (symbol == '-')
					user.decrementGrade();
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
				return (0);
			}
			std::cout << user;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			return (0);
		}
	}
}