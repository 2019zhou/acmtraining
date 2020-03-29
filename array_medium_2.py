# from collections import defaultdict

class Solution(object):
    def numTeams(self, rating):
        if len(rating) < 3:
            return 0
        
        res = 0
        greater = defaultdict(int)
        less = defaultdict(int)
        
        for i in range(len(rating) - 1):
            for j in range(i + 1, len(rating)):
                if rating[j] > rating[i]:
                    greater[i] += 1
                else:
                    less[i] +=1
        
        for i in range(len(rating) - 2):
            for j in range(i + 1, len(rating)):
                if rating[j] > rating[i]:
                    res += greater[j]
                else: 
                    res += less[j]
                    
        return res
 
 # python木有 ++
 # else 后面加上：
 # range() 前包含，后不包含
 # 这个思路比较好，先统计了每个位置比其大的元素，比其小的元素
 # 然后判断一次，若是大于，res += 第二个数的对应的大
