#ifndef TINYTERM_H
#define TINYTERM_H

#include "engine.h"
#include "entity_store.h"

class TinyTerm : public Engine::Engine {

public:
    TinyTerm() : Engine::Engine() {}

    // Members:
    EntityStore::Player m_player = EntityStore::Player("player", std::pair<int, int> { 12, 20 });
    EntityStore::Grass m_grass = EntityStore::Grass("grass", std::pair{ 10, 10 });

    std::pair<int, int> m_main_window_size, m_text_window_size, m_debug_window_size;

    WINDOW *p_m_main_window, *p_m_text_window, *p_m_debug_window;

    // Life Cycles:
    void on_create() override;

    void on_update() override;

    // Utilities:
    void initialize_windows();
};

#endif
