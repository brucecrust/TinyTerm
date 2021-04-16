#ifndef ENGINE_H
#define ENGINE_H

#include "strings.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <curses.h>

namespace Engine {

    class Engine {
    public:
        /**
         * Initializes basic Curses functionality, such as p_window.
         * */
        Engine();

        WINDOW *p_window;

        /**
         * Gets called on class initialization. All setup logic should live here.
         * */
        virtual void on_create();

        /**
         * Starts the game loop and calls the window refresh button every frame.
         * */
        virtual void on_update();


        /**
         * Called after the game loop; i.e. when the last on_update call is made.
         * */
        virtual void on_destroy();
    };

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

    /**
     * Using a reference to a 2D character vector matrix, insert a character sprite at the given coordinates.
     * 
     * @param p_matrix: A reference to a 2D character vector that you would like to modify.
     * @param p_coordinates: A pair of size_t coordinates. The character will be inserted here.
     * @param p_sprite: A character sprite to insert into the matrix.
    */
    void modify_2D_vector_at_position(std::vector<std::vector<char>> &p_matrix, std::pair<std::size_t, std::size_t> p_coordinates, char p_sprite);

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
