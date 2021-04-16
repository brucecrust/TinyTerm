#ifndef TINYTERM_TINYTERM_H
#define TINYTERM_TINYTERM_H

#include "engine.h"
#include "numerics.h"

class TinyTerm : public Engine::Engine {
public:
    TinyTerm() : Engine::Engine() {}

    // Members:
    std::pair<int, int> m_main_window_size, m_text_window_size;

    WINDOW *p_m_main_window, *p_m_text_window;

    // Life Cycles:
    void on_create() override;

    void on_update() override;

    // Utilities:
    void initialize_windows();

    void generate_game_space();
};

#endif
