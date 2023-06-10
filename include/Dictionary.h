#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include "Word.h"

class Dictionary
{
public:
    Dictionary(){}
    void addWord(Word word);
    std::vector<Word> getWords();
    int sizeOfDictionary();
    void cleanDictionary();

private:
    std::vector<Word> words; 


};


#endif // Dictionary.h