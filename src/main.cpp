#include "engine.hpp"

class TinyTerm : public Engine::Engine {
public:
    void on_create() override {
        Engine::on_create();
        on_update();
    }

    void on_update() override {
        printw("Enter 'q' to exit: ");
        wrefresh(p_window);
        for (;;) {
            int ch = getch();
            if (ch == 'q') {
                break;
            }
        }

        Engine::on_destroy();
    }
};

int main() {
    auto tinyTerm = new TinyTerm();
    tinyTerm->on_create();
    delete tinyTerm;

    return 0;
}
