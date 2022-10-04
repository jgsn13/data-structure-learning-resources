#include "circle.h"
#include <stdlib.h>

#define PI 3.14159
struct circle {
    Point *p;
    float r;
};

Circle *create_circle(float x, float y, float r) {
    Circle *c = (Circle *)malloc(sizeof(Circle));
    c->p = create_point(x, y);
    c->r = r;
    return c;
}

void free_circle(Circle *c) {
    free_point(c->p);
    free(c);
}

float circle_area(Circle *c) { return PI * c->r * c->r; }

int inside_circle(Circle *c, Point *p) {
    float d = point_distance(c->p, p);
    return (d < c->r);
}
