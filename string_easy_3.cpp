//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        else return false;
    }
};

//C++ is great! java cannot be this simple!
//ac first time
