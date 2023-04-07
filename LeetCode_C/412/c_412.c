#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
力扣第412题（简单）

给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：

answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
answer[i] == "Fizz" 如果 i 是 3 的倍数。
answer[i] == "Buzz" 如果 i 是 5 的倍数。
answer[i] == i（以字符串形式）如果上述条件全不满足。
*/

char **FizzBuzz(int n)
// int main()
{
    // 创建二维数组
    char **answer = (char **)(malloc((n+1) * sizeof(char)));
    if(answer)
    {
        for (int i = 1; i <= n + 1; i++)
        {
            char* arr = (char*)(malloc(9 * sizeof(char)));
            if(arr)
            {
                if ((i % 3 == 0) & (i % 5 == 0))
                {
                    strcpy(arr, "FizzBuzz");
                }
                else if ((i % 3 == 0) & (i % 5 != 0))
                {
                    strcpy(arr, "Fizz");
                }
                else if ((i % 3 != 0) & (i % 5 == 0))
                {
                    strcpy(arr, "Buzz");
                }
                else
                {
                    sprintf(arr, "%d", i);
                }
            }

            answer[i] = &arr[0];

            printf("answer[%d]=%s and the address is %d\n", i, answer[i], &answer[i]);
            if (i == 1)
                printf("%d\n", &answer[1]);
        }
    }

    printf("over!\n");
    return answer + 1;
}

int main()
{
    int n = 15;
    char a = 0;
    char b = 0;
    char **answer= NULL;
    char* arr = NULL;

    arr = &a;
    answer = &arr;
    answer= FizzBuzz(n);
    for (int i = 0; i < n; i++)
    {
        printf("answer[%d] is %s\n", i, answer[i]);
    }
}