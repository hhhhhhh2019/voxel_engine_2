/*
#include "../vector/vector.h"
#include "../draw.cpp"
#include "../camera/camera.h"
*/

struct Voxel {
    Vector3f a, b, c, d, e, f, g, h;
    Color color;

    Voxel(Vector3f a, Vector3f b, Vector3f c, Vector3f d, Vector3f e, Vector3f f, Vector3f g, Vector3f h):
        a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), color(Color(255, 255, 255)) {};
    
    void draw(bitmap_image &image, Camera camera) {
        Matrix3 rot_x(
            1, 0, 0,
            0, cos(camera.rotation.x), -sin(camera.rotation.x),
            0, sin(camera.rotation.x), cos(camera.rotation.x)
        );

        Matrix3 rot_y(
            cos(camera.rotation.y), 0, -sin(camera.rotation.y),
            0, 1, 0,
            sin(camera.rotation.y), 0, cos(camera.rotation.y)
        );

        Matrix3 rot_z(
            cos(camera.rotation.z), -sin(camera.rotation.z), 0,
            sin(camera.rotation.z), cos(camera.rotation.z), 0,
            0, 0, 1
        );

        Matrix3 scale(
            int(image.width()) / 2, 0, 0,
            0, -int(image.height()) / 2, 0,
            0, 0, 1
        );

        Vector3f a1 = scale * ((rot_z * (rot_y * (rot_x * a))) - camera.position);
        Vector3f b1 = scale * ((rot_z * (rot_y * (rot_x * b))) - camera.position);
        Vector3f c1 = scale * ((rot_z * (rot_y * (rot_x * c))) - camera.position);
        Vector3f d1 = scale * ((rot_z * (rot_y * (rot_x * d))) - camera.position);
        Vector3f e1 = scale * ((rot_z * (rot_y * (rot_x * e))) - camera.position);
        Vector3f f1 = scale * ((rot_z * (rot_y * (rot_x * f))) - camera.position);
        Vector3f g1 = scale * ((rot_z * (rot_y * (rot_x * g))) - camera.position);
        Vector3f h1 = scale * ((rot_z * (rot_y * (rot_x * h))) - camera.position);

        Vector2i p1(a1.x / a1.z + image.width() / 2,
                    a1.y / a1.z + image.height() / 2);
        Vector2i p2(b1.x / b1.z + image.width() / 2,
                    b1.y / b1.z + image.height() / 2);
        Vector2i p3(c1.x / c1.z + image.width() / 2,
                    c1.y / c1.z + image.height() / 2);
        Vector2i p4(d1.x / d1.z + image.width() / 2,
                    d1.y / d1.z + image.height() / 2);
        Vector2i p5(e1.x / e1.z + image.width() / 2,
                    e1.y / e1.z + image.height() / 2);
        Vector2i p6(f1.x / f1.z + image.width() / 2,
                    f1.y / f1.z + image.height() / 2);
        Vector2i p7(g1.x / g1.z + image.width() / 2,
                    g1.y / g1.z + image.height() / 2);
        Vector2i p8(h1.x / h1.z + image.width() / 2,
                    h1.y / h1.z + image.height() / 2);
        
        p1.x = std::min(std::max(p1.x, 0), int(image.width()));
        p1.y = std::min(std::max(p1.y, 0), int(image.height()));
        p2.x = std::min(std::max(p2.x, 0), int(image.width()));
        p2.y = std::min(std::max(p2.y, 0), int(image.height()));
        p3.x = std::min(std::max(p3.x, 0), int(image.width()));
        p3.y = std::min(std::max(p3.y, 0), int(image.height()));
        p4.x = std::min(std::max(p4.x, 0), int(image.width()));
        p4.y = std::min(std::max(p4.y, 0), int(image.height()));
        p5.x = std::min(std::max(p5.x, 0), int(image.width()));
        p5.y = std::min(std::max(p5.y, 0), int(image.height()));
        p6.x = std::min(std::max(p6.x, 0), int(image.width()));
        p6.y = std::min(std::max(p6.y, 0), int(image.height()));
        p7.x = std::min(std::max(p7.x, 0), int(image.width()));
        p7.y = std::min(std::max(p7.y, 0), int(image.height()));
        p8.x = std::min(std::max(p8.x, 0), int(image.width()));
        p8.y = std::min(std::max(p8.y, 0), int(image.height()));
        
        line(p1.x, p1.y, p2.x, p2.y, image, Color(255, 255, 255));
        line(p2.x, p2.y, p3.x, p3.y, image, Color(255, 255, 255));
        line(p3.x, p3.y, p4.x, p4.y, image, Color(255, 255, 255));
        line(p4.x, p4.y, p1.x, p1.y, image, Color(255, 255, 255));

        line(p1.x, p1.y, p5.x, p5.y, image, Color(255, 255, 255));
        line(p2.x, p2.y, p6.x, p6.y, image, Color(255, 255, 255));
        line(p3.x, p3.y, p7.x, p7.y, image, Color(255, 255, 255));
        line(p4.x, p4.y, p8.x, p8.y, image, Color(255, 255, 255));

        line(p5.x, p5.y, p6.x, p6.y, image, Color(255, 255, 255));
        line(p6.x, p6.y, p7.x, p7.y, image, Color(255, 255, 255));
        line(p7.x, p7.y, p8.x, p8.y, image, Color(255, 255, 255));
        line(p8.x, p8.y, p5.x, p5.y, image, Color(255, 255, 255));
    };
};