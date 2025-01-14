#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solve_climb.h"
#include "city.h"
#include "map.h"

void init_random_route(int n, int* route) {
    for (int i = 0; i < n; i++) {
        route[i] = i;
    }
    int r1, r2;
    for (int j = 0; j < 2 * n; j++) {
        r1 = rand() % (n - 1) + 1; //1 ~ n-1までのランダム整数)
        r2 = rand() % (n - 1) + 1;
        int d1 = route[r1];
        int d2 = route[r2];

        route[r1] = d2;
        route[r2] = d1;
    }
}
double solve(const City *city, int n, int *route, int iter) {
    double min_dist = 1000000000000;
    int *route_buf = (int *)malloc(sizeof(int)*n);
    for (int i = 0; i < iter; i++) {
        init_random_route(n, route_buf);
        Answer ans = search(city, n, route_buf);
        if (ans.dist < min_dist) {
            min_dist = ans.dist;
        }
    }
    memcpy(route, route_buf, n*sizeof(int));
    return min_dist;
}

Answer search(const City *city, int n, int *route) {
    int enhanced = 0;//t or f
    double min_distance, dist_tmp;
    min_distance = distance_route(city, route, n);
    int *route_swapped = (int *)malloc(sizeof(int) * n);
    int *route_min = (int *)malloc(sizeof(int) * n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            memcpy(route_swapped, route, n*sizeof(int));
            dist_tmp = 0;
            //i番目とj番目を入れ替えて距離を足す
            int c1 = route[i];
            int c2 = route[j];
            route_swapped[i] = c2;
            route_swapped[j] = c1;
            dist_tmp = distance_route(city, route_swapped, n);
            if (dist_tmp < min_distance) {
                min_distance = dist_tmp;
                memcpy(route_min, route_swapped, n*sizeof(int));
                enhanced = 1;
            }
        }
    }
    if (enhanced) {
        Answer result = search(city, n, route_min);
        free(route_min);
        return result;
    }else {
        Answer ans = {.dist = min_distance, .route = route_min};
        return ans;
    }
}
