//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/

//Aha, C++ is much faster!!

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(int i = 0;i < s.length();i++){
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};

// test case "" "z"
// 如果使用two pointer method 可能会使得前面的字符忘记，不知道前面有没有重复，但是如果用O(N)的方法，可能消耗过大了
