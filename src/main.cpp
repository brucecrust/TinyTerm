#include "./engine/engine.hpp"

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