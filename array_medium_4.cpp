// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/
// Single Number III


// 自己的最正常思路，时间空间都是 O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int i = 0;
        int j = 1;
        vector<int> ans;
        while(j < sz){
            if(nums[i] == nums[j]){
                i+=2;
                j+=2;
            }else{
                ans.push_back(nums[i]);
                i = i+1;
                j = j+1;
            }
        }
        if(i == sz -1) ans.push_back(nums[i]);
        return ans;
    }
};

// space O(n), time O(1)
// 首先可以知道所有的A xor A = 0, 所以所有的数字进行xor之后留下的只有要求的不同的两个数字的 xor
// 然后进行分组
// 分组的目的：使得含有A的为一组，含有B的为一组，假设A,B就是要求的那两个不同的数字
// 分组的方法：A xor B不为0的位子上A为1,B为0或者是A为1,B为0, 所以就选取这样的一位, 把所有这一位为1的放在一组,这一位为0的放在一组,在分组的同时xor,就可以直接算出A,B

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};

// 这个解法还可以借鉴的地方是 accumulate的函数的使用, 以及获取set bit就是是1的bit时候使用了diff &= -diff