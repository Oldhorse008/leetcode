"""
力扣第412题（简单）

给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：

answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
answer[i] == "Fizz" 如果 i 是 3 的倍数。
answer[i] == "Buzz" 如果 i 是 5 的倍数。
answer[i] == i （以字符串形式）如果上述条件全不满足。
"""


class solution:
    def FizzBuzz(n):
        answer = [0] * (n + 1)
        for i in range(0, n + 1):
            if (i % 3 == 0) & (i % 5 == 0):
                answer[i] = "FizzBuzz"
            elif (i % 3 == 0) & (i % 5 != 0):
                answer[i] = "Fizz"
            elif (i % 3 != 0) & (i % 5 == 0):
                answer[i] = "Buzz"
            else:
                answer[i] = str(i)
        return answer[1:]  # 从一返回


a = solution.FizzBuzz(15)
# for i in range(1, 5):
#     print(i)  #可见range的步长为正数的时候是左开右闭的
print("answer[0]的值是%s" % a[0])  # 可见返回后的值是从a[0]开始赋值的
for i in range(0, 15):
    print(a[i])
