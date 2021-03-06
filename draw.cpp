#include "bitmap_image.hpp"

struct Color {
   int r, g, b;

   Color(int r, int g, int b): r(r), g(g), b(b) {};
};


void line(int x0, int y0, int x1, int y1, bitmap_image &image, Color color) {
    bool steep = false;
    if (std::abs(x0-x1)<std::abs(y0-y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0>x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1-x0;
    int dy = y1-y0;
    int derror2 = std::abs(dy)*2;
    int error2 = 0;
    int y = y0;
    for (int x=x0; x<=x1; x++) {
        if (steep) {
            image.set_pixel(y, x, color.r, color.g, color.b);
        } else {
            image.set_pixel(x, y, color.r, color.g, color.b);
        }
        error2 += derror2;

        if (error2 > dx) {
            y += (y1>y0?1:-1);
            error2 -= dx*2;
        }
    }
}