#include <stdio.h>

struct point {
    float x;
    float y;
};

int main() {
    struct point p;
    printf("Enter point coordinates (x, y):\n");
    scanf("%f %f", &p.x, &p.y);
    printf("Point(%.2f, %.2f)\n", p.x, p.y);

    // How to user pointer variables?
    struct point *pp;
    pp = &p;
    (*pp).x = 10.0;
    pp->y = 20.0;

    return 0;
}
