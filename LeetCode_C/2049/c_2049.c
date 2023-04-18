/*

2409(easy)统计共同度过的日子数

Alice 和 Bob 计划分别去罗马开会。

给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期 arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。

请你返回 Alice和 Bob 同时在罗马的天数。

你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] 。

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 注意宏定义的时候是直接替换文字，所以要注意括号问题
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

// 计算过程中一定要注意数组和数组之间的对应关系，比如月份和过去的天数
int days(char *date, int *presum) {
    int month = (date[0] - '0') * 10 + (date[1] - '0');
    int dates = (date[3] - '0') * 10 + (date[4] - '0');
    return presum[month - 1] + dates;
}

int countDaysTogether(char *arriveAlice, char *leaveAlice, char *arriveBob, char *leaveBob) {
    int dates[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int presum[13] = {0};
    for (int i = 1; i < 13; i++) {
        presum[i] = dates[i - 1] + presum[i - 1];
    }

    int arriveAliceDay = days(arriveAlice, presum);
    int leaveAliceDay = days(leaveAlice, presum);
    int arriveBobDay = days(arriveBob, presum);
    int leaveBobDay = days(leaveBob, presum);
    int day = (min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1);
    return max(0, day);
}

int main() {
    char *arriveAlice = "10-01", *leaveAlice = "10-31", *arriveBob = "11-01", *leaveBob = "12-31";
    int day = countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);
    printf("两个人相聚的天数为：%d\n", day);
}