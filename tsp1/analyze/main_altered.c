#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // for assert()
#include <unistd.h> // for sleep()
#include <string.h> // for memset()
#include <time.h>
#include "city.h"
#include "map.h"
#include "solve_climb.h"

int main() {
    srand((unsigned int)time(NULL));
    int n = 1;
    City *city1 = load_cities("data/city20seed1.dat",&n);
    City *city2 = load_cities("data/city20seed10.dat",&n);
    City *city3 = load_cities("data/city20seed100.dat",&n);
    int *route = (int*)calloc(n, sizeof(int));
    int counter = 0;
    for (int i = 1; i < 500; i++) {
        counter = 0;
        i += 4;
        for (int j = 0; j < 50; j++) {
            const double d = solve(city1,n,route,i);
            if (d < 129.96) {
                counter++;
            }
        }
        printf("%d, %lf\n", i, (double) counter/50);
    }
    for (int i = 1; i < 500; i++) {
        counter = 0;
        i += 4;
        for (int j = 0; j < 50; j++) {
            const double d = solve(city2,n,route,i);
            if (d < 158.8) {
                counter++;
            }
        }
        printf("%d, %lf\n", i, (double) counter/50);
    }
    for (int i = 1; i < 500; i++) {
        counter = 0;
        i += 4;
        for (int j = 0; j < 50; j++) {
            const double d = solve(city3,n,route,i);
            if (d < 128.99) {
                counter++;
            }
        }
        printf("%d, %lf\n", i, (double) counter/50);
    }

    free(route);

    return 0;
}



    