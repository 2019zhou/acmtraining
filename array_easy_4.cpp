//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/578/
//using the feature for C+11

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> pq;
        for(auto x:nums){
            if(!mp.count(x))pq.push_back(x);
            mp[x]++;
        }
        
        for(auto i:pq) if(mp[i] > 1) return true;
        return false;
    }
};

//这个思想是把相同元素聚类处理
//unordered_map<int> 用来构造一个映射的哈希表
//pq记录的都是不重复元素
//for(auto i:pq)特性用的不够熟练，i指的是pq种每一个的值，而不是index
