#ifndef MOUSE_HPP_INCLUDE_HEADER
#define MOUSE_HPP_INCLUDE_HEADER

#include <ncurses.h>
#include "../util/coordinate.hpp"
#include "keyboard.hpp"
#include "../tui.hpp"

namespace tpp {
namespace io {
namespace mouse {

enum class Button {
    Left,
    Right,
    Middle,
    None
};

tpp::io::mouse::Button get_button_pressed() { // implement times pressed
    if (tpp::last_key == tpp::io::keyboard::Key::Mouse) {
        MEVENT mouse_event;

        if (getmouse(&mouse_event) == OK) {
            if (mouse_event.bstate & BUTTON1_PRESSED) {
                return Button::Left;
            } else if (mouse_event.bstate & BUTTON2_PRESSED) {
                return Button::Middle;
            } else if (mouse_event.bstate & BUTTON3_PRESSED) {
                return Button::Right;
            }
        }
    }

    return Button::None;
}

tpp::util::Coordinate get_mouse_position() {
    if (tpp::last_key == tpp::io::keyboard::Key::Mouse) {
        MEVENT mouse_event;
        if (getmouse(&mouse_event) == OK) {
            return tpp::util::Coordinate(mouse_event.x, mouse_event.y);
        }
    }
    return tpp::util::Coordinate(0, 0);
}

}
}
}

#endif // !MOUSE_HPP_INCLUDE_HEADER
