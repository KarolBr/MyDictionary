#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <chrono>
#include <iomanip>

class Word
{
private:
    /* data */
    std::string word;
    std::string meaning;
    std::string createDate;
    std::string updateDate;
    std::string exampleSencences;
    int knowingLevel;
    std::string getTimeStamp(){
        auto now = std::chrono::system_clock::now();
        std::time_t date_time = std::chrono::system_clock::to_time_t(now);
        return std::put_time(&date_time, "%d-%m-%Y %H-%M-%S");
    }

public:
    /* behaviour */

    Word(std::string _word,std::string _mean):word(_word),meaning(_mean)
    {
        createDate = getTimeStamp();
        knowingLevel = 0;
    }


    void setUpdateDate(std::string _updateDate);
    void setExampleSentences(std::string _exampleSentences);
    void setKnowingLevel(int _knowingLevel);

    std::string getCreateDate();
    std::string getUpdateDate();
    std::string getWord();
    std::string getMeaning();
    std::string getExampleSentences();
    int getKnowingLevel();


    
    ~Word();
};




#endif //Word.h