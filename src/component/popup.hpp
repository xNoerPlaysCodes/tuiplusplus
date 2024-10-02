#ifndef POP_HPP_INCLUDE_HEADER
#define POP_HPP_INCLUDE_HEADER

#include <functional>
#include <stdexcept>
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

class Popup : public tpp::component::Component {
private:
    std::vector<std::string> contents;
    tpp::util::Coordinate coordinates;
    tpp::util::Size size;
    BorderStyle border;
    std::vector<std::function<void(tpp::event::Event)>> listeners;
public:
    Popup(std::vector<std::string> contents, tpp::util::Size size, BorderStyle border) {
        this->contents = contents;
        this->coordinates = tpp::util::Coordinate(tpp::util::get_terminal_size().width / 2 - 15, tpp::util::get_terminal_size().height / 2 - 5);
        this->size = size;
        this->border = border;
    }

    std::string get_text() {
        return tpp::util::join(contents, '\n');
    }

    void set_text(std::string text) {
        this->contents = tpp::util::split(text, '\n');
    }

    tpp::util::Coordinate get_coordinates() {
        return coordinates;
    }

    void set_coordinates(tpp::util::Coordinate coordinates) {
        throw std::invalid_argument("cannot set coordinates of tpp::component::Popup");
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
        return contents;
    }

    void set_contents(std::vector<std::string> contents) {
        this->contents = contents;
    }

    void handle_input(tpp::io::keyboard::Key key) {
        if (key == tpp::io::keyboard::Key::X) {
            for (auto listener : listeners) {
                listener(tpp::event::Event{
                    .source = *this,
                    .type = tpp::event::EventType::POPUP_CLOSED
                });
            }
        }
    }

    void add_action_listener(const std::function<void(tpp::event::Event)> &e) {
        listeners.push_back(e);
    }

    void draw(tpp::util::Context &ctx) {
        if (border == BorderStyle::NONE) {
            throw std::invalid_argument("border_style cannot be tpp::BorderStyle::NONE");
        } else {
            auto border = BorderManager::get_border(this->border).draw(size.width, size.height, get_contents(), tpp::is_active(*this));

            tpp::util::print_to_screen(border, coordinates);
        }
    }

    ~Popup() = default;
};

}
}

#endif // !POP_HPP_INCLUDE_HEADER
