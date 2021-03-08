#include "draw.cpp"
#include "camera/camera.h"
#include "objects/voxel.h"



bitmap_image image(200, 200);

Camera camera = Camera(Vector3f(1, 1, -1), Vector3f(-0.5, 0, 0));

Voxel vox(
    Vector3f(-1, -1, 1),
    Vector3f(-1, 1, 1),
    Vector3f(1, 1, 1),
    Vector3f(1, -1, 1),
    Vector3f(-1, -1, 3),
    Vector3f(-1, 1, 3),
    Vector3f(1, 1, 3),
    Vector3f(1, -1, 3)
);

int main() {
    vox.draw(image, camera);

    image.save_image("output.bmp");
    
    return 0;
}