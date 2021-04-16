#include "tinyterm.h"

void TinyTerm::on_create() {
    Engine::on_create();

    //p_main_window = newwin(LINES - 10, COLS, 0, 0);
    //p_text_window = newwin(10, COLS, LINES - 10, 0);

    text_window_size = { Numerics::Windows::text_window_x, COLS };
    main_window_size = { LINES - text_window_size.first, COLS };

    p_main_window = newwin(
            main_window_size.first,
            main_window_size.second,
            Numerics::Windows::standard_offset,
            Numerics::Windows::standard_offset);

    int p_text_window_offset = LINES - Numerics::Windows::text_window_x_offset;

    p_text_window = newwin(
            text_window_size.first,
            text_window_size.second,
            p_text_window_offset,
            Numerics::Windows::standard_offset);

    on_update();
}

void TinyTerm::on_update() {
    wborder(p_main_window, 0, 0, 0, 0, 0, 0, 0, 0);
    wprintw(p_main_window, "TinyTerm");
    wborder(p_text_window, 0, 0, 0, 0, 0, 0, 0, 0);

    mvwprintw(p_text_window, 1, 1, "Press q to quit:");
    wrefresh(p_main_window);
    wrefresh(p_text_window);

    // TODO: This means nothing; regardless of what the user presses on_destroy is called.
    int ch = getch();
    if (ch == 'q') {
        Engine::on_destroy();
    }
}

void TinyTerm::generate_game_space() {

}
