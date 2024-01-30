#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string	_target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &a);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &a);
		~PresidentialPardonForm();

		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif