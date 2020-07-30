#include "array.h"
#include <stdio.h>

int main() {
    array_t *array = create_array(5);

    put_to_array(array, 0, 16);
    put_to_array(array, 2, 25);
    put_to_array(array, 4, 36);
    put_to_array(array, 5, 49);

    printf("%d\n", get_from_array(array, 0));
    printf("%d\n", get_from_array(array, 1));
    printf("%d\n", get_from_array(array, 2));
    printf("%d\n", get_from_array(array, 3));
    printf("%d\n", get_from_array(array, 4));
    get_from_array(array, 5);

    destroy_array(array);

    return 0;
}
