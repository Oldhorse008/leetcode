"""
给你一个下标从 0 开始的字符串 s ，该字符串仅由小写英文字母组成，s 中的每个字母都 恰好 出现 两次 。另给你一个下标从 0 开始、长度为 26 的的整数数组 distance 。
字母表中的每个字母按从 0 到 25 依次编号（即，'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25）。
在一个 匀整 字符串中，第 i 个字母的两次出现之间的字母数量是 distance[i] 。如果第 i 个字母没有在 s 中出现，那么 distance[i] 可以 忽略 。
如果 s 是一个 匀整 字符串，返回 true ；否则，返回 false 。

示例 1：

输入：s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
输出：true
解释：
- 'a' 在下标 0 和下标 2 处出现，所以满足 distance[0] = 1 。
- 'b' 在下标 1 和下标 5 处出现，所以满足 distance[1] = 3 。
- 'c' 在下标 3 和下标 4 处出现，所以满足 distance[2] = 0 。
注意 distance[3] = 5 ，但是由于 'd' 没有在 s 中出现，可以忽略。
因为 s 是一个匀整字符串，返回 true 。

"""

'''方法一 枚举 时间复杂度高
def checkDistances(s, distance):
    """
    :type s: str
    :type distance: List[int]
    :rtype: bool
    """
    num = [0] * 26
    # m = 0
    # n = 0

    for i in range(len(s)):
        for j in range(i + 1, len(s)):
            if (s[i] == s[j]) & (distance[ord(s[i]) - 97] != j - i - 1):
                # num[ord(s[i]) - 97] = j - i - 1
                # m += 1
                return 0
    return 1

    # for i in range(len(num)):
    #     if chr(97 + i) in s:
    #         if num[i] == distance[i]:
    #             n += 1

    # if n == m:
    #     return 1
    # else:
    #     return 0

'''


# 方法二 模拟
def checkDistances(s: str, distance: list[int]) -> bool:
    # 字符串长度
    n = len(s)
    # 字母第一次出现的位置
    firstIndex = [0] * 26

    for i in range(n):
        # 计算字母的位置
        idx = ord(s[i]) - 97
        # 如果第一次出现的位置和第二次出现的位置之差不等于distance的值则返回false
        # 加上firstIndex[idx]!=0的目的是保证他不是第一次出现
        if firstIndex[idx] and i - firstIndex[idx] != distance[idx]:
            return 0
        firstIndex[idx] = i + 1  # 方便计算
    return 1


s = "abaccb"
distance = [
    1,
    3,
    0,
    5,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
]
print(checkDistances(s, distance))
