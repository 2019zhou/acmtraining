//https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/745/

//1. 将数字转化为3进制，然后正则表达式匹配
// 2. 正则表达式匹配应该是以1 为起始，后面都是0的一个表达式
public class Solution {
    public boolean isPowerOfThree(int n) {
        return Integer.toString(n, 3).matches("^10*$");
    }
}


// C中使用fmod判断float 的余数是否为0 -> 在 #include <cmath>库中
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
};

// 使用the limit of integer 解，因为integer < 2^32， 可以算出最大的3的倍数是多少，然后看一下这个数%n 的余数是否为 0
public class Solution {
    public boolean isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
}


// 也可以不断地除以3直到余数为0，如果是其他的余数就不满足条件了
