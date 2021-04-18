#include "tinyterm.h"
#include <cstring>

// Life Cycles:
void TinyTerm::on_create() {
    Engine::on_create();

    initialize_windows();

    print_to_window(p_m_main_window, Numerics::default_int, Numerics::default_int, Strings::tiny_term);
    print_to_window(p_m_text_window, Numerics::default_int, Numerics::default_int, Strings::menu);
    print_to_window(p_m_debug_window, Numerics::default_int, Numerics::default_int, Strings::debug);
    print_to_window(p_m_text_window,
                    Numerics::Windows::default_dialog_offset,
                    Numerics::Windows::default_dialog_offset,
                    Strings::press_q_to_quit);

    print_ascii(p_m_main_window, 10, 10, "grass", COLOR_GREEN, COLOR_BLACK);
    print_ascii(p_m_main_window, m_player.m_position.first, m_player.m_position.second, "player", COLOR_WHITE, COLOR_BLACK);

    wrefresh(p_m_main_window);
    on_update();
}

void TinyTerm::on_update() {
    int player_pos_chars = strlen(Strings::player_position);

    // TODO: Create debug functions and hide them away
    print_to_window(p_m_debug_window, 1, 1, Strings::player_position);
    print_to_window(p_m_debug_window, 1, player_pos_chars+2, std::to_string(m_player.m_position.first).c_str());
    print_to_window(p_m_debug_window, 1, player_pos_chars+5, std::to_string(m_player.m_position.second).c_str());

    for (;;) {
        if (m_last_key_press == 'q') {
            break;
        }

        std::pair<int, int> previous_position;

        m_last_key_press = m_player.move();
        print_ascii(p_m_main_window, m_player.m_position.first, m_player.m_position.second, m_player.m_ascii, COLOR_WHITE, COLOR_BLACK);

        print_ascii(p_m_main_window, m_grass.m_position.first, m_grass.m_position.second, "empty", COLOR_WHITE, COLOR_BLACK);
        m_grass.move(m_last_key_press);
        print_ascii(p_m_main_window, m_grass.m_position.first, m_grass.m_position.second, m_grass.m_ascii, COLOR_GREEN, COLOR_BLACK);

        print_to_window(p_m_debug_window, 1, 1, Strings::player_position);
        print_to_window(p_m_debug_window, 1, player_pos_chars+2, std::to_string(m_player.m_position.first).c_str());
        print_to_window(p_m_debug_window, 1, player_pos_chars+5, std::to_string(m_player.m_position.second).c_str());
        wrefresh(p_m_debug_window);

        // TODO: Extract ascii height, width to properly iterate within a given space
        int col = m_grass.m_position.first;
        int row = m_grass.m_position.second;
        for (int i = 0; i < 15; ++i) {
            mvwaddch(p_m_main_window, col, row + i, ' ');
            wrefresh(p_m_main_window);

            if (i % 5) {
                ++col;
            }
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
                              COLS - m_debug_window_size.second);

    draw_window_border(p_m_main_window);
    draw_window_border(p_m_text_window);
    draw_window_border(p_m_debug_window);
}
