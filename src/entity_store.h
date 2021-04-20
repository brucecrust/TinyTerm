#ifndef ENTITIE_STORE_H
#define ENTITIE_STORE_H

#include <curses.h>
#include <string>

namespace EntityStore {

    // Base:
    class Entity {
    public:
        Entity(std::string ascii, std::pair<int, int> position);

        std::string m_ascii;

        std::pair<int, int> m_position, m_ascii_center, m_dimensions;
    };

    // Player:
    class Player : public Entity {
    public:
        Player(std::string ascii, std::pair<int, int> position) : Entity(ascii, position) {}

        // All user input functions must return the last pressed key, thus type of int.
        int move();
    };

    // Entity 
    class Grass : public Entity {
    public:
        Grass(std::string ascii, std::pair<int, int> position) : Entity(ascii, position) {}

        void move(int last_key_press);
    };

}

#endif
