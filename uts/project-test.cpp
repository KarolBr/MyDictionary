#include <gtest/gtest.h>
#include "Word.h"
#include "Dictionary.h"



class ProjectTest : public ::testing::Test
{
    protected:
    ProjectTest() {};
    ~ProjectTest() override {};

    void SetUp() override{};
    void TearDown() override {};
};



TEST_F(ProjectTest,ObjectWordCanBeCreated)
{
    Word word("name","imię");
}

TEST_F(ProjectTest,IfObjectWordIsCreatedMethodsGetShouldReturnValues)
{
    Word word("name","imię");
    EXPECT_EQ("name",word.getWord());
    //EXPECT_EQ(word.getDateAndTimeToString(),word.getCreateDate());
    EXPECT_EQ(0,word.getKnowingLevel());
}


TEST_F(ProjectTest,IfObjectWordIsModyfyingUpdataDateShouldBeSet)
{
    Word word("name","imię");
    word.setKnowingLevel(3);
    //std::cout<<"getUpdateDate: "<<word.getUpdateDate()<<std::endl;
    EXPECT_NE("",word.getUpdateDate());

}

TEST_F(ProjectTest,IfObjectWordIsCreatedAddExampleSentences)
{
    Word word("name","imię");
    word.setExampleSentences("My name is Karol");
    word.setExampleSentences("What is your name?");
    word.setExampleSentences("What is your name?");
    //std::cout<<"getUpdateDate: "<<word.getUpdateDate()<<std::endl;
    EXPECT_EQ(3,word.getExampleSentences().size());

}

TEST_F(ProjectTest,IfObjectDictionaryCanBeCreatedAndAddNewWord)
{
    Word newWord("effort","wysiłek");
    Dictionary myDict;
    myDict.addWord(newWord);
}

TEST_F(ProjectTest,IfAddFiveWordsintoDitionarySizeShouldBeFive)
{
    Word newWord1("effort","wysiłek");
    Word newWord2("hermit","pustelnik");
    Word newWord3("centenarian","stulatek");
    Word newWord4("desk","biurko");
    Word newWord5("window","okno");
    Word newWord6("flood","powódź");
    Dictionary myDict;
    myDict.addWord(newWord1);
    myDict.addWord(newWord2);
    myDict.addWord(newWord3);
    myDict.addWord(newWord4);
    myDict.addWord(newWord5);
    myDict.addWord(newWord6);
    EXPECT_EQ(6,myDict.sizeOfDictionary());
    /*for(Word word: myDict.getWords())
        std::cout<<word;
    */
}






