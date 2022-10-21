#include "TextHider_lib.h"
#include <fstream>

enum LocalConstants
{
	hiding_percentage = 55
};

void HideText(const char* file_name)
{
	std::ifstream input_file(file_name);
	if (input_file.is_open())
	{
		std::ofstream output_file("output.txt", std::ios_base::trunc);
		while (!input_file.eof() && output_file.is_open())
		{
			std::string str_var;
			input_file >> str_var;
			ChangeStr(str_var);
			if (output_file.tellp() == 0)
				output_file << str_var;
			else
				output_file << '\n' << str_var;
		}
		output_file.close();
	}
	input_file.close();
}

void ChangeStr(std::string& str_var)
{
	unsigned remainder = CharRemainder(str_var.size());
	for (auto i = str_var.size() - 1; i >= remainder; --i)
		str_var[i] = '*';
}

unsigned CharRemainder(const size_t& str_size)
{
	double res = str_size * (1 - hiding_percentage / 100.0);
	return static_cast<unsigned>(res);
}
