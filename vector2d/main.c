#include "vector2d.h"
#include <stdio.h>

void print_vector2d(vector2d_t v) {
    printf("(%d, %d)\n", v.x, v.y);
}

int main() {
    vector2d_t v1 = { 1, 4 };
    vector2d_t v2 = { 3, 2 };

    print_vector2d(add(v1, v2)); // (4, 6)
    print_vector2d(sub(v1, v2)); // (-2, 2)
    printf("%d\n", dot(v1, v2)); // 11

    return 0;
}
