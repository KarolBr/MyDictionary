#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
// #include "tools.h"

//std::string getDateAndTimeToString(const char *param = "%F %T");

class Word
{
private:
    /* data */
    std::string word;
    std::string meaning;
    std::string createDate;
    std::string updateDate;
    std::vector<std::string> exampleSentences;
    int knowingLevel;
    void setUpdateDate();

    std::string getDateAndTimeToString(const char *param = "%F %T")
    {
        const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
        std::stringstream currTime;
        currTime << std::put_time(std::localtime(&t_c), param);
        return currTime.str();
    }

public:
    /* behaviour */

    Word(std::string _word, std::string _mean) : word(_word), meaning(_mean)
    {
        createDate = getDateAndTimeToString();
        knowingLevel = {};
	    updateDate = {};
	    exampleSentences = {};
    }

    
    void setExampleSentences(std::string _exampleSentences);
    void setKnowingLevel(int _knowingLevel);

    std::string getCreateDate();
    std::string getUpdateDate();
    std::string getWord();
    std::string getMeaning();
    std::vector<std::string> getExampleSentences();
    int getKnowingLevel();

    friend std::ostream& operator<<(std::ostream& os,Word& word)
	{
		os<<word.getWord() << " ; "  
        << word.getMeaning() << " ; "
        << word.getCreateDate() << " ; "
        << word.getUpdateDate() << " ; "
        << word.getKnowingLevel() << " ; ";
        for(std::string sentence: word.getExampleSentences()){
            os<<sentence<< " ; ";
        }
        os << std::endl;
		return os;
	}

    friend std::istream& operator>>(std::istream& in, Word& word)
    {
	    // read member variables of f
	    return in;
    }

    ~Word();
};

#endif // Word.h
