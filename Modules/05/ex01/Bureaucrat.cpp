// #include "Bureaucrat.hpp" //Causes class redefinition
#include "Form.hpp"

Bureaucrat::Bureaucrat() { std::cout << "Default constructor\n"; }

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << "B.crat\t: Constructor\n";
}

Bureaucrat::~Bureaucrat() { std::cout << "B.crat\t: Destructor\n"; }

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << "B.crat\t: Copy constructor\n";
	}
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	// this->_name = rhs.getName(); name is const, can't be changed
	this->_grade = rhs.getGrade();
	std::cout << "B.crat\t: Assignment operator\n";
	return *this;
}

std::string const &Bureaucrat::getName(void) const { return this->_name; }

int Bureaucrat::getGrade(void) const { return this->_grade; }

std::ostream &operator<<(std::ostream &out, Bureaucrat const &instance)
{
	out << instance.getName() << ", bureaucrate grade: " << instance.getGrade() << "\n";
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "*Grade Too High*";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "*Grade Too Low*";
}

void Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

//To be called by Form::beSigned()
void Bureaucrat::signForm(Form &form) const
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		form.setIsSigned(true);
		std::cout << _name << " successfully signed [";
		std::cout << form.getFormName() << "] form\n";
	}
}
