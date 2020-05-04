'''
Hints
what is the relationship between input and output
input + output = 111....11 in binary format
Is there any corner case?
0 is a corner case expecting 1, output > input
Intuition
Let's find the first number X that X = 1111....1 > N
And also, it has to be noticed that,
N = 0 is a corner case expecting1 as result.
'''
class Solution:
    def findComplement(self, num: int) -> int:
        X = 1
        while X < num:
            X = X*2 + 1
        return X-num
        
# Go From intuition to inspiration
