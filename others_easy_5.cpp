//https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/721/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        if(s.size() == 0) return true;
        if(s.size() == 1) return false;
        for(int i = 0;i < s.size();i++){
            switch(s[i]){
                case '(':t.push(s[i]);break;
                case ')':{
                    if(t.size() == 0) return false;
                    else if(t.top() == '(') t.pop();
                    else return false;
                    break;
                }
                case '[':t.push(s[i]);break;
                case ']':{
                    if(t.size() == 0) return false;
                    else if(t.top() == '[') t.pop();
                    else return false;
                    break;
                }
                case '{':t.push(s[i]);break;
                case '}':{
                    if(t.size() == 0) return false;
                    else if(t.top() == '{') t.pop();
                    else return false;
                    break;
                }
            }
            //cout << t.size();
            //cout << t.top() << endl;
        }
        if(t.size()== 0) return true;
        else return false;
    }
};


// 弄stack的时候，stack 不为空的判断 s.top() 
// 常量数据应该可以减少一定的代码量
