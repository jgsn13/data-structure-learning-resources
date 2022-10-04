#include <stdio.h>
#include "circle.h"

int main() {
    Point *p = create_point(2.0, 1.0);
    Circle *c = create_circle(3.4, 2.1, 2.0);
    float a = circle_area(c);
    printf("Circle area: %.2f\n", a);
    if (inside_circle(c, p))
        printf("Point inside of the circle\n");
    else
        printf("Point out of the circle\n");
    free_point(p);
    free_circle(c);
    return 0;
}
