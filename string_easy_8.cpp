//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/


class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string res = "1";
        string cur = "";
        int count = 0;
        while(--n){
            cur = "";
            for(int i = 0;i < res.size();i++){
                count= 1;
                while((i + 1 < res.size()) && res[i] == res[i+1]){
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};


// 开始的时候用queue想做出来，发现queue转化到string都是个大问题
// 这个思路的 string + 运算符，还有to_string运算符都可
// 各种的初始化要分清楚，开始count初始化错过一次
// 这里的设置cur / res 而且不断更新的思路值得学习
