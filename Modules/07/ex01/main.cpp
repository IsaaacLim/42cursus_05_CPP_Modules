#include "iter.hpp"

/*
** Class given by 42 during the eval
*/
class Awesome
{
private:
	int _n;
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <typename T>
void ft_print(T &var)
{
	std::cout << std::boolalpha << var << " ";
}

template <typename T>
void ft_toupper(T &var)
{
	if (var >= 'a' && var <= 'z')
		var -= ' ';
}

template <typename T>
void ft_str_toupper(T &arr)
{
	for (int i = 0; arr[i]; i++)
		ft_toupper(arr[i]);
}

int main(void)
{
	// My test
	{
		int arr_size;

		// --- Integers --- //
		int int_arr[] = {1, 2, 3, 4, 5};
		arr_size = sizeof(int_arr) / sizeof(int_arr[0]);

		std::cout << "Integers\t: ";
		::iter(int_arr, arr_size, &ft_print);
		std::cout << "\n\n";

		// --- Characters --- //
		char char_arr[] = {'a', 'b', 'C', 'D', '1', '2', '!', 'z'};
		arr_size = sizeof(char_arr) / sizeof(char_arr[0]);

		std::cout << "Characters\t: ";
		::iter(char_arr, arr_size, &ft_print);
		std::cout << "\nft_toupper\t: ";
		::iter(char_arr, arr_size, &ft_toupper);
		::iter(char_arr, arr_size, &ft_print);
		std::cout << "\n\n";

		// --- Strings --- //
		std::string str_arr[] = {"This", "is", "a", "string"};
		arr_size = sizeof(str_arr) / sizeof(str_arr[0]);

		std::cout << "Strings\t\t: ";
		::iter(str_arr, arr_size, &ft_print);
		std::cout << "\nft_str_toupper\t: ";
		::iter(str_arr, arr_size, &ft_str_toupper);
		::iter(str_arr, arr_size, &ft_print);
		std::cout << "\n\n";

		// --- Booleans --- //
		bool bool_arr[] = {true, false, true, true};
		arr_size = sizeof(bool_arr) / sizeof(bool_arr[0]);

		std::cout << "Boolean\t\t: ";
		::iter(bool_arr, arr_size, &ft_print);
		std::cout << "\n\n";
	}

	// Intra test
	{
		int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
		Awesome tab2[5];

		std::cout << "Awesome\t\t: ";
		iter( tab, 5, ft_print );
		std::cout << "\nAwesome (empty)\t: ";
		iter( tab2, 5, ft_print );
		std::cout << std::endl;
	}
}
