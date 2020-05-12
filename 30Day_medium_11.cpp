//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

// 一道非常经典的二分查找题目
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }
};

// my answer
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size();
        while(lo+1 < hi){
            int mid = (hi + lo)/2;
            if(nums[mid+1]!= nums[mid] && nums[mid]!= nums[mid-1]) return nums[mid];
            else if(mid%2 == 0 && nums[mid+1] == nums[mid]) lo = mid + 2;
            else if(mid%2 == 1 && nums[mid-1] == nums[mid]) lo = mid + 1;
            else if(mid%2 == 0 && nums[mid-1] == nums[mid]) hi = mid - 2;
            else if(mid%2 == 1 && nums[mid+1] == nums[mid]) hi = mid - 1;
        }
        return nums[lo];
    }
};

// recursive
int singleNonDuplicate(vector<int>& nums, int st, int end) {
    if (st == end) return nums[st];
    auto mid = st + (end - st) / 2;
    if (nums[mid] == nums[mid + 1]) mid % 2 ? end = mid - 1 : st = mid;
    else mid % 2 ? st = mid + 1 : end = mid;
    return singleNonDuplicate(nums, st, end);
}
int singleNonDuplicate(vector<int>& nums) {
    return singleNonDuplicate(nums, 0, nums.size() - 1);
}
