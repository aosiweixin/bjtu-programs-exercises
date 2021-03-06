#include <stdio.h>

/*
Author Inter Horse
Date 2020-07-14

Tower of Hanoi
成绩: 5 / 折扣: 0.8
题面描述

变种汉诺塔问题和普通汉诺塔问题略有不同，规则描述如下：

1. 有三根柱子，在最左侧柱子上放置着若干圆盘。与传统汉诺塔不同的是，其中存在部分大小相同的圆盘。

2. 要求包括初始状态在内，每个圆盘上方放置的圆盘不得大于该圆盘，即圆盘上方只能放置小于自己或和自己相同大小的圆盘。

3. 每次移动只能将某柱子最顶部的一个圆盘移动到另一柱子的最顶部。

4. 需要注意的是，大小相同的圆盘具有的其他特征是不一样的，例如不同颜色。

最后需要保证 2 号柱子上的圆盘排列顺序，和开始时的 0 号柱子上的顺序完全相同。

求将初态 0 号柱子上的所有圆盘全部移到 2 号柱子上最优策略的步数 l 对 m 取模后的值。

输入数据
对于每组数据：

第一行有一个整数 t (1 ≤ t ≤ 100 ) ，表示有 t 组数据。
第一行包括 2 个数字 n,m (1≤n≤15000, 1≤m≤1000000) ，其中 n 代表圆盘种类的个数；

第二行包括 n 个数字 a1, … , an (1 ≤ ai≤ 99 )，其中 ai 代表大小为 i 的圆盘个数。

输出数据
对于每组数据，输出一行，若最优策略的步数为 l ，则输出 l mod m 。

样例输入
2
2 1000
1 2
3 1000
1 2 3
样例输出
7
21

时间限制：1秒
内存限制：无限制
 */
int main() {
    // t, n, m
    int t, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        // 存放汉诺塔
        int arr[n];
        // 普通汉诺塔挪动次数
        int normal[n];
        // 特殊汉诺塔拖动次数
        int unusual[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        // 普通汉诺塔挪动次公式： A(n) = A(n-1) * 2 + 1;
        normal[0] = arr[0];
        for (int j = 1; j < n; j++) {
            normal[j] = ((2 * normal[j - 1]) % m + arr[j]) % m;
        }
        unusual[0] = 2 * arr[0] - 1;
        for (int j = 1; j < n; j++) {
            if (arr[j] == 1) {
                // 下面种类盘子数量只有一个的情况
                unusual[j] = ((2 * normal[j - 1]) % m + 1) % m;
            } else {
                // 下面种类盘子数量大于一个的情况
                unusual[j] = ((2 * normal[j - 1]) % m + 2 * arr[j] + unusual[j - 1]) % m;
            }
        }
        printf("%d\n", unusual[n - 1]);
    }
    return 0;
}