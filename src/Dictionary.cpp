#include "Dictionary.h"
#include "Word.h"

void Dictionary::addWord(Word word)
{
    words.push_back(word);
}

std::vector<Word> Dictionary::getWords()
{
    return words;
}

int Dictionary::sizeOfDictionary()
{
    return words.size();
}