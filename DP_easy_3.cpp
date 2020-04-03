// Maximum Subarray
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/566/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j = 0;
        int min = INT_MIN;
        bool sign = 0;
        for(;j < nums.size();j++){
            if(nums[j] >= 0){ sign = 1;break;}
            else if(nums[j] > min) min = nums[j];
        }
        if(sign == 0) return min;
        
        int global_max = 0;
        int local_max = 0;
        for(int i = 0;i < nums.size();i++){
            local_max = max(local_max + nums[i], nums[i]);
            global_max = max(local_max, global_max);
            //cout << local_max << ends << global_max << endl;
        }
        return global_max;
    }
};

//分解为一个小的子问题，
// -2,1,-3,4,-1,2,1,-5,4
// 对于1 考虑sub question (-2) 和1 所以总是 （num, num + subresult）的较大的哪一个就是
// 引入global max 的原因相当于那个max, 因为local max 一定是指判断到最后一个的结果，但是可能中间就已经出现了一个最大值
// 上述的一串数 执行到最后一个 local max = 5, global max在 2 1的地方就已经取到了相当于max 
