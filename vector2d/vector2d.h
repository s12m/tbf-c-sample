#ifndef VECTOR2D_H
#define VECTOR2D_H

typedef struct {
    int x;
    int y;
} vector2d_t;

vector2d_t add(vector2d_t v1, vector2d_t v2);
vector2d_t sub(vector2d_t v1, vector2d_t v2);
int dot(vector2d_t v1, vector2d_t v2);

#endif
