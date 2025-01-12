#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "search.h"
#include "util.h"

// main関数
// プログラム使用例: ./knapsack 10 20
//  10個の品物を設定し、キャパ20 でナップサック問題をとく

int main(int argc, char **argv) {
    /* 引数処理: ユーザ入力が正しくない場合は使い方を標準エラーに表示して終了 */
    /* 引数が一つだったらファイルからの入力 二つだったら従来通り*/
    char filename[256];
    const int max_items = 100;
    Itemset *items;
    int n;
    double W;
    if (argc != 3){
        fprintf(stderr, "usage: %s <the number of items (int)> <max capacity (double)>\n", argv[0]);
        printf("       or <filename> <max capacity (double)>\n");
        exit(1);
    }else if (atoi(argv[1]) != 0) {
        n = load_int(argv[1]);
        assert(n <= max_items);  // assert で止める
        assert(n > 0);           // 0以下も抑止する
        W = load_double(argv[2]);
        assert(W >= 0.0);
        // 乱数シードを1にして、初期化 (ここは変更可能)
        int seed = 1;
        items = init_itemset(n, seed);
    }else {
        //ここにWを設定するやつを実装！
        strcpy(filename, argv[1]);
        W = atoi(argv[2]);
        items = load_itemset(filename); 
    }
    
    printf("max capacity: W = %.f, # of items: %d\n", W, n);
    print_itemset(items);

    // ソルバーで解く
    Answer ans = solve(items, W);

    // 表示する
    printf("----\nbest solution:\n");
    printf("value: %4.1f\n", ans.value);
    for(int i = get_nitem(items)-1 ; i >=0 ;i--) {
        printf("%d", (ans.flags & (1 << i))?1:0);
    }
    printf("\n");

    free_itemset(items);
    return 0;
}
