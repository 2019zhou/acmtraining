#https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/564/
#python 手打indexed block 需要非常注意，没有分号，有冒号，我太难了

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if length < 2: return 0
        max_profit = 0
        for i in range(1, length):
            if prices[i - 1] < prices[i]:
                max_profit += prices[i] -  prices[i - 1]
        return max_profit
  
  #小规模问题，如果单独考虑length = 0, length = 1， 可以少很多麻烦
