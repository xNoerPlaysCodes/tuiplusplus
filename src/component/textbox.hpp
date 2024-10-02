#ifndef TEXTBOX_HPP_INCLUDE_HEADER
#define TEXTBOX_HPP_INCLUDE_HEADER

#include <functional>
#include <memory>
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

class Textbox : public tpp::component::Component {
private:
    std::string text;
    std::string placeholder;
    tpp::util::Coordinate coordinates;
    tpp::util::Size size;
    BorderStyle border;
    int cx;
    std::vector<std::function<void(tpp::event::Event)>> action_listeners;
public:
    Textbox(tpp::util::Coordinate coordinates, int width, BorderStyle border) {
        this->coordinates = coordinates;
        this->size = tpp::util::Size(width, 1);
        this->border = border;
    }
    Textbox(std::string placeholder, tpp::util::Coordinate coordinates, int width, BorderStyle border) {
        this->placeholder = placeholder;
        this->coordinates = coordinates;
        this->size = tpp::util::Size(width, 1);
        this->border = border;
    }

    std::string get_text() {
        return text;
    }

    int get_cursorx() {
        return cx;
    }

    void set_cursorx(int cx) {
        this->cx = cx;
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
        std::vector<std::string> contents;
        auto split = util::split(text, '\n');
        contents.reserve(split.size());
        for (std::string str : split) {
            contents.push_back(text);
        }
        return contents;
    }

    void set_contents(std::vector<std::string> contents) {
        text = "";
        for (std::string line : contents) {
            text += line + '\n';
        }
    }

    void set_placeholder(std::string placeholder) {
        this->placeholder = placeholder;
    }

    std::string get_placeholder() {
        return placeholder;
    }

    void add_action_listener(const std::function<void(tpp::event::Event)> &e) {
        action_listeners.push_back(e);
    }

    void handle_input(tpp::io::keyboard::Key key) {
        if (key == tpp::io::keyboard::Key::BackspaceChar || key == tpp::io::keyboard::Key::BackspaceKey) {
            if (text.length() > 0) {
                cx--;
                text = text.substr(0, text.length() - 1);
            }
        } else if (key == tpp::io::keyboard::Key::Left) {
            if (cx > 0) {
                cx--;
            }
        } else if (key == tpp::io::keyboard::Key::Right) {
            if (cx < text.length()) {
                cx++;
            }
        } else if (key == tpp::io::keyboard::Key::EnterKey || key == tpp::io::keyboard::Key::EnterChar) {
            for (auto e : action_listeners) {
                e(tpp::event::Event {
                    .source = *this,
                    .type = tpp::event::EventType::TEXTBOX_SUBMISSION
                });
            }
        }

        else {
            if (static_cast<int>(key) >= 32 && static_cast<int>(key) <= 126 && text.length() < size.width + 2) {
                cx++;
                text += static_cast<char>(key);
            }
        }
    }

    
    void draw(tpp::util::Context &ctx) {
        if (border == BorderStyle::NONE) {
            tpp::util::place_cursor(coordinates);
            tpp::util::print_to_screen(text.empty() ? placeholder : text);
            if (!text.empty()) {
                tpp::util::place_cursor(tpp::util::Coordinate(coordinates.x + cx, coordinates.y));
            } else {
                tpp::util::place_cursor(tpp::util::Coordinate(coordinates.x, coordinates.y));
            }
        } else {
            auto borderStr = BorderManager::get_border(border).draw(size.width, size.height, get_contents(), tpp::is_active(*this));
            tpp::util::print_to_screen(borderStr, coordinates);

            // Draw the text or placeholder
            std::string displayText = text.empty() ? placeholder : text;
            tpp::util::place_cursor(tpp::util::Coordinate(coordinates.x + 1, coordinates.y + 1)); // Adjust based on border
            tpp::util::print_to_screen(displayText);
            if (!text.empty()) {
                tpp::util::place_cursor(tpp::util::Coordinate(coordinates.x + cx + 1, coordinates.y + 1));
            } else {
                tpp::util::place_cursor(tpp::util::Coordinate(coordinates.x + 1, coordinates.y + 1));
            }
        }

        if (tpp::is_active(*this)) {
            tpp::util::set_cursor_type(tpp::util::CursorType::NORMAL);
        }
    }


    ~Textbox() = default;
};

}
}


#endif // !TEXTBOX_HPP_INCLUDE_HEADER
