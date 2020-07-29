#include "vector2d.h"

vector2d_t add(vector2d_t v1, vector2d_t v2) {
    vector2d_t v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}

vector2d_t sub(vector2d_t v1, vector2d_t v2) {
    vector2d_t v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v;
}

int dot(vector2d_t v1, vector2d_t v2) {
    return v1.x * v2.x + v1.y * v2.y;
}
