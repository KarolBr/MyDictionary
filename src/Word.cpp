#include "Word.h"
#include <vector>
#include <string>

std::string getDateAndTimeToString(const char *param = "%F %T")
{
    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream currTime;
    currTime << std::put_time(std::localtime(&t_c), param);
    return currTime.str();
}

void Word::setWord(std::string _word)
{
    word = _word;
}
void Word::setMeaning(std::string _meaning)
{
    meaning = _meaning;
}
void Word::setCreateDate(std::string _createDate)
{
    createDate = _createDate;
}

void Word::setUpdateDate()
{
    updateDate = getDateAndTimeToString();
}

void Word::setUpdateDate(std::string _updateDate)
{
    updateDate = _updateDate;
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

Word::Word(std::string _word, std::string _mean) : word(_word), meaning(_mean)
{
    createDate = getDateAndTimeToString();
    knowingLevel = {};
    updateDate = {};
    exampleSentences = {};
}

Word::~Word()
{
}

Word::Word(std::string s)
{
    std::vector<std::string> vec{};
    int pos{}, next_pos{};
    while (next_pos != -1)
    {
        next_pos = s.find(';', pos);
        vec.push_back(s.substr(pos, next_pos - pos));
        pos = next_pos + 1;
    }

    word = vec.at(0);
    meaning = vec.at(1);
    createDate = vec.at(2);
    updateDate = vec.at(3);
    knowingLevel = std::stoi(vec.at(4));
    exampleSentences.push_back(vec.at(5));
}
