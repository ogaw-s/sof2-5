#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        //fopenは失敗したらerrnoの変数をセット
        //perrorは番号に対応してメッセージを返す
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    char buf[100];

    size_t rsize = fread(buf, sizeof(char), 100, fp);

    printf("%zu Byte read\n", rsize);

    if (rsize < 100) {
        buf[rsize] = '\0';
        printf("%s",buf);
    }
    return EXIT_SUCCESS;
}