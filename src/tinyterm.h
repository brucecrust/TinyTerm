#ifndef TINYTERM_H
#define TINYTERM_H

#include "engine.h"
#include "player_controller.h"

class TinyTerm : public Engine::Engine {

public:
    TinyTerm(PlayerController *player) : Engine::Engine(), m_player(player) { m_player = player; }

    // Members:
    PlayerController *m_player;

    std::pair<int, int> m_main_window_size, m_text_window_size, m_debug_window_size;

    WINDOW *p_m_main_window, *p_m_text_window, *p_m_debug_window;

    // Life Cycles:
    void on_create() override;

    void on_update() override;

    // Utilities:
    void initialize_windows();
};

#endif
