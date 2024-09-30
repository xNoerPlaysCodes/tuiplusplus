#ifndef COMPONENT_HPP_INCLUDE_HEADER
#define COMPONENT_HPP_INCLUDE_HEADER

#include "../util/size.hpp"
#include "../util/coordinate.hpp"
#include "../util/border.hpp"
#include "../io/keyboard.hpp"
#include "../event/event.hpp"
#include <functional>
#include <string>
#include <vector>

namespace tpp {
namespace util { struct Context; }

namespace component {

class Component {
public:
    virtual ~Component() = default;
    virtual tpp::util::Size             get_size() = 0;
    virtual std::vector<std::string>    get_contents() = 0;
    virtual BorderStyle                 get_border() = 0;
    virtual tpp::util::Coordinate       get_coordinates() = 0;
    virtual void                        set_coordinates(tpp::util::Coordinate coordinates) = 0;
    virtual void                        set_size(tpp::util::Size size) = 0;
    virtual void                        set_border(BorderStyle border) = 0;
    virtual void                        set_contents(std::vector<std::string> contents) = 0;
    virtual void                        handle_input(tpp::io::keyboard::Key key) = 0;
    virtual void                        draw(tpp::util::Context &ctx) = 0;
    virtual void                        add_action_listener(const std::function<void(tpp::event::Event)> &e) = 0;

    bool check_collision(Component &other) {
        tpp::util::Size thisSize = this->get_size();
        tpp::util::Size otherSize = other.get_size();
        tpp::util::Coordinate thisCoord = this->get_coordinates();
        tpp::util::Coordinate otherCoord = other.get_coordinates();

        if (this->get_border() != BorderStyle::NONE) {
            thisSize.width += 2;
            thisSize.height += 2;
            thisCoord.x -= 1;
            thisCoord.y -= 1;
        }
        if (other.get_border() != BorderStyle::NONE) {
            otherSize.width += 2;
            otherSize.height += 2;
            otherCoord.x -= 1;
            otherCoord.y -= 1;
        }

        return thisCoord.getX() <= otherCoord.getX() + otherSize.width
                && thisCoord.getX() + thisSize.width >= otherCoord.getX()
                && thisCoord.getY() <= otherCoord.getY() + otherSize.height
                && thisCoord.getY() + thisSize.height >= otherCoord.getY();
    }
};

}
}

#endif // !COMPONENT_HPP_INCLUDE_HEADER
