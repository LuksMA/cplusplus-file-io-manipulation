/*
* ----------------------------------------------
* This program demonstrates sequential file
* output
*
* Created by Mengchuan Lin
* Mar 20, 2016
* ----------------------------------------------
*/

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#define S 30
#define DELIMITER ','

//function prototypes
void checkFile(std::ostream &ofs);
void writeData(std::ostream &ofs, char *, bool);

int main()
{
	//create an output stream object
	std::ofstream ofs;

	//open file for output
	std::string fileName = "regDB.csv";
	ofs.open(fileName, std::ios::out);
	checkFile(ofs);
	char data[S];

	//prompt user for data and write to file
	std::cout << "*** Writing to file ***\n\n";
	std::cout << "Enter first name: ";
	writeData(ofs, data, false);

	std::cout << "Enter last name: ";
	writeData(ofs, data, false);

	std::cout << "Enter email address: ";
	writeData(ofs, data, true);

	std::cout << "\nYour data has been saved in " << fileName << std::endl;
	
	ofs.close();
}

void checkFile(std::ostream &ofs)
{
	if (!ofs) {
		std::cerr << "File cannot be opened." << std::endl;
		exit(1);
	}
}

void writeData(std::ostream &ofs, char *data, bool newline)
{
	std::cin.getline(data, S);
	if (!newline)
		ofs << data << DELIMITER;
	else
		ofs << data << std::endl;
}
