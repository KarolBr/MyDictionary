#ifndef WORD_H
#define WORD_H
#include <iostream>


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
public:
    /* behaviour */

    Word(std::string _word,std::string _mean):word(_word),meaning(_mean)
    {
        createDate = "now";
        knowingLevel = 0;
    }


    void setUpdateDate(std::string _updateDate);
    void setExampleSentences(std::string _exampleSentences);
    void setKnowingLevel(int _knowingLevel);

    std::string getWord();
    std::string getMeaning();
    std::string getExampleSentences();
    int getKnowingLevel();


    
    ~Word();
};




#endif //Word.h