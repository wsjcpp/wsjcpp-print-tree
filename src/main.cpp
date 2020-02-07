
#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include <wsjcpp_print_tree.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    WSJCppCore::init(argc, argv, true);
    
    // may be better read from file struct for example json or any some
    WSJCppPrintTree tree("Example Of Tree");
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
        .addChild("Hello4") // 
            .switchToLatestChild()
            .addChild("Hello123")
            .switchToParent()
    ;
    std::cout << tree.printTree() << std::endl;
    return 0;
}