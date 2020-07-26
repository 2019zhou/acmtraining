// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

class Solution(object):
    def addDigits(self, num):
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9

// 代码很简单，主要是后面的数学原理
// 上面的python代码是一个在十进制下面的原理
// 具体证明还是 add digits question下面的解析讲的清楚~