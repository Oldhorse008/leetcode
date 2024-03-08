#include <stdio.h>
#include <stdlib.h>

int compare(
    const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int a[] = {1, 4, 3, 3, 5, 20};
    int length = sizeof(a) / sizeof(int);
    qsort(a, length, sizeof(int), compare);
    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}