#include "tinyterm.h"

// Life Cycles:
void TinyTerm::on_create() {
    Engine::on_create();

    initialize_windows();

    draw_window_border(p_m_main_window);
    draw_window_border(p_m_text_window);

    print_to_window(p_m_main_window, Numerics::default_int, Numerics::default_int, Strings::tiny_term);
    print_to_window(p_m_text_window, Numerics::default_int, Numerics::default_int, Strings::menu);
    print_to_window(p_m_text_window,
                    Numerics::Windows::default_dialog_offset,
                    Numerics::Windows::default_dialog_offset,
                    Strings::press_q_to_quit);

    on_update();
}

void TinyTerm::on_update() {
    // TODO: This means nothing; regardless of what the user presses on_destroy is called.
    int ch = getch();
    if (ch == 'q') {
        Engine::on_destroy();
    }
}

// Utilities:
void TinyTerm::initialize_windows() {
    m_text_window_size = {Numerics::Windows::text_window_x, COLS };
    m_main_window_size = {LINES - m_text_window_size.first, COLS };

    p_m_main_window = newwin(m_main_window_size.first,
            m_main_window_size.second,
            Numerics::default_int,
            Numerics::default_int);

    p_m_text_window = newwin(m_text_window_size.first,
            m_text_window_size.second,
            m_main_window_size.first,
            Numerics::default_int);
}



void TinyTerm::generate_game_space() {}
