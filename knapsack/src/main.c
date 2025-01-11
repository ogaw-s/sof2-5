#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "search.h"
#include "util.h"

// main関数
// プログラム使用例: ./knapsack 10 20
//  10個の品物を設定し、キャパ20 でナップサック問題をとく

int main(int argc, char **argv) {
    /* 引数処理: ユーザ入力が正しくない場合は使い方を標準エラーに表示して終了 */
    /* 引数が一つだったらファイルからの入力 二つだったら従来通り*/
    char filename;
    const int max_items = 100;
    Itemset *items;
    if (argc == 2) {
        strcpy(filename, argv[1]);
        items = load_itemset(filename);

    }else if(argc == 3) {
        const int n = load_int(argv[1]);
        assert(n <= max_items);  // assert で止める
        assert(n > 0);           // 0以下も抑止する
        const double W = load_double(argv[2]);
        assert(W >= 0.0);
        // 乱数シードを1にして、初期化 (ここは変更可能)
        int seed = 1;
        items = init_itemset(n, seed);
    }else {
        fprintf(stderr, "usage: %s <the number of items (int)> <max capacity (double)>\n", argv[0]);
        printf("       or <filename>\n");
        exit(1);    
    }
    
    printf("max capacity: W = %.f, # of items: %d\n", W, n);
    print_itemset(items);

    // ソルバーで解く
    double total = solve(items, W);

    // 表示する
    printf("----\nbest solution:\n");
    printf("value: %4.1f\n", total);

    free_itemset(items);
    return 0;
}
