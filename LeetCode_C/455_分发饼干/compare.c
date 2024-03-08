#include "compare.h"

// 比较函数
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
