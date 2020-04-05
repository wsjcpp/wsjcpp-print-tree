#include "unit_test_tree_simple.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_print_tree.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestTreeSimple)

UnitTestTreeSimple::UnitTestTreeSimple()
    : WsjcppUnitTestBase("UnitTestTreeSimple") {
}

// ---------------------------------------------------------------------

void UnitTestTreeSimple::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestTreeSimple::run() {
    bool bTestSuccess = true;

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

    compareS(bTestSuccess, "Test tree", tree.printTree(), sTreeExpected);
    return bTestSuccess;
}

