//https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/
//这个动归真交了很多遍，开始初始情况max没写好，在小数据集上错，下次多多测试。

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 4){
            switch(nums.size()){
                case 0: return 0;
                case 1: return nums[0];
                case 2: return max(nums[1],nums[0]);
                case 3: return max(nums[0] + nums[2], nums[1]);
            }
        }
        
        vector<int> amounts(nums.size(),0);
        
        amounts[0] = nums[0];
        amounts[1] = nums[1];
        amounts[2] = nums[0] + nums[2];
        
        for(int i = 3;i < nums.size();i++){
            if(amounts[i - 2] > amounts[i - 3]){
                amounts[i] = amounts[i - 2] + nums[i];
            }else
                amounts[i] = amounts[i - 3] + nums[i];
        }
        return max(amounts[nums.size() -1], amounts[nums.size() -2]);
    }
};


//这个dp写的太烂了，改天重写

//看两个java, 其实除了多了public并没有什么区别

//Iterative + memo (bottom-up)
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}
/*
Iterative + 2 variables (bottom-up)
We can notice that in the previous step we use only memo[i] and memo[i-1], 
so going just 2 steps back. We can hold them in 2 variables instead. 
This optimization is met in Fibonacci sequence creation and some other problems [to paste links].
*/

/* the order is: prev2, prev1, num  */
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = Math.max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}
