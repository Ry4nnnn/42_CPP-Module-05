#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
		int	getGrade() const;
		void	increamentGrade();
		void	decreamentGrade();

		class GradeTooHighException : public std::exception

}

#endif