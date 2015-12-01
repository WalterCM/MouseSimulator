#include <iostream>
#include <thread>
#include "Program.hpp"

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
        elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() >= (1.0f / 60)) {
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::JoystickButtonPressed:
                        joystick.handleJoystickPressed();
                        checkMouseButtonPressed();
                        break;
                    case sf::Event::JoystickButtonReleased:
                        joystick.handleJoystickReleased();
                        checkMouseButtonReleased();
                        break;
                    default:
                        break;
                }
            }
            update();
            clock.restart();
        }
    }
}

void Program::update()
{
    velocity.y = moveDown - moveUp;
    velocity.y *= speed;
    velocity.x = moveRight - moveLeft;
    velocity.x *= speed;

    if (velocity.x != 0 || velocity.y != 0)
        mouse.move(velocity.x, velocity.y);
}

void Program::checkMouseButtonPressed()
{
    stopProgram = joystick.isButtonPressed(Joystick::J10);

    if (stopProgram)
        exit(0);

    leftPressed = joystick.isButtonPressed(Joystick::JL1) ||
                  joystick.isButtonPressed(Joystick::JL2);
    rightPressed = joystick.isButtonPressed(Joystick::JR1) ||
                   joystick.isButtonPressed(Joystick::JR2);

    moveLeft = joystick.isButtonPressed(Joystick::J4);
    moveRight = joystick.isButtonPressed(Joystick::J2);
    moveUp = joystick.isButtonPressed(Joystick::J1);
    moveDown = joystick.isButtonPressed(Joystick::J3);

    if (leftPressed)
        mouse.buttonMake(Mouse::LEFTDOWN);
    else if (rightPressed)
        mouse.buttonMake(Mouse::RIGHTDOWN);
}

void Program::checkMouseButtonReleased()
{
    leftReleased = joystick.isButtonReleased(Joystick::JL1) ||
                   joystick.isButtonReleased(Joystick::JL2);
    rightReleased = joystick.isButtonReleased(Joystick::JR1) ||
                    joystick.isButtonReleased(Joystick::JR2);

    moveLeft = moveLeft && !joystick.isButtonReleased(Joystick::J4);
    moveRight = moveRight && !joystick.isButtonReleased(Joystick::J2);
    moveUp = moveUp && !joystick.isButtonReleased(Joystick::J1);
    moveDown = moveDown && !joystick.isButtonReleased(Joystick::J3);

    if (leftReleased)
        mouse.buttonBreak(Mouse::LEFTUP);
    else if (rightReleased)
        mouse.buttonBreak(Mouse::RIGHTUP);
}