#ifndef BUTTON_HPP_INCLUDE_HEADER
#define BUTTON_HPP_INCLUDE_HEADER

#include <functional>
#include <string>
#include <ncurses.h>
#include "component.hpp"
#include "../util/size.hpp"
#include "../util/border.hpp"
#include "../util/coordinate.hpp"
#include "../util/context.hpp"
#include "../tui.hpp"

namespace tpp {
namespace component {

class Button : public tpp::component::Component {
private:
    std::string text;
    tpp::util::Coordinate coordinates;
    tpp::util::Size size;
    BorderStyle border;
    std::vector<std::function<void(tpp::event::Event)>> listeners;
public:
    Button(std::string text, tpp::util::Coordinate coordinates, int width, BorderStyle border) {
        this->text = text;
        this->coordinates = coordinates;
        this->size = tpp::util::Size(width, 1);
        this->border = border;
    }

    std::string get_text() {
        return text;
    }

    void set_text(std::string text) {
        this->text = text;
    }

    tpp::util::Coordinate get_coordinates() {
        return coordinates;
    }

    void set_coordinates(tpp::util::Coordinate coordinates) {
        this->coordinates = coordinates;
    }

    tpp::util::Size get_size() {
        return size;
    }

    void set_size(tpp::util::Size size) {
        this->size = size;
    }

    BorderStyle get_border() {
        return border;
    }

    void set_border(BorderStyle border) {
        this->border = border;
    }

    std::vector<std::string> get_contents() {
        return tpp::util::split(text, '\n');
    }

    void set_contents(std::vector<std::string> contents) {
        text = "";
        for (std::string line : contents) {
            text += line + '\n';
        }
    }

    void handle_input(tpp::io::keyboard::Key key) {
        if (key == tpp::io::keyboard::Key::EnterKey || key == tpp::io::keyboard::Key::EnterChar) {
            for (auto listener : listeners) {
                listener(tpp::event::Event{
                    .source = *this,
                    .type = tpp::event::EventType::BUTTON_PRESSED
                });
            }
        }
    }

    void add_action_listener(const std::function<void(tpp::event::Event)> &e) {
        listeners.push_back(e);
    }

    void draw(tpp::util::Context &ctx) {
        if (border == BorderStyle::NONE) {
            tpp::util::place_cursor(coordinates);
            tpp::util::print_to_screen(text);
        } else {
            auto border = BorderManager::get_border(this->border).draw(size.width, size.height, get_contents(), tpp::is_active(*this));
            tpp::util::print_to_screen(border);
        }
    }

    ~Button() = default;
};

}
}

#endif // !BUTTON_HPP_INCLUDE_HEADER
