//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/549/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    if(nums.size() == 1)return nums[0];
    sort(nums.begin(), nums.end());
    int i = 1;
    while(i < nums.size()/2 *2){
        if(nums[i - 1] != nums[i]) return nums[i - 1];
        i += 2;
    }
    return nums[i - 1];
    }
};

//开始i += 2写错了，其余ok
