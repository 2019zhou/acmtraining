//https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        string temp;
        for(int i = 1;i <= n;i++){
           res.push_back(to_string(i));
        }
        int t = 0;
        for(int i = 1;i <= n/3;i++){
            t = 3*i -1;
            res[t] = "Fizz";
        }
        for(int i = 1;i <= n/5;i++){
            t = i*5 -1;
            if(res[t] != "Fizz") res[t] = "Buzz";
            else res[t] = "FizzBuzz";
        }
        return res;
    }
};

//思路清晰，应该就可以ac
// 注意这题用到的int -> string的方法
// to_string() 里面用int, float, double, long double都可，功能比较强大
// int 一般用这个方法就可以，sstream流里也有方法，但是还是float, double的时候，精确度会高一点
