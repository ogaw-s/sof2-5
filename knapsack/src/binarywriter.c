#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
バイナリ：
品物数　size_t(8バイト)、 
価値　品物数分double(8バイト)、
重さ　品物数分double
*/
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <binary filename>\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *fp;
    fp = fopen(argv[1], "wb");
    srand((unsigned int)time(NULL));
    double v[3] = {0.25 * (rand() % 200),0.25 * (rand() % 200),0.25 * (rand() % 200)};
    double w[3] = {0.25 * (rand() % 200),0.25 * (rand() % 200),0.25 * (rand() % 200)};
    size_t a = 3;
    fwrite(&a, sizeof(size_t),1,fp);
    for (int i = 0; i < 3; i++) {
        fwrite(&v[i], sizeof(double), 1, fp);
    }
    for (int i = 0; i < 3; i++) {
        fwrite(&w[i], sizeof(double), 1, fp);
    }
    fclose(fp);
}
