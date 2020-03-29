//https://leetcode.com/contest/weekly-contest-182/problems/find-lucky-integer-in-an-array/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> pq;
        for(auto x:arr){
            if(!mp.count(x))pq.push_back(x);
            mp[x]++;
        }
        sort(pq.begin(), pq.end());
        for(int i = pq.size()-1;i >=0;i--){
            if(mp[pq[i]] == pq[i]) return pq[i];
        }
        return -1;
    }
};


//哭辽， easy居然wa了两次，第一次是想优化想多了，不存在优化
//还有没有考虑是总是输出最大。。。
