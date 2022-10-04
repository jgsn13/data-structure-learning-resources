typedef struct point Point;

/* Create a point with x and y coordinates */
Point *create_point(float x, float y);

/* Release memory from a point */
void free_point(Point *p);

/* Access the coordinates of a point */
void access_point(Point *p, float *x, float *y);

/* Assigns new coordinates to a point */
void assign_point(Point *p, float x, float y);

/* Calculate the distance between two points */
float point_distance(Point *p1, Point *p2);
