#ifndef TINYTERM_TINYTERM_H
#define TINYTERM_TINYTERM_H

#include "engine.h"
#include "numerics.h"

class TinyTerm : public Engine::Engine {
public:
    TinyTerm() : Engine::Engine() {}

    std::pair<int, int> main_window_size, text_window_size;

    WINDOW *p_main_window, *p_text_window;

    void on_create() override;

    void on_update() override;

    void generate_game_space();
};

#endif
