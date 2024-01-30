#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &a);
		Bureaucrat &operator=(const Bureaucrat &a);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& a);

#endif