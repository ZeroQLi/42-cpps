#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int	ft_error(int err)
{
	if (err == 1)
		std::cerr << "invalid number of arguments\n";
	else if (err == 2)
		std::cerr << "ERROR: invalid (or locked) file provided. Please enter a valid file\n";
	else if (err == 3)
		std::cerr << "ERROR: Unable to create new file. Please check permissions\n";
	std::cerr << "Usage: ./bettersed <filename> <string 1> <string 2>\n";
	exit(0);
}

int	read_and_replace(std::ifstream *infile, std::ofstream *outfile, std::string str1, std::string str2)
{
	std::string				str;
	std::string				before;
	std::string				after;
	std::string::size_type	result;

	while (getline((*infile), str))
	{
		result = str.find(str1);
		if (result != std::string::npos)
		{
			before = str.substr(0, result);
			after = str.substr((result + str1.length()), str.length());
			str = before + str2 + after;
		}
		if (!(*infile).eof())
			(*outfile) << str << std::endl;
		else
			(*outfile) << str;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		ft_error(1);

	std::string filename = argv[1];
	std::string resultname = filename + ".replace";

	std::ifstream Original(filename.std::string::c_str());
	if (!Original.is_open())
		ft_error(1);

	std::ofstream Result(resultname.std::string::c_str());
	if (!Result.is_open())
	{
		Original.close();
		ft_error(3);
	}
	read_and_replace(&Original, &Result, argv[2], argv[3]);
	Original.close();
	Result.close();
	return (0);
}
