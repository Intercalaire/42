/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:13:13 by vgodart           #+#    #+#             */
/*   Updated: 2024/12/03 15:13:15 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string Replace(std::string s1, std::string s2, std::string str)
{
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return (str);
	}
	std::string result;
	size_t start = 0;
	size_t found;

	while ((found = str.find(s1, start)) != std::string::npos)
	{
		result += str.substr(start, found - start);
		result += s2;
		start = found + s1.length();
	}
	result += str.substr(start);
	return result;
}

int main(int argc, char **argv)
{
	if (!argv[2][0])
	{
		std::cout << "Error: empty string" << std::endl;
		return 1;
	}
	std::string copie_argv;
	std::string str;
	if (argc != 4)
	{
		std::cout << "Usage: ./SED_IS_FOR_LOSERS [file] [s1] [s2]" << std::endl;
		return 1;
	}
	std::ifstream fs(argv[1]);
	if (!fs.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return 1;
	}
	if (fs.is_open() && fs.peek() == std::ifstream::traits_type::eof())
    {
		std::cout << "Error: file is a folder or empty" << std::endl;
		return 1;
	}
	copie_argv = argv[1] + std::string(".replace");
	std::ofstream fs_copie(copie_argv.c_str());
	if (!fs.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return 1;
	}
	while (std::getline(fs, str))
	{
        std::string modified_line = Replace(argv[2], argv[3], str);
        fs_copie << modified_line;
        if (!fs.eof())
            fs_copie << '\n';
	}
	fs.close();
	return (0);

	
}
