#include <iostream>
#include <fstream>
#include "MyFile.h"
#include "Dictionary.h"


void MyFile::saveFile(Dictionary dict)
{
    if(!myFile.is_open())
        myFile.open(fileName,std::ios::app);
    
    for(Word word: dict.getWords())
        myFile<<word;

    myFile.close();
}


void MyFile::loadFile(Dictionary dict)
{
    std::string lineFromFile;
    if(!myFile.is_open())
        myFile.open(fileName,std::ios::in);
    Word w1("treatment","traktowanie,leczenie,opieka lekarska");
    dict.addWord(w1);
    while(getline(myFile,lineFromFile)){
        std::cout<<lineFromFile<<std::endl;
    }
    myFile.close();
}