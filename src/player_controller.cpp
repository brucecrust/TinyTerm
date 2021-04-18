#include "player_controller.h"

PlayerController::PlayerController(std::pair<int, int> position) {
    m_player_position = position;
}

void PlayerController::move() {
    int ch = getch();
    if (ch == 'w') m_player_position = { -1 + m_player_position.first, 0 };
    if (ch == 's') m_player_position = { 1 + m_player_position.first, 0 };
    if (ch == 'a') m_player_position = { 0, -1 + m_player_position.second };
    if (ch == 'd') m_player_position = { 0, 1 + m_player_position.second };
}