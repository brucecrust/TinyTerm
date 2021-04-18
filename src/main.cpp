#include "tinyterm.h"
#include <iostream>

int main() {
    auto player = new PlayerController(std::pair<int, int> { 12, 20 });
    auto tinyTerm = new TinyTerm(*player);
    tinyTerm->on_create();
    delete player;
    delete tinyTerm;
    return 0;
}
