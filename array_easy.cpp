//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/727/
// in place algorithm - 不使用额外的数据结构的算法
// Easy Section

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0; 
        int i = 0;
        int j = 1;
        while(j < nums.size()){
            while(j!= nums.size() && nums[j] == nums[i]) j++;
            if(j == nums.size()) return i+1;
            else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
};

//[1, 1] AddressSanitizer 数组超过界
// while(j!= nums.size() && nums[j] == nums[i]) j++; 先判断防止越界
// [] 开始没有考虑, 必须分开考虑
