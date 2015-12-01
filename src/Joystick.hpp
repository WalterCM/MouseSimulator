
/**
 * \class JoystickHandler
 * 
 * \brief Genera una interfaz para poder recibir informacion de 1 joystick generico.
 *
 * <br>
 * A travez de la libreria de programas multimedia, SFML,
 * esta libreria obtiene los valores analogicos de los botones del joystick.
 * <br>
 * Proporciona un enumerador de botones que puede ser usado en otros programas
 * <br>
 * Y posee funciones que muestran si algun boton especifico esta presionado
 * o acaba de ser soltado.
 **/

#ifndef MOUSESIMULATOR_JOYSTICK_HPP
#define MOUSESIMULATOR_JOYSTICK_HPP

/**
 * \namespace Joystick
 **/
namespace Joystick {
    class JoystickHandler;
    enum Button {
        J1,
        J2,
        J3,
        J4,
        JL2,
        JR2,
        JL1,
        JR1,
        J9,
        J10
    };
}

class JoystickHandler
{
public:
    /**
     * \fn JoystickHandler()
     * \brief Constructor de la clase.
     *
     * <br>
     * Inicializa todos los booleanos a falso
     **/
    JoystickHandler();

    /**
     * \fn handleJoystickPressed()
     * \brief Actualiza los booleanos de presionado
     *
     * <br>
     * Esta es una funcion de eventos de presionado de boton
     * Puede ser llamada si se sabe que algun evento de presionado de boton ha ocurrido
     * Esta cambiara los booleans de acuerdo al evento
     **/
    void handleJoystickPressed();

    /**
     * \fn handleJoystickReleased()
     * \brief Actualiza los booleanos de soltado
     *
     * <br>
     * Esta es una funcion de eventos de soltado de boton
     * Puede ser llamada si se sabe que algun evento de soltado de boton ha ocurrido
     * Esta cambiara los booleans de acuerdo al evento
     **/
    void handleJoystickReleased();

    /**
     * \fn isButtonPressed(Joystick::Button button)
     * \brief Esta el boton presionado?
     *
     * <br>
     * Funcion que devuelve true si el boton pasado como argumento esta presionado
     * \param button : Es un boton del enumerador del namespace Joystick
     **/
    bool isButtonPressed(Joystick::Button button);

    /**
     * \fn isButtonReleased(Joystick::Button button)
     * \brief Se ha acaba de soltar el boton?
     *
     * <br>
     * Funcion que devuelve true si el boton pasado como argumento ha sido soltado
     * \param button : Es un boton del enumerador del namespace Joystick
     **/
    bool isButtonReleased(Joystick::Button button);
private:
    bool isJ1Pressed;
    bool isJ2Pressed;
    bool isJ3Pressed;
    bool isJ4Pressed;
    bool isJL1Pressed;
    bool isJL2Pressed;
    bool isJR1Pressed;
    bool isJR2Pressed;
    bool isJ9Pressed;
    bool isJ10Pressed;

    bool isJ1Released;
    bool isJ2Released;
    bool isJ3Released;
    bool isJ4Released;
    bool isJL1Released;
    bool isJL2Released;
    bool isJR1Released;
    bool isJR2Released;
    bool isJ9Released;
    bool isJ10Released;
};
#endif //MOUSESIMULATOR_JOYSTICK_HPP
