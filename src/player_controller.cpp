#include "player_controller.h"

PlayerController::PlayerController(std::pair<int, int> position) {
    m_player_position = position;
}

std::pair<int, int> PlayerController::move() {
    std::pair<int, int> new_position;

    int ch = getch();
    if (ch == 'w') new_position = { -1 + m_player_position.first, 0 };
    if (ch == 's') new_position = { 1 + m_player_position.first, 0 };
    if (ch == 'a') new_position = { 0, -1 + m_player_position.second };
    if (ch == 'd') new_position = { 0, 1 + m_player_position.second };

    return new_position;
}