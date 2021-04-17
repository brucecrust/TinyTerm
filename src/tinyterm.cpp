#include "tinyterm.h"

// Life Cycles:
void TinyTerm::on_create() {
    Engine::on_create();

    initialize_windows();

    draw_window_border(p_m_text_window);

    print_to_window(p_m_main_window, Numerics::default_int, Numerics::default_int, Strings::tiny_term);
    print_to_window(p_m_text_window, Numerics::default_int, Numerics::default_int, Strings::menu);
    print_to_window(p_m_text_window,
                    Numerics::Windows::default_dialog_offset,
                    Numerics::Windows::default_dialog_offset,
                    Strings::press_q_to_quit);

    m_player_position = { 12, 12 };

    print_ascii(p_m_main_window, 10, 10, "grass", COLOR_GREEN, COLOR_BLACK);
    print_ascii(p_m_main_window, m_player_position.first, m_player_position.second, "player", COLOR_WHITE, COLOR_BLACK);

    wrefresh(p_m_main_window);
    on_update();
}

void TinyTerm::on_update() {
    for (;;) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    Engine::on_destroy();
}

// Utilities:
void TinyTerm::initialize_windows() {
    m_text_window_size = { Numerics::Windows::text_window_x, COLS };
    m_main_window_size = { LINES - m_text_window_size.first, COLS };
    m_player_window_size = { Numerics::Windows::player_window_xy, Numerics::Windows::player_window_xy };

    p_m_main_window = newwin(m_main_window_size.first,
                             m_main_window_size.second,
                             Numerics::default_int,
                             Numerics::default_int);

    p_m_text_window = newwin(m_text_window_size.first,
                             m_text_window_size.second,
                             m_main_window_size.first,
                             Numerics::default_int);

    p_m_player_window = newwin(
                               m_player_window_size.first,
                               m_player_window_size.second,
                               m_player_position.first,
                               m_player_position.second);
}
