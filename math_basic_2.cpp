// math 做的太难。。。。。。
//https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3698/

class Solution {
public:
    int minOperations(int n) {
        if(n == 1)
            return 0;
        int midnum = -1;
        int res;
        if(n%2 == 0){
            res = ((2 * (n/2) - 1 + 1) )* (n/2 - 0) / 2;
        }else{
            res = ((2 * n/2 - 1 + 2) )* (n/2 - 0) / 2;
        }
        return  res;
        
    }
};