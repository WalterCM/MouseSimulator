
#include "Program.hpp"
#include <iostream>
using namespace std;

Program::Program()
{
    moveLeft = false;
    moveRight = false;
    moveUp = false;
    moveDown = false;
    leftPressed = false;
    leftReleased = false;
    rightPressed = false;
    rightReleased = false;
    middleClick = false;
    stopProgram = false;
}

void Program::run()
{
    sf::Window window(sf::VideoMode(1, 1), "mouseTest");

    sf::Clock clock;
    sf::Time elapsed;

    while (window.isOpen()) {
        // Receive the elapsed time to calculate when to run the next frame
        elapsed = clock.getElapsedTime();
        // CCalculate if it's time to run the next frame
        if (elapsed.asSeconds() >= (1.0f / 60)) {
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::JoystickButtonPressed:
                        joystick.handleJoystickPressed();
                        break;
                    case sf::Event::JoystickButtonReleased:
                        joystick.handleJoystickReleased();
                        break;
                    default:
                        break;
                }
            }
            update();
            // Restart the clock
            clock.restart();
        }
    }
}

void Program::update()
{
    leftPressed = joystick.isButtonPressed(Joystick::JL1) ||
                  joystick.isButtonPressed(Joystick::JL2);
    leftReleased = joystick.isButtonReleased(Joystick::JL1) ||
                   joystick.isButtonReleased(Joystick::JL2);

    rightPressed = joystick.isButtonPressed(Joystick::JR1) ||
                   joystick.isButtonPressed(Joystick::JR2);
    rightReleased = joystick.isButtonReleased(Joystick::JR1) ||
                    joystick.isButtonReleased(Joystick::JR2);

    stopProgram = joystick.isButtonPressed(Joystick::J10);

    moveLeft = joystick.isButtonPressed(Joystick::J4) &&
               !joystick.isButtonReleased(Joystick::J4);
    moveRight = joystick.isButtonPressed(Joystick::J2) &&
                !joystick.isButtonReleased(Joystick::J2);
    moveUp = joystick.isButtonPressed(Joystick::J1) &&
             !joystick.isButtonReleased(Joystick::J1);
    moveDown = joystick.isButtonPressed(Joystick::J3) &&
               !joystick.isButtonReleased(Joystick::J3);

    if (leftPressed) {
        mouse.buttonMake(Mouse::LEFT);
    } else if (leftReleased) {
        mouse.buttonBreak(Mouse::LEFT);
    }

    if (rightPressed) {
        mouse.buttonMake(Mouse::RIGHT);
    } else if (rightReleased) {
        mouse.buttonBreak(Mouse::RIGHT);
    }

    else if (stopProgram) {
        exit(0);
    }

    velocity.y = moveDown - moveUp;
    velocity.y *= speed;
    velocity.x = moveRight - moveLeft;
    velocity.x *= speed;

    mouse.move(velocity.x, velocity.y);
}
