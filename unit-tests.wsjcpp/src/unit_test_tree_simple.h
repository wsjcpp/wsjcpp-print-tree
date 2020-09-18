#ifndef UNIT_TEST_TREE_SIMPLE_H
#define UNIT_TEST_TREE_SIMPLE_H

#include <wsjcpp_unit_tests.h>

// Description: TODO
class UnitTestTreeSimple : public WsjcppUnitTestBase {
    public:
        UnitTestTreeSimple();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_TREE_SIMPLE_H

