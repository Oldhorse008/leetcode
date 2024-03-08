#include <stdio.h>
#include <stdlib.h>
#include "compare.h"

int findContentChildren(int *g, int gSize, int *s, int sSize) {
    int i = 0, j = 0, count = 0;

    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    while (i < gSize && j < sSize) {
        while (j < sSize && g[i] > s[j]) {
            j += 1;
        }
        if (j < sSize) {
            count += 1;
        }

        i++;
        j++;
    }

    return count;
}

int main() {
    int g[] = {1, 3, 2}, gSize = sizeof(g) / sizeof(int);
    int s[] = {1, 1}, sSize = 2;
    int ans = findContentChildren(g, gSize, s, sSize);
    printf("%d\n", ans);
    return 0;
}
