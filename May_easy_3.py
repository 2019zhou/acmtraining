//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return not collections.Counter(ransomNote) - collections.Counter(magazine)
        
# One line of code yet tell a lot not 间接表达了magazine >= ransomNote的概念
