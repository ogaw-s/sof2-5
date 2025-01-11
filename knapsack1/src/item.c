#include <stdio.h>
#include <stdlib.h>

#include "item.h"

// 以下は構造体定義

// 構造体 Item
// 価値valueと重さweightが格納されている
struct item {
    double value;
    double weight;
};

// 構造体 Item
// 価値valueと重さweightが格納されている
// Itemポインタをmallocする必要あり
struct itemset {
    size_t number;
    Item *item;
};


// 構造体をポインタで確保するお作法を確認してみよう
Itemset *init_itemset(size_t number, int seed) {
    Itemset *list = (Itemset *)malloc(sizeof(Itemset));

    Item *item = (Item *)malloc(sizeof(Item) * number);

    srand(seed);
    for (int i = 0; i < number; i++) {
        item[i].value = 0.25 * (rand() % 200);
        item[i].weight = 0.25 * (rand() % 200 + 1);
    }
    *list = (Itemset){.number = number, .item = item};
    return list;
}

/*
バイナリ：
品物数　size_t(8バイト)、 
価値　品物数分double(8バイト)、
重さ　品物数分double
*/
Itemset *load_itemset(char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        perror(filename);
        return NULL;
    }
    size_t item_num;
    
    fread(&item_num, sizeof(size_t), 1, fp);
    printf("item num: %ld\n",item_num);
    Itemset *list = (Itemset *)malloc(sizeof(Itemset) * item_num);
    Item *item = (Item *)malloc(sizeof(Item) * item_num);

    for (size_t i = 0; i < item_num; i++) {
        fread(&item[i].value, sizeof(double), 1, fp);
    }
    for (size_t i = 0; i < item_num; i++) {
        fread(&item[i].weight, sizeof(double), 1, fp);
    }
    *list = (Itemset){.number = item_num, .item = item};

    fclose(fp);
    return list;
}

// itemset の free関数
void free_itemset(Itemset *list) {
    free(list->item);
    free(list);
}

// 表示関数
void print_itemset(const Itemset *list) {
    size_t n = list->number;
    const char *format = "v[%d] = %4.1f, w[%d] = %4.1f\n";
    for (int i = 0; i < n; i++) {
        Item *item = get_item(list, i);
        printf(format, i, get_itemvalue(item), i, get_itemweight(item));
    }
    printf("----\n");
}

Item *get_item(const Itemset *list, size_t index) {
    return &(list->item[index]);
}

size_t get_nitem(const Itemset *list) { return list->number; }

double get_itemweight(const Item *item) { return item->weight; }

double get_itemvalue(const Item *item) { return item->value; }
