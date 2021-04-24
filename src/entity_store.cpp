#include "entity_store.h"

EntityStore::Entity::Entity(std::string ascii, std::pair<int, int> position)  {
    m_ascii = ascii;
    m_position = position;
}

int EntityStore::Entity::move_player() {
    int ch = getch();

    if (ch == 'w') m_position.first -= 1;
    if (ch == 's') m_position.first += 1;
    if (ch == 'a') m_position.second -= 1;
    if (ch == 'd') m_position.second += 1;

    return ch;
}

void EntityStore::Entity::move_rel_player(int last_key_press) {
    if (last_key_press == 'w') m_position.first -= 1;
    if (last_key_press == 's') m_position.first += 1;
    if (last_key_press == 'a') m_position.second -= 1;
    if (last_key_press == 'd') m_position.second += 1;
}