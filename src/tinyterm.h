#ifndef TINYTERM_H
#define TINYTERM_H

#include "engine.h"

class TinyTerm : public Engine::Engine {

public:
    TinyTerm() : Engine::Engine() {}

    // Members:
    std::pair<int, int> m_main_window_size, m_text_window_size, m_player_window_size;
    std::pair<int, int> m_player_position;

    WINDOW *p_m_main_window, *p_m_text_window, *p_m_player_window;

    // Life Cycles:
    void on_create() override;

    void on_update() override;

    // Utilities:
    void initialize_windows();
};

#endif
