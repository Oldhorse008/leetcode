/*
力扣第9题（简单）
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
例如，121 是回文，而 123 不是。
*/

#include <stdio.h>
#include <stdbool.h>

int isPlidrome(int x) {
    int div = 1;
    int left = 0;
    int right = 0;
    if (x < 0)
        return false;
    while (x / div >= 10)
        div *= 10;
    while (x > 0) {
        left = x / div;
        right = x % 10;
        if (left != right)
            return false;
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

int main() {
    int x = 121;
    bool res;
    res = isPlidrome(x);
    printf("是否是回文数：%d", res);
}