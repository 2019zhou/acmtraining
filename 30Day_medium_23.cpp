//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};

// 为什么总是觉得bit方面的翻转过于精巧qaq, dl又是来了一个one line code
