
#ifndef MOUSESIMULATOR_PROGRAM_HPP
#define MOUSESIMULATOR_PROGRAM_HPP

#include <SFML/Window.hpp>
#include "Joystick.hpp"
#if defined(__linux__)
    #include "MouseLinux.hpp"
#endif
#if defined(_WIN32)
    #include "MouseWindows.hpp"
#endif

class Program
{
public:
    Program();
    void run();
private:
    void update();
    void checkButtonPressed();
    void checkButtonReleased();

    JoystickHandler joystick;
    MouseHandler mouse;

    bool moveLeft;
    bool moveRight;
    bool moveUp;
    bool moveDown;
    bool leftPressed;
    bool leftReleased;
    bool rightPressed;
    bool rightReleased;
    bool middleClick;
    bool stopProgram;

    sf::Vector2i velocity;
    const int speed = 10;
};


#endif //MOUSESIMULATOR_PROGRAM_HPP
