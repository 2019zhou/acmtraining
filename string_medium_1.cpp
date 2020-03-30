//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(str[i] == ' ')i++;
        str.erase(str.begin(), str.begin()+i);
        
        i = 0;
        int res = 0;
        bool sign = 0;
        if(str[0] == '+')i++;
        else if(str[0] == '-'){
            sign = 1;
            i++;
        }
        else if(!isdigit(str[i])) return 0;
        else i = 0;
        
        while(i < str.length() && isdigit(str[i])){
            //cout << "initial i:" << i << endl;
            if(res > INT_MAX/10){
                if(sign == 1) return INT_MIN;
                else return INT_MAX;
            }
            else if(res == INT_MAX/10){
                if(str[i]-'0' == 7 && sign == 1) return INT_MIN+1;
                //cout << str[i] << endl;
                if(str[i]-'0' >= 7){
                    if(sign == 1) return INT_MIN;
                    else return INT_MAX;
                }
            }
            str[i] = str[i] -'0';
            res = res*10 + str[i];
            //cout << res << ends << str[i] << endl;
            i++;  
        }
        
        res = (sign == 1)? -res: res;
        return res;
    }
};

// 这个边界情况考虑的我醉了
// 算法不难，很直接的按要求写就完事
// 边界太烦了，
// 开始str[i] -'0' 忘记了一个，结果 2**31-2 没有过
// 后来，-2**31 - 1 没过，因为 
// str[i] = str[i] -'0';
// res = res*10 + str[i];
// 会先算左边的，所以非常容易超限，分开来才可能不报错，不超界限。

//最后还是ac快乐
