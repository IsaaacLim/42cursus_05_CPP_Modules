#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Convert
{
private:
	Convert();

	//Functions
	void evaluateInput(void);
	void cast(void);
	// void cast_char(void);
	// void cast_int(void);
	// void cast_float(void);
	// void cast_double(void);

	//Variables
	std::string _input;
	int _type;

	enum e_type
	{
		eChar,
		eInt,
		eFloat,
		eDouble,
		eLong
		// eInvalid
	};

	//Values in correct type
	char _cValue;
	int _iValue;
	float _fValue;
	double _dValue;

	//Libft functions
	static bool ft_isascii(int c);
	static bool ft_isprint(int c);

public:
	Convert(std::string const &literal);
	~Convert();

	char getCValue(void) const;
	int getIValue(void) const;
	float getFValue(void) const;
	double getDValue(void) const;
};

std::ostream &operator<<(std::ostream &out, Convert const &instance);

#endif
