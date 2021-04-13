#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

namespace Engine {

    // Vector Interactions: 

    /**
     * Prints a provided 2D character vector to the screen.
     * 
     * @param p_matrix: The 2D character vector matrix to print.
    */
    void print_2D_vector(std::vector<std::vector<char>> p_matrix);

    /**
     * Prints a simple vector of strings.
     * 
     * @param p_strings: The provided string vector to print.
    */
    void print_string_vector(std::vector<std::string> p_strings);

    // Input Interactions:

    /**
     * Have a user select an option from a vector of strings. This will recursively loop until the user has selected a correct answer.
     * User input does not need to contain the full word; instead, they can simply type just enough characters for their choice to be unambiguous.
     * I.E. If the options "Fireball" and "Firestorm" are presented, the user must only type "Fireb" to select "Fireball".
     * 
     * @param p_acceptable_input: The provided vector of strings for the user to choose from. 
     * @param p_verify_input: Whether the function should verify with "Yes" or "No" when a user selects an answer.
    */
    std::string handle_user_input(std::vector<std::string> p_acceptable_input, bool p_verify_input = true);
}

#endif