#include <stdio.h>

struct point {
    float x;
    float y;
};

void catch(struct point *pp) {
    printf("Enter point coordinates (x, y):\n");
    scanf("%f %f", &pp->x, &pp->y);
}

void prints(struct point *pp) {
    printf("Point(%.2f, %.2f)", pp->x, pp->y);
}

int main() {
    struct point p;
    catch(&p);
    prints(&p);
    return 0;
}
