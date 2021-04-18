#include "player_controller.h"

PlayerController::PlayerController(std::pair<int, int> position) {
    m_player_position = position;
}

void PlayerController::move() {
    int ch = getch();
    if (ch == 'w') m_player_position.first = m_player_position.first - 1;
    if (ch == 's') m_player_position.first = m_player_position.first + 1;
    if (ch == 'a') m_player_position.second = m_player_position.second - 1;
    if (ch == 'd') m_player_position.second = m_player_position.second + 1;
}