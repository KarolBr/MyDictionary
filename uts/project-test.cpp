#include <gtest/gtest.h>
#include "person.h"

class ProjectTest : public ::testing::Test
{
    protected:
    ProjectTest() {};
    ~ProjectTest() override {};

    void SetUp() override{};
    void TearDown() override {};
};



TEST_F(ProjectTest,PersonCanBeCreated)
{
    Person person;
}


