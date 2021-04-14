#include "engine.hpp"

// TEST COMMENT: This is written in visual studio!
int main() {
    std::vector<std::vector<char>> matrix = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'},
    };

    Engine::print_2D_vector(matrix);
    Engine::handle_user_input(std::vector<std::string> {"Fireball", "Firestorm"});

    return 0;
}