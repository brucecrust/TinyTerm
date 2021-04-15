#include "engine.hpp"

int main() {
    // TODO: Curses initialization; move to engine.
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    printw("Hello world\n ");
    printw("Enter 'q' to exit: ");
    refresh();
    int ch = getch();
    if (ch == 'q') {
        endwin();
    }

    return 0;
}
