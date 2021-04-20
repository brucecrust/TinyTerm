#include "tinyterm.h"
#include <cstring>

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

    wrefresh(p_m_main_window);
    on_update();
}

void TinyTerm::on_update() {
    for (;;) {
        if (m_last_key_press == 'q') {
            break;
        }

        print_ascii(p_m_main_window, m_grass.m_position.first, m_grass.m_position.second, m_grass.m_ascii, COLOR_GREEN, COLOR_BLACK);
        print_ascii(p_m_main_window, m_player.m_position.first, m_player.m_position.second, m_player.m_ascii, COLOR_WHITE, COLOR_BLACK);

        debug_ascii_loading();
        debug_player_position();

        m_last_key_press = m_player.move();
        m_grass.move(m_last_key_press);

        reset_main_window_state();
    }

    Engine::on_destroy();
}

// Utilities:
void TinyTerm::initialize_windows() {
    if (m_debug_mode) {
        m_debug_window_size = {Numerics::Windows::text_window_y, Numerics::Windows::debug_window_x};
        m_text_window_size = {Numerics::Windows::text_window_y, COLS - m_debug_window_size.second};
        m_main_window_size = {LINES - m_text_window_size.first, COLS};

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

        draw_window_border(p_m_debug_window);

    } else {
        m_text_window_size = {Numerics::Windows::text_window_y, COLS};
        m_main_window_size = {LINES - m_text_window_size.first, COLS};

        p_m_main_window = newwin(m_main_window_size.first,
                                 m_main_window_size.second,
                                 Numerics::default_int,
                                 Numerics::default_int);

        p_m_text_window = newwin(m_text_window_size.first,
                                 m_text_window_size.second,
                                 m_main_window_size.first,
                                 Numerics::default_int);
    }

    draw_window_border(p_m_main_window);
    draw_window_border(p_m_text_window);

}

void TinyTerm::evaluate_ascii_state() {
    for (const auto &[key, val] : m_ascii_state) {
        bool string_exists = std::find(m_printed_ascii_images.begin(), m_printed_ascii_images.end(), key) != m_printed_ascii_images.end();
        if (val && !string_exists) {
            m_printed_ascii_images.push_back(key);
        }
    }
}

void TinyTerm::reset_main_window_state() {
    wclear(p_m_main_window);
    draw_window_border(p_m_main_window);
    print_to_window(p_m_main_window, Numerics::default_int, Numerics::default_int, Strings::tiny_term);
}

// Debug:

void TinyTerm::print_debug(std::vector<std::string> &args, int column, int line) {
    int length_of_last_string = 0;

    for (const auto &i : args) {
        print_to_window(p_m_debug_window, column, line, i.c_str());
        length_of_last_string = i.length();
        line += length_of_last_string;
        ++line;
    }

    wrefresh(p_m_debug_window);
}

void TinyTerm::debug_player_position() {
    std::vector<std::string> player_position_text = {
            Strings::player_position,
            "col:", std::to_string(m_player.m_position.first),
            "line:", std::to_string(m_player.m_position.second)
    };

    print_debug(player_position_text, 1, 1);
}

void TinyTerm::debug_ascii_loading() {
    evaluate_ascii_state();

    std::vector<std::string> ascii_text = { Strings::ascii };
    for (auto &i : m_printed_ascii_images) {
        ascii_text.push_back(i);
    }

    print_debug(ascii_text, 2, 1);
}
