//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3298/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int counti = 0;
        int maxlen = 0;
        mp[0] = -1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0) counti--;
            else counti++;
            //cout << counti << ends << i << endl;
            if(!mp.count(counti)) mp[counti] = i;
            else maxlen = max(maxlen, i-mp[counti]);
            //cout << i - mp[counti] << endl;
        }
        return maxlen;
    }
};

// 这个应该和以前的一个股票问题有点类似，需要一起看一下
// 算是medium的题目
// 觉得比较难想的地方在于找到两个相同的结果的值，判断距离
// mp[0] = -1 set o at index -1 这个哨兵设置的非常巧妙了
// comeon
