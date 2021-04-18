#include "entity_store.h"

// Player:
int EntityStore::Player::move() {
    int ch = getch();
    if (ch == 'w') m_position.first -= 1;
    if (ch == 's') m_position.first += 1;
    if (ch == 'a') m_position.second -= 1;
    if (ch == 'd') m_position.second += 1;

    return ch;
}

// Grass:
void EntityStore::Grass::move(int last_key_press) {
    if (last_key_press == 'w') m_position.first -= 1;
    if (last_key_press == 's') m_position.first += 1;
    if (last_key_press == 'a') m_position.second -= 1;
    if (last_key_press == 'd') m_position.second += 1;
}
