#include "unit_test_tree_simple.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_print_tree.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestTreeSimple)

UnitTestTreeSimple::UnitTestTreeSimple()
    : WsjcppUnitTestBase("UnitTestTreeSimple") {
}

// ---------------------------------------------------------------------

bool UnitTestTreeSimple::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestTreeSimple::executeTest() {

    WsjcppPrintTree tree("Example Of Tree");
    tree
        .addChild("Hello1")
            .switchToLatestChild()
            .addChild("Hello2")
                .switchToLatestChild()
                .switchToParent()    
            .addChild("Hello2")
            .switchToParent()
        .addChild("Hello3")
            .switchToLatestChild()
            .switchToParent()
        .addChild("Hello4")
            .switchToLatestChild()
            .addChild("Hello123")
            .switchToParent()
    ;
    std::string sTreeExpected =
        "Example Of Tree\n"
        "├─ Hello1\n"
        "│  ├─ Hello2\n"
        "│  └─ Hello2\n"
        "├─ Hello3\n"
        "└─ Hello4\n"
        "   └─ Hello123\n";

    compare("Test tree", tree.printTree(), sTreeExpected);
}

// ---------------------------------------------------------------------

bool UnitTestTreeSimple::doAfterTest() {
    // nothing
    return true;
}