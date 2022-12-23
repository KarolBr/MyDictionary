#include "Word.h"
#include <vector>

void Word::setUpdateDate()
{
    updateDate = getDateAndTimeToString(); 
}

void Word::setExampleSentences(std::string _exampleSentences)
{
    setUpdateDate();
    exampleSentences.push_back(_exampleSentences);
}

void Word::setKnowingLevel(int _knowingLevel)
{
    setUpdateDate();
    knowingLevel = _knowingLevel;
}


std::string Word::getCreateDate()
{
    return createDate;
}

std::string Word::getUpdateDate()
{
    return updateDate;
}


std::string Word::getWord()
{
    return word;
}

std::string Word::getMeaning()
{
    return meaning;
}

std::vector<std::string> Word::getExampleSentences()
{
    return exampleSentences;
}

int Word::getKnowingLevel()
{
    return knowingLevel;
}

Word::~Word()
{
}
