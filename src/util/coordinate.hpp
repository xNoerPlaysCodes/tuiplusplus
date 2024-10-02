#ifndef COORDINATE_HPP_INCLUDE_HEADER
#define COORDINATE_HPP_INCLUDE_HEADER

namespace tpp {
namespace util {

struct Coordinate {
    int x;
    int y;
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    Coordinate(int x, int y) : x(x), y(y) {}
    Coordinate() {}
};

}
}

#endif // !COORDINATE_HPP_INCLUDE_HEADER
