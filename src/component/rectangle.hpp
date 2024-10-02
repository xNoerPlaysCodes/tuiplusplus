#ifndef RECTANGLE_HPP_INCLUDE_HEADER
#define RECTANGLE_HPP_INCLUDE_HEADER

#include "component.hpp"
#include <functional>
#include "../tui.hpp"
namespace tpp {
namespace component {

class Rectangle : public tpp::component::Component {
private:
    tpp::util::Coordinate coordinates;
    tpp::util::Size size;
    BorderStyle border;
public:
    Rectangle(tpp::util::Coordinate coordinates, tpp::util::Size size, BorderStyle border) {
        this->coordinates = coordinates;
        this->size = size;
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

    void set_contents(std::vector<std::string> contents) {}

    std::vector<std::string> get_contents() {
        return std::vector<std::string>();
    }

    void handle_input(tpp::io::keyboard::Key key) {}

    void add_action_listener(const std::function<void(tpp::event::Event)> &e) {}

    void draw(tpp::util::Context &ctx) {
        if (border == BorderStyle::NONE) {
            tpp::util::place_cursor(coordinates);
            tpp::util::print_to_screen("");
        } else {
            auto border = BorderManager::get_border(this->border).draw(size.width, size.height, {}, tpp::is_active(*this));
            tpp::util::place_cursor(coordinates);
            tpp::util::print_to_screen(border, coordinates);
        }
    }

    ~Rectangle() = default;
};

}
}

#endif // !RECTANGLE_HPP_INCLUDE_HEADER
