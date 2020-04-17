//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3301/

class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size(); if(size == 0) return true;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for(int len=1; len<=size; len++) {
            for(int i=0; i<=size-len; i++) {
                int j = i+len-1;
                bool flag = false;
                for(int k=i; k<=j; k++) {
                    bool seg1 = (k-1)>=i ? dp[i][k-1] : true;
                    bool seg2 = (j-1)>=(k+1) ? dp[k+1][j-1] : true;
                    bool seg3;
                    if((s[k] == '*' && s[j] != '(') || (s[j] == '*' && s[k] != ')') || (s[k]=='(' && s[j]==')')) {seg3 = true;} 
                    else { seg3 = false; }
                    if(seg1==true && seg2==true && seg3==true){flag = true; break;}
                }
                dp[i][j] = flag;
            }
        }
        return dp[0][size-1];
    }
};

// 整体思路是：
// 判断dp[i][j] 的一段
// 如果 s[i] = * 并且 dp[i+1][j] valid
// 如果 s[i] = '(' 并且从后面选择一个k, k可以当作')' 使得dp[i+1, k-1] dp[k+1, j]都是valid
// 并且s[i] = 

//Line 23: Char 123: runtime error: load of value 190, which is not a valid value for type 'bool' (solution.cpp)
//SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:33:123
// 反复报错 undefined-behavior bool，结果是c++ bool数据没有初始化，就会有这个情况
// 然后因为size是变量，必须用一个值

//class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for(int i = 0;i < s.size();i++){
            lo += s[i]=='(' ? 1 :-1;
            hi += s[i]==')' ? 1 :-1;
            lo = max(lo, 0);
        }
        return lo == 0;
    }
};

// Greedy method好
// 发现只需要规定是上下边界就可以，
