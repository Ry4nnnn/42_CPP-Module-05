#include "Form.hpp"

Form::Form() : _gradeToSign(150), _gradeToExec(150) {
	this->_signed = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
		_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(const Form &a) :
		_name(a._name), _gradeToSign(a._gradeToSign), _gradeToExec(a._gradeToExec) {
	this->_signed = a._signed;
	(*this) = a;
}

Form &Form::operator=(const Form &a) {
	this->_signed = a.getSigned();
	return (*this);
}

Form::~Form() {

}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const {
	return (this->_gradeToExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too High!.\n");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too Low!.\n");
}

std::ostream &operator<<(std::ostream& os, const Form& a) {
	os << "Form name: " << a.getName() << std::endl;
	os << "Grade to sign: " << a.getGradeToSign() << std::endl;
	os << "Grade to execute: " << a.getGradeToExec() << std::endl;
	os << "Signed: " << a.getSigned() << std::endl;
	return (os);
}