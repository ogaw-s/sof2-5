/*
都市数が20の場合の解を示すこと（tsp内のbin/gencity で都市のパターンは生成できる）
初期解の個数を増やしてどのような結果になるか適宜考察し、まとめる。可能であれば有効な可能性の高い初期値についても検討する。下記ディレクトリにtsp1.mdを同梱すること。
ディレクトリ名はtsp1 とする。

複数の初期解をランダムに生成する
それぞれの初期解について
あるパターンが与えられたときに全ての近傍パターン（2都市の入れ替え）を調べる
距離が最小だったパターンを採用。2-iに戻る。
全ての近傍より小さいパターンを見つけたら終了。局所最適解とする
2で得られた全ての局所最適解を比較し最適なものを解とする。
*/

#include "solve.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "city.h"
#include "map.h"

double solve(const City *city, int n, int *route) {
    int iter = 5;
    Answer *answers = (Answer *)malloc(sizeof(Answer) * iter);
    for (int i = 0; i < iter; i++) {
        init_random_route(n, route);    
        Answer ans = search(city, n, route);
        answers[i] = ans;
    }
    return honya;
}


Answer search(const City *city, int n, int *route) {
    //入れ替えたやつで探索→最小のやつの近傍を探索
    //局所最適解(入れ替えない方がまし)を探す
    int min_i, min_j;
    double min_distance, dist_tmp;
    double *route_swapped;
    memcpy(route_swapped, route, n);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dist_tmp = 0;
            //i番目とj番目を入れ替えて距離を足す
            double c1 = route[i];
            double c2 = route[j];
            route_swapped[i] = c2;
            route_swapped[j] = c1;
            dist_tmp = distance_route(city, route_swapped, n);
            if (dist_tmp < min_distance) {
                min_distance = dist_tmp;
                min_i = i;
                min_j = j;
            }
        }
    }


    
}