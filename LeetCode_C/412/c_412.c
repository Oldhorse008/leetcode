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
answer[i] == i （以字符串形式）如果上述条件全不满足。
*/

char **FizzBuzz(int n)
// int main()
{
    // 创建二维数组
    char **answer = (char **)(malloc((n + 1) * sizeof(char *)));

    for (int i = 1; i <= n; i++)
    {
        answer[i] = (char *)(malloc(9 * sizeof(char)));

        if ((i % 3 == 0) & (i % 5 == 0))
        {
            strcpy(answer[i], "FizzBuzz");
        }
        else if ((i % 3 == 0) & (i % 5 != 0))
        {
            strcpy(answer[i], "Fizz");
        }
        else if ((i % 3 != 0) & (i % 5 == 0))
        {
            strcpy(answer[i], "Buzz");
        }
        else
        {
            sprintf(answer[i], "%d", i);
        }

        printf("answer[%d] is %s\n", i, answer[i]);
    }

    printf("over!\n");
    printf("answer[1]的地址%d\n", answer[1]);
    printf("answer的地址%d\n", sizeof(answer));
    return answer + 1;
}

int main()
{
    char **p = FizzBuzz(15);

    printf("p[0] 的地址：%d\n", p[0]);
    printf("P[0]的长度：%d\n", sizeof(p[0]));
    for (int i = 0; i < 15; i++)
    {
        printf("answer[%d] = %s\n", i + 1, p[i]);
        free(p[i]);
    }

    free(p);
    return 0;
}