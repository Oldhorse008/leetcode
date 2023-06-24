"""
力扣第9题（简单）
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
例如，121 是回文，而 123 不是。
"""


def isPlidrome(x):
    if x < 0:
        return False
    div = 1
    # 使除数和被除数的位数一致，以进行取整操作
    while x / div >= 10:
        div *= 10
    while x > 0:
        # 注意pyhton的取余是两个//
        left = x // div
        right = x % 10
        if left != right:
            return False
        x = (x % div) // 10
        div /= 100
    return True


x = 121
print(isPlidrome(x))
