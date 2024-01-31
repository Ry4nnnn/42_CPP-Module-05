#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45) {
		this->_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 72, 45) {
		this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : Form(a) {
	(*this) = a;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {
	this->_target = a._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw Form::GradeNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	else
	{
		srand(time(nullptr));
		int success_rate = rand();
		std::cout << "Makes drilling noises..." << std::endl;
		if (success_rate % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << this->_target << " robotomy failed." << std::endl;
	}
}

