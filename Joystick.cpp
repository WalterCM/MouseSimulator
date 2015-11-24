
#include <SFML/Window.hpp>
#include "Joystick.hpp"

JoystickHandler::JoystickHandler()
{
    isJ1Pressed = false;
    isJ2Pressed = false;
    isJ3Pressed = false;
    isJ4Pressed = false;
    isJL1Pressed = false;
    isJL2Pressed = false;
    isJR1Pressed = false;
    isJR2Pressed = false;
    isJ9Pressed = false;
    isJ10Pressed = false;

    isJ1Released = false;
    isJ2Released = false;
    isJ3Released = false;
    isJ4Released = false;
    isJL1Released = false;
    isJL2Released = false;
    isJR1Released = false;
    isJR2Released = false;
    isJ9Released = false;
    isJ10Released = false;
}

void JoystickHandler::handleJoystickPressed()
{
    isJ1Pressed = sf::Joystick::isButtonPressed(0, Joystick::J1);
    isJ2Pressed = sf::Joystick::isButtonPressed(0, Joystick::J2);
    isJ3Pressed = sf::Joystick::isButtonPressed(0, Joystick::J3);
    isJ4Pressed = sf::Joystick::isButtonPressed(0, Joystick::J4);
    isJL1Pressed = sf::Joystick::isButtonPressed(0, Joystick::JL1);
    isJL2Pressed = sf::Joystick::isButtonPressed(0, Joystick::JL2);
    isJR1Pressed = sf::Joystick::isButtonPressed(0, Joystick::JR1);
    isJR2Pressed = sf::Joystick::isButtonPressed(0, Joystick::JR2);
    isJ9Pressed = sf::Joystick::isButtonPressed(0, Joystick::J9);
    isJ10Pressed = sf::Joystick::isButtonPressed(0, Joystick::J10);

    if (isJ1Pressed) isJ1Released = false;
    if (isJ2Pressed) isJ2Released = false;
    if (isJ3Pressed) isJ3Released = false;
    if (isJ4Pressed) isJ4Released = false;
    if (isJL1Pressed) isJL1Released = false;
    if (isJL2Pressed) isJL2Released = false;
    if (isJR1Pressed) isJR1Released = false;
    if (isJR2Pressed) isJR2Released = false;
    if (isJ9Pressed) isJ9Released = false;
    if (isJ10Pressed) isJ10Released = false;
}

void JoystickHandler::handleJoystickReleased()
{
    isJ1Released = isJ1Pressed && !sf::Joystick::isButtonPressed(0, Joystick::J1);
    isJ2Released = isJ2Pressed && !sf::Joystick::isButtonPressed(0, Joystick::J2);
    isJ3Released = isJ3Pressed && !sf::Joystick::isButtonPressed(0, Joystick::J3);
    isJ4Released = isJ4Pressed && !sf::Joystick::isButtonPressed(0, Joystick::J4);
    isJL1Released = isJL1Pressed && !sf::Joystick::isButtonPressed(0, Joystick::JL1);
    isJL2Released = isJL2Pressed && !sf::Joystick::isButtonPressed(0, Joystick::JL2);
    isJR1Released = isJR1Pressed && !sf::Joystick::isButtonPressed(0, Joystick::JR1);
    isJR2Released = isJR2Pressed && !sf::Joystick::isButtonPressed(0, Joystick::JR2);
    isJ9Released = isJ9Pressed && !sf::Joystick::isButtonPressed(0, Joystick::J9);
    isJ10Released = isJ10Pressed && !sf::Joystick::isButtonPressed(0, Joystick::J10);

    if (isJ1Released) isJ1Pressed = false;
    if (isJ2Released) isJ2Pressed = false;
    if (isJ3Released) isJ3Pressed = false;
    if (isJ4Released) isJ4Pressed = false;
    if (isJL1Released) isJL1Pressed = false;
    if (isJL2Released) isJL2Pressed = false;
    if (isJR1Released) isJR1Pressed = false;
    if (isJR2Released) isJR2Pressed = false;
    if (isJ9Released) isJ9Pressed = false;
    if (isJ10Released) isJ10Pressed = false;
}

bool JoystickHandler::isButtonPressed(Joystick::Button button)
{

    switch (button) {
        case Joystick::J1:
            //cout << "j1pressed" << endl;
            return isJ1Pressed;
        case Joystick::J2:
            //cout << "j2pressed" << endl;
            return isJ2Pressed;
        case Joystick::J3:
            //cout << "j3pressed" << endl;
            return isJ3Pressed;
        case Joystick::J4:
            //cout << "j4pressed" << endl;
            return isJ4Pressed;
        case Joystick::JL2:
            return isJL2Pressed;
        case Joystick::JR2:
            return isJR2Pressed;
        case Joystick::JL1:
            return isJL1Pressed;
        case Joystick::JR1:
            return isJR1Pressed;
        case Joystick::J9:
            return isJ9Pressed;
        case Joystick::J10:
            return isJ10Pressed;
    }
    return false;
}

bool JoystickHandler::isButtonReleased(Joystick::Button button)
{
    switch (button) {
        case Joystick::J1:
            return isJ1Released;
        case Joystick::J2:
            return isJ2Released;
        case Joystick::J3:
            return isJ3Released;
        case Joystick::J4:
            return isJ4Released;
        case Joystick::JL2:
            return isJL2Released;
        case Joystick::JR2:
            return isJR2Released;
        case Joystick::JL1:
            return isJL1Released;
        case Joystick::JR1:
            return isJR1Released;
        case Joystick::J9:
            return isJ9Released;
        case Joystick::J10:
            return isJ10Released;
    }
    return false;
}
