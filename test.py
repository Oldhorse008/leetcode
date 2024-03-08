class Solution:
    def search(self, nums, target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid
            elif nums[mid] == target:
                return mid
        return left


nums = [-1, 0, 3, 5, 9, 12]
target = 3
solu = Solution()
print(solu.search(nums, target))
