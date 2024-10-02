#ifndef CHECKBOX_HPP_INCLUDE_HEADER
#define CHECKBOX_HPP_INCLUDE_HEADER

#include "component.hpp"
#include "../tui.hpp"
#include <functional>
#include <vector>

namespace tpp {
namespace component {

class Checkbox : public tpp::component::Component {
private:
    tpp::util::Coordinate coordinates;
    tpp::util::Size size;
    BorderStyle border;
    bool state;
    std::string text;
    std::vector<std::function<void(tpp::event::Event)>> listeners;
public:
    Checkbox(bool state, std::string text, tpp::util::Coordinate coordinates, int width, BorderStyle border) {
        this->state = state;
        this->text = text;
        this->coordinates = coordinates;
        this->size = tpp::util::Size(width, 1);
        this->border = border;
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

    void set_contents(std::vector<std::string> contents) {
        this->text = contents.at(0);
    }

    bool get_state() {
        return state;
    }

    void set_state(bool state) {
        this->state = state;
    }

    std::string get_state_string() {
        if (state) {
            return "[X]";
        } else {
            return "[ ]";
        }
    }

    std::vector<std::string> get_contents() {
        std::vector<std::string> contents;
        contents.reserve(1);
        std::string text = this->text;
        text += tpp::util::repeat(" ", size.width - text.length() + 3);
        text += get_state_string();
        contents.push_back(text);
        return contents;
    }

    void handle_input(tpp::io::keyboard::Key key) {
        if (key == tpp::io::keyboard::Key::Space) {
            state = !state;
            for (auto l : listeners) {
                l(tpp::event::Event{
                    .source = *this,
                    .type = tpp::event::EventType::CHECKBOX_STATE_CHANGE,
                });
            }
        }
    }

    void add_action_listener(const std::function<void(tpp::event::Event)> &e) {
        listeners.push_back(e);
    }

    void draw(tpp::util::Context &ctx) {
        const int plus_number = 4;
        if (border == BorderStyle::NONE) {
            tpp::util::place_cursor(coordinates);
            tpp::util::print_to_screen(get_contents().at(0));
        } else {
            auto border = BorderManager::get_border(this->border).draw(size.width + plus_number, size.height, get_contents(), tpp::is_active(*this));

            tpp::util::print_to_screen(border, coordinates);
        }
    }

    ~Checkbox() = default;
};

}
}

#endif // !CHECKBOX_HPP_INCLUDE_HEADER
