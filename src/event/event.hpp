#ifndef EVENT_HPP_INCLUDE_HEADER
#define EVENT_HPP_INCLUDE_HEADER

namespace tpp { namespace component { class Component; } }

namespace tpp {
namespace event {

enum class EventType {
    TEXTBOX_SUBMISSION,
    CHECKBOX_STATE_CHANGE,
    BUTTON_PRESSED,
    POPUP_CLOSED
};

struct Event {
    tpp::component::Component   &source;
    tpp::event::EventType       type;
};

}
}

#endif // !EVENT_HPP_INCLUDE_HEADER
