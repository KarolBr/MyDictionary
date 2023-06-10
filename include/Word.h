#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>


// std::string getDateAndTimeToString(const char *param = "%F %T");


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
    
public:
    /* behaviour */

    Word(std::string _word, std::string _mean);

    Word(std::string line);
    

    Word(){};

    void setWord(std::string);
    void setMeaning(std::string);
    void setCreateDate(std::string);
    void setExampleSentences(std::string _exampleSentences);
    void setKnowingLevel(int _knowingLevel);
    void setUpdateDate(std::string _updateDate);

    std::string getCreateDate();
    std::string getUpdateDate();
    std::string getWord();
    std::string getMeaning();
    std::vector<std::string> getExampleSentences();
    int getKnowingLevel();

    friend std::ostream &operator<<(std::ostream &os, Word &word)
    {
        os << word.getWord() << " ; "
           << word.getMeaning() << " ; "
           << word.getCreateDate() << " ; "
           << word.getUpdateDate() << " ; "
           << word.getKnowingLevel() << " ; ";
        for (std::string sentence : word.getExampleSentences())
        {
            os << sentence << " ; ";
        }
        if (word.exampleSentences.empty())
            os << ";";
        os << "\n";
        return os;
    }

    friend std::istream &operator>>(std::istream &in, Word &word)
    {
        word.setUpdateDate();
        // read member variables of f
        return in;
    }

    ~Word();
};

#endif // Word.h
