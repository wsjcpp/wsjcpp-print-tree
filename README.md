# wsjcpp-print-tree

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-print-tree.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-print-tree) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-print-tree.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-print-tree) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-print-tree.svg)](https://github.com/wsjcpp/wsjcpp-print-tree) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-print-tree.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-print-tree/network/members)

Helper class for print tree like a for filesystems

## How to integrate to your project

First way:

```
wsjcpp install https://github.com/wsjcpp/wsjcpp-print-tree:master
```

Second way integrate files:

* `src.wsjcpp/wsjcpp_core/wsjcpp_core.h` 
* `src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp`
* `wsjcpp_print_tree.h`
* `wsjcpp_print_tree.cpp`

## Example of usage

```
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
    .addChild("Hello4") // 
        .switchToLatestChild()
        .addChild("Hello123")
        .switchToParent()
;
std::cout << tree.printTree() << std::endl;
```

Result will be like this:
```
Example Of Tree
├─ Hello1
│  ├─ Hello2
│  └─ Hello2
├─ Hello3
└─ Hello4
   └─ Hello123
```