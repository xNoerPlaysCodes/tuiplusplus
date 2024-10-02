#ifndef UTIL_HPP_INCLUDE_HEADER
#define UTIL_HPP_INCLUDE_HEADER

#include "color.hpp"
#include "coordinate.hpp"
#include "size.hpp"
#include <cstdio>
#include <locale>
#include <string>
#include <sstream>
#include <vector>
#include <ncurses.h>
#include <string>
#include <codecvt>
#include <locale>

namespace tpp {

namespace util {

std::vector<std::string> split(std::string text, char delim) {
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(text);
    while(std::getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}

template<typename B, typename D>
bool instanceof(B base, D derived) {
    return dynamic_cast<D>(base) != nullptr;
}

std::string repeat(std::string str, int times) {
    std::string result;
    for (int i = 0; i < times; i++) {
        result += str;
    }
    return result;
}

std::string join(std::vector<std::string> vec, char delim) {
    std::string str;
    for (auto s : vec) {
        str += s + delim;
    }
    return str.substr(0, str.size() - 1);
}

void place_cursor(Coordinate coordinates) {
    wmove(stdscr, coordinates.y, coordinates.x);
}

void place_cursor(int x, int y) {
    place_cursor(Coordinate(x, y));
}

void print_to_screen(std::string str) {
    wprintw(stdscr, "%s", str.c_str());
}

void print_to_screen(std::string str, tpp::util::Coordinate coordinates) {
    std::vector<std::string> contents = split(str, '\n');
    int y = coordinates.y;
    for (auto content : contents) {
        wmove(stdscr, y, coordinates.x);
        wprintw(stdscr, "%s", content.c_str());
        y++;
    }
}

tpp::util::Size get_terminal_size() {
    return Size(getmaxx(stdscr), getmaxy(stdscr));
}

enum class CursorType {
    INVISIBLE = 0,
    NORMAL    = 1,
    UNDERLINE = 2
};

auto cur = tpp::util::CursorType::INVISIBLE;

void set_cursor_type(CursorType type) {
    curs_set(static_cast<int>(type));
    cur = type;
}

[[deprecated]]
void ansi_set_fg(RGBColor color) {
    init_color(COLOR_RED, color.r * 1000 / 255, color.g * 1000 / 255, color.b * 1000 / 255);
    init_pair(700, COLOR_RED, -1);  // -1 for default background
    attron(COLOR_PAIR(700));
}

[[deprecated]]
void ansi_set_bg(RGBColor color) {
    init_color(COLOR_RED, color.r * 1000 / 255, color.g * 1000 / 255, color.b * 1000 / 255);
    init_pair(701, -1, COLOR_RED);  // Use a different pair
    attron(COLOR_PAIR(701));
}

[[deprecated]]
void ansi_reset() {
    attroff(COLOR_PAIR(700));
    attroff(COLOR_PAIR(701));  // Reset background color too
}


tpp::util::CursorType get_cursor_type() {
    return cur;
}

/**
 *    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
*/

inline void disable_line_buffering() {
    cbreak(); // change to raw() for all INPUTHANDNG AND SIGNAL HANDLE
}

inline void disable_echo() {
    noecho();
}

inline void disable_input_delay() {
    nodelay(stdscr, TRUE);
}

inline void enable_special_keys() {
    keypad(stdscr, TRUE);
}

inline void enable_color_mode() {
    start_color();
}

}
}

#endif // !UTIL_HPP_INCLUDE_HEADER
