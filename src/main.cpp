#include "engine.h"
#include "tinyterm.h"

int main() {
    auto tinyTerm = new TinyTerm();
    tinyTerm->on_create();
    delete tinyTerm;

    return 0;
}
