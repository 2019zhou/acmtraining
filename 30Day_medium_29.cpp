//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3311/

//Basic DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(text1[i] == text2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                //cout << dp[i+1][j+1] << ends;
            }
            //cout << endl;
        }
        return dp[n][m];
    }
};

// 注意dp的准备工作问题，注意初始化要多出的一行一列要如何处理
// 这里选择的是使用空间换取时间的做法，其实繁琐一点也可以判断一下边界，如果在边界上可以把max的其中一项设置为0
