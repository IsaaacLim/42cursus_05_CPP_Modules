#ifndef BUREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	Bureaucrat();

	std::string const _name;
	int _grade;

public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	virtual ~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string const &getName(void) const;
	int getGrade(void) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	void incrementGrade(void);
	void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &instance);

#endif