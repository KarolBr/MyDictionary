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

TEST_F(ProjectTest,IfCreatedObjectHasWordGetShouldReturnThisWord)
{
    Word word("name","imię");
    
}
