// 一个dp, wa了多少次才过。。。我太难了
// 看看测试样例都是什么些神奇的东东
// https://leetcode.com/problems/decode-ways

// 特别特别需要注意打头是0，中间是0， 连续0的情况，
// 1212
// 0002
// 0101
// 这些测试样例都fail过。。。

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if(s.size() == 0)
            return 0;
        if(s[0] == '0')
            dp[0] = 0;
        else
            dp[0] = 1;
        int temp;
        for(int i = 1;i < s.size();i++){
            temp = (s[i - 1] - '0')*10 + s[i] - '0';
            if(s[i] == '0'){
                if(temp > 0 && temp <= 26)
                    if(i >= 2)
                        dp[i] = dp[i-2];
                    else
                        dp[i] = 1;
                else
                    break;
            }else if(temp <= 26 && temp> 10){
                if(i >= 2)
                    dp[i] = dp[i - 1] + dp[i - 2];
                else
                    dp[i] = dp[i - 1] + 1;
            }else{
                dp[i] = dp[i - 1];
            }
            // printf("%d\n", temp);
            // printf("dp[i] = %d\n", dp[i]);
            
        }
        return dp[s.size() - 1];
    }
};

// 观摩一下别人的
