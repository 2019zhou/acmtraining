//https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/

// 错误示范，开始时这样写的
// 但是写完就后悔了，因为像 “baab”这样的情况事没有解决的
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, pair<int,int>> mp;
        for(auto x:s){
            mp[x].first++;
            mp[x].second = -1;
        }
        int count = 1;
        int temp;
        for(int i = 0;i < s.size();i++){
            if(mp[s[i]].first != 1){
                if(mp[s[i]].second == -1) mp[s[i]].second = i;
                else{
                    temp = i - mp[s[i]].second;
                    if(temp > count) count = temp;
                    mp[s[i]].second = i;
                }
            }
         }
        return count;
    }
    
// 正解是使用了sliding window方法
// 但是貌似brute force + a little optimize 也可以过
// a sliding window 就是知道一个端点，然后可以在线性的复杂程度在找到另外一个端点
// 基本思想就是找端点是和上一个是一样的，都是找repetitive s[i]的上一个出现的位置
// 但是如何避免嵌套的repetitive解决方案是一边移动一边更新 i的选取 可能是i,可能是vp[s[j]]+1, 选取其中最大的那个
// 就是说如果是中间没有嵌套repetitive 选取的是s[i]上一个出现位置的后一个，如果有，i肯定已经早就被更新为更大一点的一个值，
// 所以直接 max(vp[s[j]+1, i)就可以
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> vp(128, -1);
        int count = 0;
        for(int i = 0, j = 0;j < n;j++){
            i = max(vp[s[j]]+1, i);
            count = max(count, j-i+1);
            vp[s[j]] = j;
        }
        return count;
    }
};
};
