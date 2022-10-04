#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Without Abstract Data Types

typedef struct point {
    float x;
    float y;
} Point;

/* Function protocols */
Point *create_point(float x, float y);
void free_point(Point *p);
void access_point(Point *p, float *x, float *y);
void assign_point(Point *p, float x, float y);
float point_distance(Point *p1, Point *p2);

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

int main() {
    Point *p1 = create_point(2.0, 1.0);
    Point *p2 = create_point(3.4, 2.1);
    float d = point_distance(p1, p2);
    printf("Distance between points: %f\n", d);
    free_point(p1);
    free_point(p2);

    return 0;
}
