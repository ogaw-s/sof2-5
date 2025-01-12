#include "city.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 町の構造体（今回は2次元座標）を定義
struct city {
    int x;
    int y;
};


double distance(const City *a, const City *b) {
    const double dx = a->x - b->x;
    const double dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}

double distance_route(const City *city, const int *route, const int n) {
    double dist_sum = 0;
    City *c1, *c2;
    double dx, dy;
    for (int i = 0; i < n - 1; i++) {
        c1 = get_city(city, route[i]);
        c2 = get_city(city, route[i+1]);
        dx = c1->x - c2->x;
        dy = c1->y - c2->y;
        dist_sum += sqrt(dx * dx + dy * dy);
    }
    return dist_sum;
}

City *load_cities(const char *filename, int *n) {
    City *city;
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "%s: cannot open file.\n", filename);
        exit(1);
    }
    fread(n, sizeof(int), 1, fp);
    city = (City *)malloc(sizeof(City) * *n);

    for (int i = 0; i < *n; i++) {
        fread(&city[i].x, sizeof(int), 1, fp);
        fread(&city[i].y, sizeof(int), 1, fp);
    }
    fclose(fp);
    return city;
}

City *get_city(const City *a, size_t i) { return a + i; }

int get_x(const City *c) { return c->x; }

int get_y(const City *c) { return c->y; }
