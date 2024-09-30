#ifndef SIZE_HPP_INCLUDE_HEADER
#define SIZE_HPP_INCLUDE_HEADER

namespace tpp {
namespace util {

struct Size {
    int width;
    int height;
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    Size(int width, int height) : width(width), height(height) {}
    Size() {}
};

}
}

#endif // !SIZE_HPP_INCLUDE_HEADER
