// Find Minimum in Rotated Sorted Array
// have duplicated elements & have no duplicated elements

//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3401/

/* tips for when to use start < end in binary search
You use while (start <= end) if you are returning the match from inside the loop.
You use while (start < end) if you want to exit out of the loop first, and then use the result of start or end to return the match.
*/

// without duplicated elements
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int lo = 0;
        int hi = nums.size() -1;
        int mid;
        if(nums[lo] < nums[hi]) return nums[lo];
        while(lo < hi){
            mid = (lo + hi)/2;
            if(nums[mid] > nums[lo]) lo = mid;
            else hi = mid;           
        }
        return nums[lo + 1];
    }
};


// with duplicated elements
class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        if(nums.size() == 1) return nums[0];
        int lo = 0;
        int hi = nums.size() -1;
        int mid;
        if(nums[lo] < nums[hi]) return nums[lo];
        while(lo <= hi){
            while(lo + 1 < sz){
                if(nums[lo] == nums[lo + 1]) lo = lo + 1;
                else break;
            }
            if(lo >= hi) return nums[hi];
            while(hi -1 > 0){
                if(nums[hi] == nums[hi - 1]) hi = hi -1;
                else break;
            }
            mid = (lo + hi)/2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if(nums[mid] > nums[lo]) lo = mid + 1;
            else hi = mid;
        }
        return -1;
    }
};

// 这里使用了比较笨拙的解法，但是还是挺有效果的

// a simple & concise answer
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};