#include "engine.hpp"

void Engine::Engine::on_create() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    p_window = newwin(200, 100, 5, 5);
}

void Engine::Engine::on_update() {
    for (;;) {
        break;
    }
    on_destroy();
}

void Engine::Engine::on_destroy() {
    endwin();
    delwin(p_window);
}

Engine::Engine::Engine() {}

void Engine::print_2D_vector(std::vector<std::vector<char>> p_matrix) {
    for (std::size_t column = 0; column < p_matrix.size(); ++column) {
        for (std::size_t row = 0; row < p_matrix[column].size(); ++row) {
            std::cout << " " << p_matrix[column][row] << " ";
        }

        std::cout << "\n";
    }
}

void Engine::print_string_vector(std::vector<std::string> p_strings) {
    for (auto index : p_strings) {
        std::cout << index << "\n";
    }
}

void Engine::modify_2D_vector_at_position(std::vector<std::vector<char>> &p_matrix, std::pair<std::size_t, std::size_t> p_coordinates, char p_sprite) {
    if (p_coordinates.first > p_matrix.size()) return;
    if (p_coordinates.second > p_matrix[p_coordinates.first].size()) return;
    p_matrix[p_coordinates.first][p_coordinates.second] = p_sprite;
}

// TODO: Allow for users to enter 'q' to quit this loop. 
// TODO: Ignore casing on user input.
std::string Engine::handle_user_input(std::vector<std::string> p_acceptable_input, bool p_verify_input) {
    print_string_vector(p_acceptable_input);

    std::string raw_input;

    std::cin >> raw_input;

    std::vector<std::string> input;

    // For each string in the provided answer vector, check if the user's input matches an option in the vector.
    for (std::string i : p_acceptable_input) {
        if (std::find(p_acceptable_input.begin(), p_acceptable_input.end(), i) != p_acceptable_input.end()) {
            if (i.rfind(raw_input, 0) == 0) input.push_back(i);
        }
    }

    if (input.empty()) {
        std::cout << Strings::invalid_input << "\n";
        handle_user_input(p_acceptable_input);
    }

    if (input.size() == 1) {
        if (p_verify_input) {
            std::cout << Strings::did_you_choose << input[0] << "\n";

            if (handle_user_input(std::vector<std::string> {Strings::yes, Strings::no}, false) == "Yes") {
                return input[0];
            }

            handle_user_input(p_acceptable_input);
        }

        return input[0];
    }

    std::cout << Strings::which_of_the_following << "\n";
    handle_user_input(input);

    return Strings::empty;
}
