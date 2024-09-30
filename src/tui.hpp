#ifndef TUI_HPP_INCLUDE_HEADER
#define TUI_HPP_INCLUDE_HEADER

#include "io/keyboard.hpp"
#include "tpp.hpp"
#include "util/color.hpp"
#include "component/component.hpp"
#include "util/context.hpp"
#include "util/mode.hpp"
#include "util/size.hpp"
#include "util/util.hpp"
#include <algorithm>
#include <clocale>
#include <cstddef>
#include <cstdio>
#include <memory>
#include <ncurses.h>
#include <stdexcept>
#include <thread>

namespace tpp {

tpp::util::Context context;
tpp::util::Size TERMINAL_SIZE;
tpp::io::keyboard::Key last_key = tpp::io::keyboard::Key::None;

void initialize_tui() {
    // ncurses init
    std::printf("\033]0;%s\007", TPP_FULL_VERSION);
    fflush(stdout);
    setlocale(LC_ALL, "");
    initscr();
    tpp::util::disable_line_buffering();
    tpp::util::disable_echo();
    tpp::util::disable_input_delay();
    tpp::util::enable_special_keys();
    tpp::util::set_cursor_type(tpp::util::CursorType::INVISIBLE);
    getmaxyx(stdscr, TERMINAL_SIZE.height, TERMINAL_SIZE.width);

    context.running = true;
}

/**
 * Draws and blocks until TargetFPS is met
*/
void draw_screen() {
    auto cur_type = tpp::util::get_cursor_type();
    if (context.clear_mode == Mode::FRAME_RENDER_HARD) {
        clear();
    } else {
        tpp::util::place_cursor(0, 0);
    }
    for (auto c : context.components) {
        c->draw(context);
    }
    wrefresh(stdscr);
    auto frame_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = frame_end - context.frame_time;

    // Sleep for the remaining time of the frame duration
    if (elapsed.count() < context.fps) {
        std::this_thread::sleep_for(std::chrono::milliseconds(context.fps) - elapsed);
    }

    context.frame_time = std::chrono::high_resolution_clock::now();
    tpp::util::set_cursor_type(cur_type);
}

void enter_mode(tpp::Mode mode) {
    switch (mode) {
        case Mode::INTERACTIVE: {
            noecho();
            break;
        }
        case Mode::REGULAR: {
            echo();
            break;
        }
        case Mode::ENABLE_MOUSE: {
            mousemask(ALL_MOUSE_EVENTS, NULL);
            break;
        }
        case Mode::DISABLE_MOUSE: {
            mousemask(0, NULL);
            break;
        }
        case Mode::FRAME_RENDER_HARD: {
            context.clear_mode = Mode::FRAME_RENDER_HARD;
            break;
        }
        case Mode::FRAME_RENDER_SOFT: {
            context.clear_mode = Mode::FRAME_RENDER_SOFT;
            break;
        }
    }
}

void destroy_tui() {
    context.running = false;
    endwin();
}

inline bool is_running() {
    return context.running;
}

void add_component(std::shared_ptr<tpp::component::Component> component) {
    context.components.push_back(std::move(component));
}

void remove_component(std::shared_ptr<tpp::component::Component> component) {
    for (auto it = context.components.begin(); it != context.components.end(); it++) {
        if (*it == component) {
            context.components.erase(it);
            break;
        }
    }
}

void remove_component(tpp::component::Component &component) {
    for (auto c : context.components) {
        if (c.get() == &component) {
            context.components.erase(std::remove(context.components.begin(), context.components.end(), c), context.components.end());
            break;
        }
    }
}

bool is_active(tpp::component::Component &component) {
    for (std::size_t i = 0; i < context.components.size(); i++) {
        if (context.components.at(i).get() == &component) {
            return i == context.active_component_index;
        }
    }
    return false;
}

bool is_active(int i) {
    if (i < 0 || i >= context.components.size()) {
        throw std::out_of_range("index out of range");
    }
    return i == context.active_component_index;
}

void set_active_component(int index) {
    if (index < 0 || index >= context.components.size()) {
        throw std::out_of_range("index out of range");
    }
    context.active_component_index = index;
}

void set_active_component(tpp::component::Component &component) {
    for (std::size_t i = 0; i < context.components.size(); i++) {
        if (context.components.at(i).get() == &component) {
            context.active_component_index = i;
            break;
        }
    }
}

void set_active_component(std::shared_ptr<tpp::component::Component> component) {
    tpp::set_active_component(*component);
}

void set_target_fps(int fps) {
    if (fps > 1000 || fps < 0) {
        throw std::out_of_range("fps cannot be higher than 1000 or less than 0");
    }

    context.fps = 1000 / (double) fps;
}

void set_terminal_title(std::string title) {
    int x = getcurx(stdscr);
    int y = getcury(stdscr);

    std::printf("\033]0;%s\007", title.c_str());
    std::fflush(stdout);
    refresh();
    wmove(stdscr, y, x);
}

void handle_input(tpp::io::keyboard::Key key) {
    last_key = key;
    if (context.components.size() > 0) {
        context.components.at(context.active_component_index)->handle_input(key);
    }
}

}

#endif // !TUI_HPP_INCLUDE_HEADER:
