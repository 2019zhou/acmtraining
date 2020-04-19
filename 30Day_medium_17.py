//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/

// 自己想法和solution的完全一致，但是
// 在考虑什么情况下要继续搜索的时候考虑的不是非常清楚
// nums[0] <= target <= nums[i]
//               target <= nums[i] < nums[0]
//                         nums[i] < nums[0] <= target
/*
            /
           /
   nums[0]/
                    / nums[i]
                   /
 第一种情况比较好理解，第2，3种情况就是判断是在上面的半条线上，还是下面的半条线上              
*/
class Solution(object):
    def search(self, nums, target):
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = (lo+hi) // 2
            if nums[mid] == target:
                return mid
            if nums[0] <= target < nums[mid] or target < nums[mid] < nums[0] or nums[mid] < nums[0] <= target:
                hi = mid - 1
            else:
                lo = mid + 1
        
        return -1

// 其中判断条件的语句
// 可以使用XOR代替
def search(self, nums, target):
    lo, hi = 0, len(nums) - 1
    while lo < hi:
        mid = (lo + hi) / 2
        if (nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]):
            lo = mid + 1
        else:
            hi = mid
    return lo if target in nums[lo:lo+1] else -1

// C++ version

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while(lo < hi){
            mid = (lo + hi)/2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])){
                lo = mid + 1;
            }
            else hi = mid;
        }
        return lo == hi && nums[lo] == target? lo : -1;
    }
};

// 感觉有关的lo, hi还有要不要去端点值的问题需要好好深入理解
