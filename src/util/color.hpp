#ifndef COLOR_HPP_INCLUDE_HEADER
#define COLOR_HPP_INCLUDE_HEADER

namespace tpp {
namespace util {

enum class Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

struct RGBColor {
public:
    int r;
    int g;
    int b;
    RGBColor(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    };

    RGBColor(Color color) {
        switch (color) {
            case Color::BLACK:
                this->r = 0;
                this->g = 0;
                this->b = 0;
                break;
            case Color::RED:
                this->r = 255;
                this->g = 0;
                this->b = 0;
                break;
            case Color::GREEN:
                this->r = 0;
                this->g = 255;
                this->b = 0;
                break;
            case Color::YELLOW:
                this->r = 255;
                this->g = 255;
                this->b = 0;
                break;
            case Color::BLUE:
                this->r = 0;
                this->g = 0;
                this->b = 255;
                break;
            case Color::MAGENTA:
                this->r = 255;
                this->g = 0;
                this->b = 255;
                break;
            case Color::CYAN:
                this->r = 0;
                this->g = 255;
                this->b = 255;
                break;
            case Color::WHITE:
                this->r = 255;
                this->g = 255;
                this->b = 255;
                break;
        }
    }
};

}
}

#endif // !COLOR_HPP_INCLUDE_HEADER
