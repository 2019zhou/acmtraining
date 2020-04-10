//https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/878/

class Solution {

public:
    int romanToInt(string s) {
        unordered_map<char, int> mp= {{'I', 1},
                                      {'V', 5},
                                      {'X', 10},
                                      {'L', 50},
                                      {'C', 100},
                                      {'D', 500},
                                      {'M', 1000}};
        int sum = mp[s.back()];
        for(int i = s.length()-2;i>=0;i--){
            if(mp[s[i + 1]] > mp[s[i]]) sum-= mp[s[i]];
            else sum += mp[s[i]];
        }
        return sum;
    }
};

// 开始还想用enum做，后来发现小的程序其实unordered_map无比的好用
// 本来的复杂的题目（题目字很多）
// 解决的非常clean 
// end the easy interview set!!!

