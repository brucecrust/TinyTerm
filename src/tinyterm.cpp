#include "tinyterm.h"

// Life Cycles:
void TinyTerm::on_create() {
    Engine::on_create();

    initialize_windows();

    print_to_window(p_m_main_window, Numerics::default_int, Numerics::default_int, Strings::tiny_term);
    print_to_window(p_m_text_window, Numerics::default_int, Numerics::default_int, Strings::menu);
    print_to_window(p_m_text_window,
                    Numerics::Windows::default_dialog_offset,
                    Numerics::Windows::default_dialog_offset,
                    Strings::press_q_to_quit);

    print_ascii(p_m_main_window, 10, 10, "grass", COLOR_GREEN, COLOR_BLACK);
    print_ascii(p_m_main_window, m_player->m_player_position.first, m_player->m_player_position.second, "player", COLOR_WHITE, COLOR_BLACK);

    wrefresh(p_m_main_window);
    on_update();
}

void TinyTerm::on_update() {
    for (;;) {
        std::pair<int, int> new_position = m_player->move();
        print_ascii(p_m_main_window, new_position.first, new_position.second, "player", COLOR_WHITE, COLOR_BLACK);
        wrefresh(p_m_main_window);

        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    Engine::on_destroy();
}

// Utilities:
void TinyTerm::initialize_windows() {
    m_debug_window_size = { Numerics::Windows::text_window_y, Numerics::Windows::debug_window_x };
    m_text_window_size = { Numerics::Windows::text_window_y, COLS - m_debug_window_size.second };
    m_main_window_size = { LINES - m_text_window_size.first, COLS };

    p_m_main_window = newwin(m_main_window_size.first,
                             m_main_window_size.second,
                             Numerics::default_int,
                             Numerics::default_int);

    p_m_text_window = newwin(m_text_window_size.first,
                             m_text_window_size.second,
                             m_main_window_size.first,
                             Numerics::default_int);

    p_m_debug_window = newwin(m_debug_window_size.first,
                              m_debug_window_size.second,
                              m_main_window_size.first,
                              Numerics::default_int);

    draw_window_border(p_m_main_window);
    draw_window_border(p_m_text_window);
    draw_window_border(p_m_debug_window);
}
