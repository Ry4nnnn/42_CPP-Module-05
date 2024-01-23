#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") {
	this->_grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) {
	(*this) = a;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a) {
	this->_grade = a._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {

}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too High!, highest grade is 1.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too Low!, lowest grade is 150.\n");
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& a) {
	os << a.getName() << ", Bureaucrat Grade: " << a.getGrade() << std::endl;
	return (os);
}
