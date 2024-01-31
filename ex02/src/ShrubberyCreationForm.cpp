#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137) {
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : Form(a) {
	(*this) = a;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
	this->_target = a._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw Form::GradeNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	else
	{
		std::ofstream outfile(this->_target + "_shrubbery");
		outfile << "                                              .\n";
		outfile << "                                   .         ;\n";
		outfile << "      .              .              ;%     ;;\n";
		outfile << "        ,           ,                :;%  %;\n";
		outfile << "         :         ;                   :;%;'     .,\n";
		outfile << ",.        %;     %;            ;        %;'    ,;\n";
		outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
		outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
		outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
		outfile << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
		outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
		outfile << "         `:%;.  :;bd%;          %;@%;'\n";
		outfile << "           `@%:.  :;%.         ;@@%;'\n";
		outfile << "             `@%.  `;@%.      ;@@%;\n";
		outfile << "               `@%%. `@%%    ;@@%;\n";
		outfile << "                 ;@%. :@%%  %@@%;\n";
		outfile << "                   %@bd%%%bd%%:;\n";
		outfile << "                     #@%%%%%:;;\n";
		outfile << "                     %@@%%%::;\n";
		outfile << "                     %@@@%(o);  . '\n";
		outfile << "                     %@@@o%;:(.,'\n";
		outfile << "                 `.. %@@@o%::;\n";
		outfile << "                    `)@@@o%::;\n";
		outfile << "                     %@@(o)::;\n";
		outfile << "                    .%@@@@%::;\n";
		outfile << "                    ;%@@@@%::;.\n";
		outfile << "                   ;%@@@@%%:;;;.\n";
		outfile << "               ...;%@@@@@%%:;;;;,..\n";
		outfile.close();
		std::cout << this->_target << "_shrubbery file has been created." << std::endl;
	}


}