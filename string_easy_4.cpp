//English learning qaq
// alphanumeric characters = alpha + number 数字加上字母
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            while(i < s.length() && !isalpha(s[i])&&!isdigit(s[i])) i++;
            while(j >= 0 && !isalpha(s[j]) && !isdigit(s[j])) j--;
            if(i >= j) return true;
            //cout << s[i] << ends << s[j] << endl;
            s[i] = s[i] <='Z' ? s[i]:s[i] + 'A' - 'a';
            s[j] = s[j] <='Z' ? s[j]:s[j] + 'A' - 'a';
            //cout << s[i] << ends << s[j] << endl;
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//测试错误的例子
// “,.” 这种可能会超出边界
// 开始的alphanumeric的 理解错误
// 有一个等号写错， 15 ， 16没有写等号
// 导致"Zeus was deified, saw Suez." 这个样例没过。
