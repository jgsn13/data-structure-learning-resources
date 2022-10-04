#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "point_2.h"

// With Abstract Data Types

struct point {
    float x;
    float y;
};

Point *create_point(float x, float y) {
    Point *p = (Point *)malloc(sizeof(Point));
    if (p == NULL) {
        printf("Insufficient memory");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void free_point(Point *p) { free(p); }

void access_point(Point *p, float *x, float *y) {
    *x = p->x;
    *y = p->y;
}

void assign_point(Point *p, float x, float y) {
    p->x = x;
    p->y = y;
}

float point_distance(Point *p1, Point *p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}
