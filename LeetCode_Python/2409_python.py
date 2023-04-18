"""

2409(easy)统计共同度过的日子数

Alice 和 Bob 计划分别去罗马开会。

给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期 arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。

请你返回 Alice和 Bob 同时在罗马的天数。

你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] 。

"""


def countDaysTogether(
    arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
) -> int:
    datesOfMonths = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    prefixSum = [0]
    for date in datesOfMonths:
        # prefixSum[-1]代表引用列表最后一个元素
        prefixSum.append(prefixSum[-1] + date)

    arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum)
    leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum)
    arriveBobDay = calculateDayOfYear(arriveBob, prefixSum)
    leaveBobDay = calculateDayOfYear(leaveBob, prefixSum)
    # 返回0和相差日期的最大值，省去if比较
    return max(
        0, min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1
    )


def calculateDayOfYear(day: str, prefixSum: list[int]) -> int:
    month = int(day[:2])  # 前两位，即月份
    date = int(day[-2:])  # 后两位，即日期
    return prefixSum[month - 1] + date


arriveAlice = "08-15"
leaveAlice = "08-18"
arriveBob = "08-16"
leaveBob = "08-19"
print(countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob))
