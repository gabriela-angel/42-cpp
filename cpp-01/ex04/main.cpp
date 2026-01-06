/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:00:19 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/06 19:54:26 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Error: Wrong format. Try: ./replace <file name> <string to be replaced> <new string>" << std::endl;
		return 1;
	}
	
	std::string oldStr;
	std::string newStr;
	std::string newFileName;
	std::string line;
	std::fstream file(argv[1], std::ios::in);

	if (!file.is_open()) {
		std::cerr << "Error: could not open file \" " << argv[1] << "\"" << std::endl;
		return 2;
	}	

	newFileName = std::string("updated_") + argv[1];
	std::fstream newFile(newFileName.c_str(), std::ios::out);
	
	if (!newFile.is_open()) {
		std::cerr << "Error: could not create file \"" << newFileName << "\"" << std::endl;
		file.close();
		return 3;
	}
	if (!getline(file, line)) {
		std::cerr << "Error: Failed to read data" << std::endl;
		file.close();
		return 4;
	}

	oldStr = argv[2];
	newStr = argv[3];
	std::size_t pos = line.find(oldStr);
	
	while (pos!=std::string::npos) {
		ftReplace(pos, oldStr.length(), line, newStr);
		pos = line.find(oldStr);
	}
	newFile << line;
	while (getline(file, line)) {
		newFile <<std::endl;
		pos = line.find(oldStr);
		while (pos != std::string::npos) {
			ftReplace(pos, oldStr.length(), line, newStr);
			pos = line.find(oldStr);
		}
		newFile << line;
	}
	if (!file.eof()) {
		std::cerr << "Error: Failed to read data" << std::endl;
		file.close();
		newFile.close();
		remove(newFileName.c_str());
		return 5;
	}
	file.close();
	newFile.close();
	
	return 0;
}
