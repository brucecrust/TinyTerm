#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <curses.h>
#include <utility>

class PlayerController {
public:
    PlayerController(std::pair<int, int> position);

    std::pair<int, int> m_player_position;

    std::pair<int, int> move();
};

#endif
