//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/

// Brute force
// time O(n^3)
// space O(1)

//using cumulative sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sumarr(nums.size() + 1, 0);
        int sum = 0;
        int count = 0;
        sumarr[0] = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            sumarr[i+1] = sum;
            for(int j = 0;j <= i;j++){
                //cout << sum << ends << sumarr[j]<< endl;
                if((sum - sumarr[j] == k)){
                    //cout << sum << ends << sumarr[j]<< endl;
                    count++;
                }
            }
        }
        return count;
    }
};

public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
// 这个也差不多啦，空间优化了一点点

public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}

// 这个HashMap的做法值得学习！！！
// Solution里面有动画，很好康
