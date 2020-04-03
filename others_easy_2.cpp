//https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/762/

class Solution {
public:
    int hammingDistance(int x, int y) {
        uint32_t t = x^y;
        int sum = 0;
        while(t!= 0){
            sum++;
            t &= t-1;
        }
        return sum;
    }
};


// 在第一题的基础上进行的一个hammingDistance 注意t的类型uint32_t 如果是int 会有样例不通过
