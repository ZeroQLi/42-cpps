#include "./iter.hpp"
#include <string>

void	square(int &num)
{
	num *= num;
}

void	to_upper(std::string &ref)
{
	for (size_t i = 0; i < ref.length(); i++)
		ref[i] = std::toupper(ref[i]);
}

int main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5};
	std::string strs[] = {"hello", "HI", "My", "n_a_m_e"};

	::iter(arr, 6, square);
	for (int i = 0; i < 6; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	::iter(strs, 4, to_upper);
	for (int i = 0; i < 4; i++)
		std::cout << strs[i] << " ";
	std::cout << std::endl;
}