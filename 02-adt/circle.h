#include "point_2.h"

typedef struct circle Circle;

/* Creates a new circle with the coordinates x, y and the radius r */
Circle *create_circle(float x, float y, float r);

/* Releases memory of a circle */
void free_circle(Circle *c);

/* Calculates the area of a circle */
float circle_area(Circle *c);

/* Verify if a point p is inside of a circle */
int inside_circle(Circle *c, Point *p);
