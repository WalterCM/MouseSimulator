
#include <X11/extensions/XTest.h>
#include "MouseLinux.hpp"

MouseHandler::MouseHandler()
{
    display = XOpenDisplay(NULL);
}

void MouseHandler::move(int x, int y){
    XTestFakeRelativeMotionEvent(display, x, y, 0);
    XFlush(display);
}

void MouseHandler::set(int x, int y){
    XTestFakeMotionEvent(display, 0, x, y, 0);
    XFlush(display);
}

void MouseHandler::buttonMake(Mouse::Button button){
    XTestFakeButtonEvent(display, button, True, 0);
    XFlush(display);
}

void MouseHandler::buttonBreak(Mouse::Button button){
    XTestFakeButtonEvent(display, button, False, 0);
    XFlush(display);
}
