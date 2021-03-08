#include <cmath>


template <class t> struct Vector3{
    t x;
    t y;
    t z;

    Vector3(): x(0), y(0), z(0) {};
    Vector3(t x): x(x), y(x), z(x) {};
    Vector3(t x, t y, t z): x(x), y(y), z(z) {};

    inline Vector3<t> operator +(const Vector3<t> &v) const {return Vector3<t>(x + v.x, y + v.y, z + v.z);};
    inline Vector3<t> operator -(const Vector3<t> &v) const {return Vector3<t>(x - v.x, y - v.y, z - v.z);};
    inline Vector3<t> operator *(const Vector3<t> &v) const {return Vector3<t>(x * v.x, y * v.y, z * v.z);};
    inline Vector3<t> operator *(const t &n) const {return Vector3<t>(x * n, y * n, z * n);};
    inline Vector3<t> operator /(const Vector3<t> &v) const {return Vector3<t>(x / v.x, y / v.y, z / v.z);};
    inline Vector3<t> operator /(const t &n) const {return Vector3<t>(x / n, y / n, z / n);};

    inline Vector3<t> length() const {return pow((pow(x, 2) + pow(y, 2) + pow(z, 2)), 0.5);};
};

template <class t> struct Vector2{
    t x;
    t y;

    Vector2(): x(0), y(0) {};
    Vector2(t x): x(x), y(x) {};
    Vector2(t x, t y): x(x), y(y) {};

    inline Vector2<t> operator +(const Vector2<t> &v) const {return Vector2<t>(x + v.x, y + v.y);};
    inline Vector2<t> operator -(const Vector2<t> &v) const {return Vector2<t>(x - v.x, y - v.y);};
    inline Vector2<t> operator *(const Vector2<t> &v) const {return Vector2<t>(x * v.x, y * v.y);};
    inline Vector2<t> operator *(const t &n) const {return Vector2<t>(x * n, y * n);};
    inline Vector2<t> operator /(const Vector2<t> &v) const {return Vector2<t>(x / v.x, y / v.y);};
    inline Vector2<t> operator /(const t &n) const {return Vector2<t>(x / n, y / n);};

    inline float length() const {return pow((pow(x, 2) + pow(y, 2)), 0.5);};
};


typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;
typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;


struct Matrix2 {
    float a, b, c, d;

    Matrix2(float a, float b, float c, float d): a(a), b(b), c(c), d(d) {};

    inline Vector2f operator *(const Vector2f v) const {return Vector2f(v.x * a + v.y * b, v.x * c + v.y * d);};
};

struct Matrix3 {
    float a, b, c, d, e, f, g, h, i;

    Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i): 
        a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {};
    
    inline Vector3f operator *(const Vector3f v) const {return Vector3f(
        v.x * a + v.y * b + v.z * c,
        v.x * d + v.y * e + v.z * f,
        v.x * g + v.y * h + v.z * i
    );};
};


float dot(Vector3f a, Vector3f b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float dot(Vector3i a, Vector3i b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float dot(Vector2f a, Vector2f b) {
    return a.x * b.x + a.y * b.y;
}

float dot(Vector2i a, Vector2i b) {
    return a.x * b.x + a.y * b.y;
}

Vector3f normalize(Vector3f v) {
    return v / v.length();
}

Vector2f normalize(Vector2f v) {
    return v / v.length();
}