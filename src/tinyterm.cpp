#include "tinyterm.h"

void TinyTerm::on_create() {
    Engine::on_create();
    on_update();
}

void TinyTerm::on_update() {
    printw("Enter 'q' to exit: ");
    wrefresh(p_window);
    for (;;) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    Engine::on_destroy();
}
