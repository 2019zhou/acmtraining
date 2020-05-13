//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/

// 这波贪心也算写的不容易
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == 0 ||n == 0) return num;
        for(int i = 0;i < k;i++){
            n = num.size();
            int j = 1;
            while(j < n){
                if(num[j] >= num[j-1]){
                    j++;
                }
                else break;
            }
            num.erase(num.begin()+j-1);
        }
        int len = num.size();
        while(len != 0){
            if(num[0] == '0') num.erase(num.begin());
            else break;
            len = num.size();
        }
        if(len == 0) return {'0'};
        else return num;
    }
};

// 首先是思考到每次只需要贪心，就是只解决一个任务，都满足最优子结构
// 然后是思考每一步如何贪心，使得减少的最多，然后发现只要找到最后一个不减的元素就可以做到
// em,, 我是手动找规律得到的。。（大概还是经验不足
// 途中遇到的错误
// 开始的时候是写的增加 num[j] >= num[j-1]那边，没写等号导致 {‘112’} 1没有过
// 开始还出现过不删0的情况，发现又忘记string里面是放的ch而不是int了
// 本来的返回写的是 return len==0? {'0'}:0 但是编译器报错，不允许这样写
// 还有string如何删除特定位置元素还去google了一番。。

/* stack好像可以进一步减少时间复杂度~*/
//One can simulate the above procedure by using a stack, 
// and obtain a O(n) algorithm. Note, when the result stack (i.e. res) pop a digit, 
// it is equivalent as remove that "peak" digit.

string removeKdigits(string num, int k) {
        string res;
        int keep = num.size() - k;
        for (int i=0; i<num.size(); i++) {
            while (res.size()>0 && res.back()>num[i] && k>0) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);
        
        // trim leading zeros
        int s = 0;
        while (s<(int)res.size()-1 && res[s]=='0')  s++;
        res.erase(0, s);
        
        return res=="" ? "0" : res;
    }
