#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // for assert()
#include <unistd.h> // for sleep()
#include <string.h> // for memset()
#include <time.h>
#include "city.h"
#include "map.h"
#include "solve_climb.h"

int main(int argc, char**argv) {
    srand((unsigned int)time(NULL));
    const int width = 70;
    const int height = 40;
    const int max_cities = 100;
    
    Map *map = init_map(width, height);
    
    if (argc != 2){
        fprintf(stderr, "Usage: %s <city file>\n", argv[0]);
        exit(1);
    }
    int n = 1;
    
    City *city = load_cities(argv[1],&n);
    assert( n > 1 && n <= max_cities);

    
    plot_cities(map, city, n, NULL);
    sleep(1);
    
    int *route = (int*)calloc(n, sizeof(int));
    const double d = solve(city,n,route,50);
    plot_cities(map, city, n, route);
    printf("total distance = %f\n", d);
    for (int i = 0 ; i < n ; i++){
	    printf("%d -> ", route[i]);
    }
    printf("0\n");
    
    free(route);
    free(city);
    
    return 0;
}
