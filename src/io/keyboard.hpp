#ifndef KEYBOARD_HPP_INCLUDE_HEADER
#define KEYBOARD_HPP_INCLUDE_HEADER

#include <ncurses.h>
namespace tpp { namespace io { namespace keyboard { enum class Key; } } }
namespace tpp { void handle_input(tpp::io::keyboard::Key key); }
namespace tpp {
namespace io {
namespace keyboard {

enum class Key {
    None,
    // Normal ASCII Characters
    Space = ' ',
    Exclamation = '!',
    DoubleQuote = '"',
    Hash = '#',
    Dollar = '$',
    Percent = '%',
    Ampersand = '&',
    SingleQuote = '\'',
    LeftParen = '(',
    RightParen = ')',
    Asterisk = '*',
    Plus = '+',
    Comma = ',',
    Minus = '-',
    Period = '.',
    Slash = '/',
    
    // Digits
    Digit0 = '0',
    Digit1 = '1',
    Digit2 = '2',
    Digit3 = '3',
    Digit4 = '4',
    Digit5 = '5',
    Digit6 = '6',
    Digit7 = '7',
    Digit8 = '8',
    Digit9 = '9',

    Colon = ':',
    Semicolon = ';',
    LessThan = '<',
    Equal = '=',
    GreaterThan = '>',
    Question = '?',
    At = '@',

    // Uppercase Letters
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    G = 'G',
    H = 'H',
    I = 'I',
    J = 'J',
    K = 'K',
    L = 'L',
    M = 'M',
    N = 'N',
    O = 'O',
    P = 'P',
    Q = 'Q',
    R = 'R',
    S = 'S',
    T = 'T',
    U = 'U',
    V = 'V',
    W = 'W',
    X = 'X',
    Y = 'Y',
    Z = 'Z',

    // Lowercase Letters
    a = 'a',
    b = 'b',
    c = 'c',
    d = 'd',
    e = 'e',
    f = 'f',
    g = 'g',
    h = 'h',
    i = 'i',
    j = 'j',
    k = 'k',
    l = 'l',
    m = 'm',
    n = 'n',
    o = 'o',
    p = 'p',
    q = 'q',
    r = 'r',
    s = 's',
    t = 't',
    u = 'u',
    v = 'v',
    w = 'w',
    x = 'x',
    y = 'y',
    z = 'z',

    // Special Symbols
    LeftBracket = '[',
    Backslash = '\\',
    RightBracket = ']',
    Caret = '^',
    Underscore = '_',
    Backtick = '`',

    // Arrow Keys
    Left = KEY_LEFT,
    Right = KEY_RIGHT,
    Up = KEY_UP,
    Down = KEY_DOWN,

    // Function Keys
    F1 = KEY_F(1),
    F2 = KEY_F(2),
    F3 = KEY_F(3),
    F4 = KEY_F(4),
    F5 = KEY_F(5),
    F6 = KEY_F(6),
    F7 = KEY_F(7),
    F8 = KEY_F(8),
    F9 = KEY_F(9),
    F10 = KEY_F(10),
    F11 = KEY_F(11),
    F12 = KEY_F(12),
    F13 = KEY_F(13),
    F14 = KEY_F(14),
    F15 = KEY_F(15),
    F16 = KEY_F(16),
    F17 = KEY_F(17),
    F18 = KEY_F(18),
    F19 = KEY_F(19),
    F20 = KEY_F(20),
    F21 = KEY_F(21),
    F22 = KEY_F(22),
    F23 = KEY_F(23),
    F24 = KEY_F(24),

    // Navigation Keys
    Home = KEY_HOME,
    End = KEY_END,
    PageDown = KEY_NPAGE,
    PageUp = KEY_PPAGE,
    Insert = KEY_IC,
    Delete = KEY_DC,
    BackspaceKey = KEY_BACKSPACE,
    BackspaceChar = static_cast<int>('\b'),

    // Editing Keys
    BackTab = KEY_BTAB,
    EnterChar = static_cast<int>('\n'),
    EnterKey = KEY_ENTER,
    InsertLine = KEY_IL,
    DeleteLine = KEY_DL,
    ExitInsertMode = KEY_EIC,

    // Miscellaneous Keys
    Resize = KEY_RESIZE,
    Mouse = KEY_MOUSE,
    ScrollForward = KEY_SF,
    ScrollBackward = KEY_SR,
    Clear = KEY_CLEAR,

    // Keypad Keys
    KeypadA1 = KEY_A1,
    KeypadA3 = KEY_A3,
    KeypadB2 = KEY_B2,
    KeypadC1 = KEY_C1,
    KeypadC3 = KEY_C3,

    // Control and Escape Sequences
    Escape = 27, // ASCII for ESC
    Tab = static_cast<int>('\t'),
    Suspend = KEY_SUSPEND,
    Redo = KEY_REDO,

    // Movement and Scrolling
    /*ShiftLeft = KEY_SLEFT,*/
    /*ShiftRight = KEY_SRIGHT,*/
    /*ShiftUp = KEY_SUP,*/
    /*ShiftDown = KEY_SDOWN,*/
    /*Begin = KEY_BEG,*/

    // Meta/Alt Keys - typically Alt is handled with escape sequences
    MetaEscape = 27, // Alt + x is often treated as ESC + x
};

tpp::io::keyboard::Key get_key_pressed() {
    auto key = tpp::io::keyboard::Key(getch());
    tpp::handle_input(key);
    return key;
}

}
}
}

#endif // !KEYBOARD_HPP_INCLUDE_HEADER
