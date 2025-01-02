#include <stdio.h>
#include <stdint.h>
#include <string.h>
// windows 11
// gcc (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0

int main(void){
    unsigned char a1[] = {'H','e','l','l'};
    unsigned char a2[] = {'o',',','W','o'};
    unsigned char a3[] = {'r','l','d','\n'};
    unsigned char a4[] = {'\0','e','e','e'};
    unsigned char a5[] = {'h','e','l','l'};

    float f[4];
    float falt;
    memcpy(&f[0], &a1, sizeof(float));
    memcpy(&f[1], &a2, sizeof(float));
    memcpy(&f[2], &a3, sizeof(float));
    memcpy(&f[3], &a4, sizeof(float));
    memcpy(&falt, &a5, sizeof(float));
    
    printf("%.90f\n", f[0]);
    printf("%.90f\n", f[1]);
    printf("%.90f\n", f[2]);
    printf("%.90f\n", f[3]);
    printf("%.90f\n", falt - f[0]);
    
    printf("%s", (char *)f);
    
}