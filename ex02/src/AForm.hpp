#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int	const			_gradeToExec;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &a);
		Form &operator=(const Form &a);
		virtual ~Form();

		std::string getName() const;
		bool		getSigned() const;
		int 		getGradeToSign() const;
		int 		getGradeToExec() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		virtual std::string	getTarget() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, const Form& a);

#endif