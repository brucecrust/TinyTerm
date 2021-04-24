#include "tinyterm.h"
#include <iostream>

int main() {
    auto tinyTerm = TinyTerm(true);
    tinyTerm.on_create();
    std::cout << tinyTerm.back_path << "\n";
    return 0;
}
