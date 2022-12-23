#include "Word.h"

void Word::setUpdateDate()
{
    updateDate = getDateAndTimeToString(); 
}

void Word::setExampleSentences(std::string _exampleSentences)
{
    setUpdateDate();
    exampleSentences = _exampleSentences;
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

std::string Word::getExampleSentences()
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
