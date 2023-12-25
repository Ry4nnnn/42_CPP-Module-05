#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") {
	this->_grade = 0;
}

Bureaucrat::Bureaucrat(std::string _name)