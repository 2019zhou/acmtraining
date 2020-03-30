//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
//find the first unique character in a string

class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = collections.Counter(s);
        for idx, ch in enumerate(s):
            if count[ch] == 1:
                return idx
        return -1
 
 
 
 // python nb! over!
