#include <gtest/gtest.h>
#include "Word.h"



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










