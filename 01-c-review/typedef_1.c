#include <stdio.h>

// Defining new types
typedef float Real;
struct point {
    Real x;
    Real y;
};
typedef struct point Point;
typedef struct point *PPoint;

typedef struct circle {
    Point p;
    Real r;
} Circle;

int main() {
    Real r = 10.5;
    Point p;
    p.x = 10.0;
    PPoint pp = &p;
    pp->x = 12.0;
    return 0;
}
