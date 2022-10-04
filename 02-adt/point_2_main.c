#include <stdio.h>
#include "point_2.h"

int main() {
    Point *p1 = create_point(2.0, 1.0);
    Point *p2 = create_point(3.4, 2.1);
    float d = point_distance(p1, p2);
    printf("Distance between points: %f\n", d);
    free_point(p1);
    free_point(p2);

    return 0;
}
