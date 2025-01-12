#pragma once
#include "city.h"

typedef struct ans{
    double dist;
    int *route;
} Answer;

double solve(const City *city, int n, int *route);

Answer search(const City *city, int n, int *route);

void init_random_route(int n, int* route);

