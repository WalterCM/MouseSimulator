/**
 * \class MouseHandler
 *
 * \brief Genera una interfaz para poder controlar acciones de simulador de mouse
 *
 * <br>
 * Esta clase usa funciones de las librerias de xorg xlib y xtest para generar acciones
 * de mouse falso.
 * <br>
 * Esta clase puede:
 *      - Mover el cursor a una posicion especifica de la pantalla
 *      - Mover el cursor una distancia especifica
 *      - Hacer clicks derechos
 *      - Hacer clicks izquierdos
 *      - Hacer click medio
 **/    
#ifndef MOUSESIMULATOR_MOUSE_HPP
#define MOUSESIMULATOR_MOUSE_HPP

#include <windows.h>
/**
 * \namespace Mouse
 **/
namespace Mouse {
    class MouseHandler;
    enum Button {
        LEFTDOWN = MOUSEEVENTF_LEFTDOWN,
        LEFTUP = MOUSEEVENTF_LEFTUP,
        MIDDLE,
        RIGHTDOWN = MOUSEEVENTF_RIGHTDOWN,
        RIGHTUP = MOUSEEVENTF_RIGHTUP
    };
}

class MouseHandler
{
public:
    /**
     * \fn MouseHandler()
     * \brief Constructor de la clase.
     *
     * <br>
     * Inicializa el display invisible que se usara para las funciones
     **/
    MouseHandler();

    /**
     * \fn move(int x,int y)
     * \brief Mueve el cursor
     *
     * <br>
     * Funcion que mueve el cursor las dimensiones pasadas como argumentos
     * en pixeles
     * \param x : Distancia en el eje x que se movera el cursor
     * \param y : Distancia en el eje y que se movera el cursor
     **/
    void move(int x, int y);

    /**
     * \fn set(int x,int y)
     * \brief Posicion el cursor
     *
     * <br>
     * Funcion que posiciona el cursor en el punto x, y
     * \param x : Posicion en el eje x para posicionar el cursor
     * \param y : Posicion en el eje y para posicionar el cursor
     **/
    void set(int x, int y);

    /**
     * \fn buttonMake(Mouse::Button button)
     * \brief Presiona un boton
     *
     * <br>
     * Presiona el boton especificado
     * \param button : Boton del namespace Mouse
     **/
    void buttonMake(int button);

    /**
     * \fn buttonBreak(Mouse::Button button)
     * \brief Suelta un boton
     *
     * <br>
     * Suelta el boton especificado
     * \param button : Boton del namespace Mouse
     **/
    void buttonBreak(int button);
private:
};


#endif //MOUSESIMULATOR_MOUSE_HPP



