#ifndef BORDER_HPP_INCLUDE_HEADER
#define BORDER_HPP_INCLUDE_HEADER

#include <string>
#include <vector>
#include "../util/util.hpp"
namespace tpp {

enum class BorderStyle {
    NONE,
    SINGLE,
    DOUBLE,
    ROUNDED
};

class BorderCharacter {
public:
    std::string character;
    BorderCharacter(std::string character) {
        this->character = character;
    }
    BorderCharacter() = default;
};

class BorderCharacters {
public: 
    BorderCharacter topLeft;
    BorderCharacter topRight;
    BorderCharacter bottomLeft;
    BorderCharacter bottomRight;
    BorderCharacter horizontal;
    BorderCharacter vertical;


    BorderCharacters(BorderCharacter topLeft,
                     BorderCharacter topRight,
                     BorderCharacter bottomLeft,
                     BorderCharacter bottomRight,
                     BorderCharacter horizontal,
                     BorderCharacter vertical) {
        this->topLeft = topLeft;
        this->topRight = topRight;
        this->bottomLeft = bottomLeft;
        this->bottomRight = bottomRight;
        this->horizontal = horizontal;
        this->vertical = vertical;
    }

    std::string draw(int width, int height, std::vector<std::string> content, bool active) {
        std::string border;
        width += 2;
        border += topLeft.character;
        if (width > 2 && active) {
            border += "*";
            border += tpp::util::repeat(horizontal.character, width - 1);
        } else {
            border += tpp::util::repeat(horizontal.character, width);
        }
        border += topRight.character;
        border += "\n";

        for (int i = 0; i < height; i++) {
            border += vertical.character;
            if (i < content.size()) {
                if (width > content.at(i).length()) {
                    border += content.at(i) + tpp::util::repeat(" ", width - content.at(i).length());
                } else {
                    border += content.at(i);
                }
            } else {
                border += tpp::util::repeat(" ", width);
            }
            border += vertical.character;
            border += "\n";
        }

        border += bottomLeft.character;
        border += tpp::util::repeat(horizontal.character, width);
        border += bottomRight.character;
        return border;
    }
};

class BorderManager {
public:
    static BorderCharacters get_border(BorderStyle border) {
        switch (border) {
            case BorderStyle::ROUNDED: {
                return BorderCharacters(
                    BorderCharacter("╭"),
                    BorderCharacter("╮"),
                    BorderCharacter("╰"),
                    BorderCharacter("╯"),
                    BorderCharacter("─"),
                    BorderCharacter("│")
                );
            }            
            case BorderStyle::SINGLE: {
                return BorderCharacters(
                    BorderCharacter("┌"), 
                    BorderCharacter("┐"), 
                    BorderCharacter("└"), 
                    BorderCharacter("┘"), 
                    BorderCharacter("─"), 
                    BorderCharacter("│")
                );
            }
            case BorderStyle::DOUBLE: {
                return BorderCharacters(
                    BorderCharacter("╔"), 
                    BorderCharacter("╗"), 
                    BorderCharacter("╚"), 
                    BorderCharacter("╝"), 
                    BorderCharacter("═"), 
                    BorderCharacter("║")
                );
            }
            default: {
                return BorderCharacters(
                    BorderCharacter(""), 
                    BorderCharacter(""), 
                    BorderCharacter(""), 
                    BorderCharacter(""), 
                    BorderCharacter(""), 
                    BorderCharacter("")
                );
            }
        }
    }
};

}

#endif // !BORDER_HPP_INCLUDE_HEADER
