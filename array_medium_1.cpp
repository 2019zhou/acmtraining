//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/674/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) return false;
    unordered_map<int, int> mp;
    vector<int> pq;
    for (auto x : nums) {
        if (!mp.count(x)) pq.push_back(x);
        mp[x]++;
    }

    sort(pq.begin(), pq.end());
    int temp;
    for (int i = 0; i < pq.size();) {
        temp = mp[pq[i]];
        mp[pq[i]] -= temp;
        for (int j = 1; j < k; j++) {
            if (pq[i + j] != pq[i] + j) return false;
            if (mp[pq[i + j]] - temp < 0) return false;
            mp[pq[i + j]] -= temp;
        }
        while (mp[pq[i]] == 0) { 
            i++; 
            if (i == pq.size()) return true;
        }
    }
    return true;
}
};

//数组边界的判断还是非常重要 最后的mp while那边还是错了几次
//not fast enough, but use very little memory
