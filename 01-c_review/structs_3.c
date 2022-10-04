#include <stdio.h>
#include <math.h>

// Distance between two points

typedef struct {
    float x;
    float y;
} Point;

void catch(Point *pp) {
    printf("Enter point coordinates (x, y):\n");
    scanf("%f %f", &pp->x, &pp->y);
}

float distance(Point *p1, Point *p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    Point p1, p2;
    catch(&p1);
    catch(&p2);
    printf("Distance between points: %.1f\n", distance(&p1, &p2)); return 0;
}

