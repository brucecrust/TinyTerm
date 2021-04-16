#include "tinyterm.h"

void TinyTerm::on_create() {
    Engine::on_create();
    on_update();
}

void TinyTerm::on_update() {
    int column = 5;
    int row = 5;
    for (int i = 0; i < 10; ++i) {
        draw_to_window(column, row, '-');
        ++column;
        ++row;
        refresh();
    }

    int ch = getch();
    if (ch == 'q') {
        Engine::on_destroy();
    }

    Engine::on_destroy();
}

void TinyTerm::generate_game_space() {

}
