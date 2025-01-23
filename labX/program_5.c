#include <stdio.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int x = 5, y = 10, z = 15, sum = 0;
    add(&x, &y, &z, &sum);
    printf("Sum: %d\n", sum);
    return 0;
}
