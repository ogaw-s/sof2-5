#include <stdio.h>

int main(void) {
    float f[4];

    // 以下に適切な値を設定する
    f[0] = 1143139122437582505939828736.0f;
    f[1] = 66592994030331831990133719040.0f;
    f[2] = 0.00000000000000000000000000000001099819697936194957854f;
    f[3] = 1143133809775289277588963328.0f;

    // "Hello,World\n" と出力してほしい
    printf("%s", (char*)f);

    // f[0] をいじる
    f[0] += 2361183241434822606848.0f;

    // "hello,World\n" と出力してほしい
    printf("%s", (char*)f);

    return 0;
}