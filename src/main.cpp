#include "tinyterm.h"
#include <iostream>

int main() {
    auto player = PlayerController(std::pair<int, int> { 12, 20 });
    auto tinyTerm = TinyTerm(player);
    tinyTerm.on_create();
    return 0;
}
