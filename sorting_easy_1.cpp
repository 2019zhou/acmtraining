//https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(j >=0){
            if(i<0 || nums1[i] < nums2[j]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }
            
    }
};


// 骄傲了，简洁而优美 & ac
// 第一次交光想着写的简洁点，结果忘记i<0 这个条件了。。。
// 导致 [0] 0 [1]1 这个样例没过，下次一定反复测试之后交qaq
