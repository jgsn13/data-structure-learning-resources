#include <stdio.h>
#include <math.h>

// Returns 1 if a point is inside a circle, otherwise returns 0

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point p;
    float r;
} Circle;

void catchPoint(Point *pp) {
    printf("Enter point coordinates (x, y):\n");
    scanf("%f %f", &pp->x, &pp->y);
}

void catchCircle(Circle *pc) {
    catchPoint(&pc->p);
    printf("Enter circle radius (r):\n");
    scanf("%f", &pc->r);
}

float distance(Point *p1, Point *p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

int inside(Circle *c, Point *p) {
    float d = distance(&c->p, p);
    return (d < c->r);
}

int main() {
    Point p;
    Circle c;
    catchPoint(&p);
    catchCircle(&c);
    if (inside(&c, &p))
        printf("Inside the circle\n");
    else
        printf("Out of the circle\n");
    return 0;
}
