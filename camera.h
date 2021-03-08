#include "../vector/vector.h"

struct Camera {
    Vector3f position, rotation;

    Camera(Vector3f pos, Vector3f rot): position(pos), rotation(rot) {};
};