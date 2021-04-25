// leetcode daily challenge
// Longest Valid Parentheses
// https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3695/
// dynamic programming


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1;i < s.size();i++){
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = ((i >= 2) ? dp[i - 2]: 0)  + 2;
                }else{
                    int ind = i - dp[i - 1] - 1;
                    //cout << ind << endl;
                    //cout << dp[ind] << endl;
                    if(ind >= 0 && s[ind] == '('){
                        dp[i] = (ind > 0 ) ? dp[ind - 1] + dp[i - 1] + 2 :  dp[i - 1] + 2;
                        //cout << dp[i] << endl;
                    } 
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

// 分析这样的两种情况
// 1. 如果这个位置是 ）才有可能成功，然后如果前面是（那已经匹配成功了
// 2. 如果前面是） 查看i - dp[i -1] -1的地方是不是 （，　如果是那说明也是匹配成功了




// Global and Local Inversions
// https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3697/


class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1) return 0;
        stack<int> st;
        st.push(-1);
        int res;
        for(int i = 0;i < s.size();i++){
            int t = st.top();
            if( t!= -1 && s[t] =='(' && s[i] == ')'){
                st.pop();
                res = max(i - st.top(), res);
            }else{
                st.push(i);
            }
        }
        return res;
    }
};

// use stack to facilitate the process, 首先stack push -1, 之后根据后面的输入如果是 ( 就push, 如果 ) 要判断一下是否正常
//  