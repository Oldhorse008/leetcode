/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，
并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
*/

#include <stdio.h>
#include <stdlib.h>

// 暴力循环 注意！空指针不可以赋值！！一定要给指针赋值！！
int *twosum(int *nums, int numsize, int target, int *returnsize) {
    for (int i = 0; i < numsize; i++) {
        for (int j = i + 1; j < numsize; j++) {
            if (target - nums[i] == nums[j]) {
                int *ret = (int *)malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnsize = 2;
                printf("%d\n", ret[0]);
                return ret;
            }
        }
    }
    *returnsize = 0;
    return NULL;
}

int main() {
    int target = 9;
    int nums[] = {3, 6, 9};
    int len = sizeof(nums);
    int *returnsize;
    int arr = 0;
    returnsize = &arr;
    int *a = twosum(nums, len, target, returnsize);
    printf("%d\n", *returnsize);
    for (int i = 0; i < *returnsize; i++)
        printf("%d\n", a[i]);
}