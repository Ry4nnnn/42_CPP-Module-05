#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5) {
		this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", 25, 5) {
		this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : Form(a) {
	(*this) = a;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &a) {
	this->_target = a._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw Form::GradeNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}