/*
* ----------------------------------------------
* This program demonstrates sequential file
* input and parsing .csv files
*
* Created by Mengchuan Lin
* Mar 20, 2016
* ----------------------------------------------
*/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cstdlib>
#define DELIMITER ','

//function prototypes
void checkFile(std::istream &ifs);
std::vector<std::string> parseInputFile(std::istream &ifs);

int main()
{
	//create an input stream object
	std::ifstream ifs;

	//open file for input
	std::string fileName = "regDB.csv";
	ifs.open(fileName, std::ios::in);
	checkFile(ifs);

	//parse data and read from file
	std::cout << "*** Reading from " << fileName << " ***\n\n";
	std::vector<std::string> data = parseInputFile(ifs);

	//print parsed data to stdout
	int j = 0;
	for (std::vector<std::string>::const_iterator i = data.begin(); i != data.end(); ++i) {
		std::cout << *i;
		if (!(++j % 3)) //print a newrecord after processing three fields
			std::cout << '\n';
		else
			std::cout << ' ';
	}

	ifs.close();
}

void checkFile(std::istream &ifs)
{
	if (!ifs) {
		std::cerr << "File cannot be opened." << std::endl;
		exit(1);
	}
}

std::vector<std::string> parseInputFile(std::istream & ifs)
{
	std::vector<std::string> result;
	std::string record;
	//keep grabbing records from file until EOF
	while (std::getline(ifs, record)) {

		std::stringstream recordStream(record);
		std::string field;

		//parse record by extracting individual field from it and dump the delimiter
		while (std::getline(recordStream, field, DELIMITER)) {
			result.push_back(field);
		}
	}
	return result;
}
