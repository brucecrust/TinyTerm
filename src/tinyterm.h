#ifndef TINYTERM_TINYTERM_H
#define TINYTERM_TINYTERM_H

#include "engine.h"

class TinyTerm : public Engine::Engine {
public:
    void on_create() override;

    void on_update() override;
};

#endif //TINYTERM_TINYTERM_H
