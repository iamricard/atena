/**
 * Atena Game Engine
 * InputHandler.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __InputHandler__
#define __InputHandler__

class InputHandler {
 public:
    static InputHandler* Instance() {
        if (s_pInstance = 0) {
            s_pInstance = new InputHandler();
        }

        return s_pInstance;
    }

    void update();
    void clean();

 private:
    InputHandler();
    ~InputHandler();

    static InputHandler* s_pInstance;
};
typedef InputHandler AGEInput;

#endif
