// like bubble ,two pointer method
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
 
 
 //my poor answer, just edit
 class Solution {
public:
    void moveZeroes(vector<int>& nums){
        int step = 0;
        for(int i = 0;i< nums.size();i++){
            if(nums[i] == 0) step ++;
            else nums[i-step] = nums[i];
        }
        for(int j = 1;j <= step;j++)
            nums[nums.size() -j] = 0;
    }
};

//conclusion
//1. 不可以一边用迭代一遍做题，因为迭代要便修改边erase会出问题，不出问题的方法，只能是使用额外空间，但是本题不许用额外空间
//2. 第一个的two pointer method 非常好,自己的只是强行修改vector
