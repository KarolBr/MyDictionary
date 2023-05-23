#ifndef MYFILE_H
#define MYFILE_H
#include <iostream>
#include <fstream>
#include "Dictionary.h"

class MyFile
{
public:

	MyFile(std::string fileName): fileName(fileName)
	{
		//myFile.open(fileName,std::ios::app);
		std::cout<<"I'm opening file ..."<<std::endl;
	}

	void saveFile(Dictionary &dict);
	void loadFile(Dictionary &dict);

	~MyFile()
	{
		myFile.close();
		std::cout<<"I'm closeing file ..."<<std::endl;
	}

private:
	std::string fileName;
	std::fstream myFile;
};

#endif //MyFile.h
