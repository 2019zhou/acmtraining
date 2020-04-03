//https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/648/
//reverse bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0;i < 32;i++){
            result = (result<<1) +(n>>i &1);
        }
        return result;
    }
};


// 这个思想挺巧的
// 注意运算级的优先问题， (result << 1) 一定要加括号 + 的运算级比<< 高，会先算
