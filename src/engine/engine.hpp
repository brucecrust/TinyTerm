#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

namespace Engine {

    // Vector Interactions: 

    void print_2D_vector(std::vector<std::vector<char>> p_matrix);

    void print_string_vector(std::vector<std::string> p_strings);

    // Input Interactions:

    std::string handle_user_input(std::string p_acceptable_input, bool p_verify_input = true);
}

#endif