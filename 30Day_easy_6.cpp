//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/

// HashMap直接一遍过了，但是看到solution还是需要感叹，自己的思路过于常规
// 所以即使是easy题目还是记录

// sorting 其实这个很好想，sort时间复杂也就最多O(nlogn), 比全部遍历肯定好很多
class Solution{
public:
     int majorityElement(vector<int>& nums){
        sort(nums.begin(), nums.end());
        return num[nums.size()/2];
     }
};

// Randomization
class Solution {
    private int randRange(Random rand, int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private int countOccurences(int[] nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    public int majorityElement(int[] nums) {
        Random rand = new Random();

        int majorityCount = nums.length/2;

        while (true) {
            int candidate = nums[randRange(rand, 0, nums.length)];
            if (countOccurences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }
}
// solution java版本，感觉不太看好这样子，这个randomization还是有可能使得时间复杂度无穷大的
// 每看到一个数字还是要全部搜一遍整个数组


// Divide & Conquer 分而治之
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size()-1);
    }
private:
    int countelement(vector<int>& nums, int lo, int hi, int element){
        int count = 0;
        for(int i = lo;i <= hi;i++){
            if(nums[i] == element)
                count++;
        }
        return count;
    }
    int majorityElement(vector<int>& nums, int lo, int hi){
        if(hi == lo) return nums[lo];
        int mid = (lo + hi)/2;
        int left = majorityElement(nums, lo, mid);
        int right = majorityElement(nums, mid+1, hi);
        if(left == right) return left;
        int leftCount = countelement(nums, lo, mid, left);
        int rightCount = countelement(nums, mid+1, hi, right);
        return leftCount>rightCount ? left: right;
    }
};
// 时间O(nlogn)
// 空间O(logn)
// 应该是上述以个解法中最好的，稳定性也比alogrithm库中的快排好

 //Boyer-Moore Voting Algorithm
 // 时间复杂度O(n), 空间O(1)
 // 算法是这样的：
 // 如果看到一个比这个数字大的count++, 比这个数字小的count--
 // 分析下述两组数组，可以发现当 count = 0 然后丢弃全部前缀是可以的，因为majority依然还是majority
 // [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
//Here, the 7 at index 0 is selected to be the first candidate for majority element. count will eventually reach 0 after index 5 is processed, so the 5 at index 6 will be the next candidate. In this case, 7 is the true majority element, so by disregarding this prefix, we are ignoring an equal number of majority and minority elements - therefore, 7 will still be the majority element in the suffix formed by throwing away the first prefix.
//[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]
 class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}

// HashMap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> np;
        for(auto ch:nums){
            if(!mp.count(ch))np.push_back(ch);
            mp[ch]++;
        }
        for(auto ch:np)
            if(mp[ch] > n/2) res = ch;
        return res;
    }
};
