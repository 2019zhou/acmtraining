//https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/722/
// 很简单的一道missing number 题目，解法很多

// Approach 1: sorting
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};

// Approach2: Hashmap
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums)mp[x]++;
        for(int i = 0;i <= nums.size();i++){
            if(!mp.count(i)) return i;
        }
        return -1;
    }
};

// Approach3: Bit manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for(int i = 0;i < nums.size();i++){
            missing ^= i^nums[i];
        }
        return missing;
    }
};
// 这个方法看起来要用到bit翻转，实际上就是i和nums[i]取异或看看一不一样，
// 然后和missing取异或，因为如果没有满足的条件的，说明nums.size()内部的都满足条件
// 所以就是nums.size() 这个数字啦啦啦

// 最后一种方法就是 先算出1-n 所有的总和，然后算出给的所有的数字的总和，两个相减，就得到要的数字
// sum_expected = n*(n-1)/2;
