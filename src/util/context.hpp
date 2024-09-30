#ifndef CONTEXT_HPP_INCLUDE_HEADER
#define CONTEXT_HPP_INCLUDE_HEADER

#include "../component/component.hpp"
#include "mode.hpp"
#include <chrono>
#include <memory>

namespace tpp {
namespace util {

struct Context {
    bool running = false;
    std::vector<std::shared_ptr<tpp::component::Component>> components;
    int active_component_index = 0;
    int fps = 1000 / 60;
    std::chrono::time_point<std::chrono::high_resolution_clock> frame_time = std::chrono::high_resolution_clock::now();
    Mode clear_mode = Mode::FRAME_RENDER_HARD;
};

}
}

#endif // !CONTEXT_HPP_INCLUDE_HEADER
