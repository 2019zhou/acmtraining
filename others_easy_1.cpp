//https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/565/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for(int i = 0;i < 32;i++){
            if(n&1) sum++;
            n = n>>1;
        }
        return sum;
    }
};

// 开始写的时候右移写成了> 。。。。。。

// flip the least significant bit
// 每次反转一个bit 直至到0，这里有一个技巧，n& n-1 按位与总是会反转一个n的比特，反复使用这个技巧，可以在一些情况省时间

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n!= 0){
            sum++;
            n &= n-1;
        }
        return sum;
    }
};
