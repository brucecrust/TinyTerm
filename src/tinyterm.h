#ifndef TINYTERM_TINYTERM_H
#define TINYTERM_TINYTERM_H

#include "engine.h"

class TinyTerm : public Engine::Engine {
public:
    TinyTerm() : Engine::Engine() {}

    void on_create() override;

    void on_update() override;

    void generate_game_space();
};

#endif
