//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*multiply all the product to the left and to the right*/
        int sz = (int)nums.size();
        vector<int> left(sz, 1);
        vector<int> right(sz, 1);
        int i = 1;
        int j = sz - 2;
        
        while(i < sz and j >= 0){
            left[i] =nums[i-1]*left[i-1];
            right[j] = nums[j+1]*right[j+1];
            i++;
            j--;
        }
        vector<int> res;
        for(int i = 0;i < sz;i++){
            res.push_back(left[i]*right[i]);
        }
        return res;
    }
};

// 开始的时候思路有点卡
// 开始的时候vector的初始化写错了，尴尬 （size, initial value） 两个交换了位置，结果一直buffer overflow

//solution还给出了一种constant space的解法

class Solution {
    vector<int> productExceptSelf(vector<int> nums) {

        // The length of the input array 
        int length = nums.length;

        // Final answer array to be returned
        vector<int> answer(length, 1);

        // answer[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the left,
        // so the answer[0] would be 1
        for (int i = 1; i < length; i++) {

            // answer[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all 
            // elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // For the index 'i', R would contain the 
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
        }
        return answer;
    }
}
