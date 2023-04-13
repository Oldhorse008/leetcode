"""
2040(简单) 出现最频繁的偶数元素

给你一个整数数组 nums ，返回出现最频繁的偶数元素。
如果存在多个满足条件的元素，只需要返回最小的一个。如果不存在这样的元素，返回 -1 。
"""


def mostFrequentEven(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    hash = dict()
    count = [0] * len(nums)
    temp = [0] * len(nums)
    tem = 0
    flag = 0
    answer = 0
    for i, num in enumerate(nums):
        if num not in hash and (num % 2 == 0 or num == 0):
            hash[num] = i
            temp[i] = num
            count[i] += 1
        elif num in hash:
            count[hash[num]] += 1
    for i in range(len(count)):
        if count[i] > tem:
            tem = count[i]
            answer = nums[i]
        elif count[i] == tem and tem != 0:
            if nums[i] < answer:
                answer = nums[i]
        else:
            flag += 1
    if flag == len(count):
        return -1
    else:
        return answer


nums = [29, 47, 21, 41, 13, 37, 25, 7]
print(mostFrequentEven(nums))
