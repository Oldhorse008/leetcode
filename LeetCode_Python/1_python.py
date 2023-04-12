"""
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，
并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
"""
# 哈希表：可以简单理解为一种映射，将实体和下标唯一对应起来


def twosum(nums, target):
    hash = dict()
    for idx, num in enumerate(nums):
        if target - num in hash:
            return (idx, hash[target - num])
        hash[nums[idx]] = idx
    return []


nums = [2, 3, 10]
target = 9
print(twosum(nums, target))
