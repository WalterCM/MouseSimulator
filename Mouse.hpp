
/* Mouse.hpp
 *
 * Esta clase genera una interfaz para poder controlar acciones de simulador de mouse
 *
 * Esta clase usa funciones de las librerias de xorg xlib y xtest para generar acciones
 * de mouse falso.
 *
 * Esta clase puede:
 * Mover el cursor a una posicion especifica de la pantalla
 * Mover el cursor una distancia especifica
 * Hacer clicks derechos
 * Hacer clicks izquierdos
 * hacer click medio
 * */

#ifndef MOUSESIMULATOR_MOUSE_HPP
#define MOUSESIMULATOR_MOUSE_HPP


/* El namespace que permite diferenciar los botones del mouse de otros dispositivos
 */
namespace Mouse {
    class MouseHandler;
    enum Button {
        LEFT = 1,
        MIDDLE,
        RIGHT
    };
}


class MouseHandler
{
public:
    /*
     * Constructor de la clase
     * Inicializa el display invisible que se usara para las funciones
     * */
    MouseHandler();

    /*
     * Funcion que mueve el cursor las dimensiones pasadas como argumentos
     * en pixeles
     * @x: Distancia en el eje x que se movera el cursor
     * @y: Distancia en el eje y que se movera el cursor
     * */
    void move(int x, int y);

    /*
     * Funcion que posiciona el cursor en el punto x, y
     * @x: Posicion en el eje x para posicionar el cursor
     * @y: Posicion en el eje y para posicionar el cursor
     * */
    void set(int x, int y);

    /*
     * Presiona el boton especificado
     * @button: boton del namespace Mouse
     * */
    void buttonMake(Mouse::Button button);

    /*
     * Suelta el boton especificado
     * @button: boton del namespace Mouse
     * */
    void buttonBreak(Mouse::Button button);
private:
    Display *display;
};


#endif //MOUSESIMULATOR_MOUSE_HPP



