//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/

// 在无数的wa之后，终于有了AC!!! 这个AC真的恍如隔世了！！！！ 我太难了，现在get写库函数的人多么nb了
// 要处理各种奇奇怪怪的输入
// 包括但不限于
// ""  "" 
// "aaa" "aaaaa" 也就是匹配的串比要匹配的串要短
// "mississippi" "issipi" 这组看起来问题不是很大，但是-1不会因为i-j返回，所以要判断什么时候返回，一定是两个条件同时满足
// "" "a"



// 算法kmp我查了3遍，才写全对
// 主要问题是string.size() 这个函数的返回类型是size_t
// 所以如果是        while(j < m && i < n) { 这个写成 while(j < haystack.size() && i < needle.size()) 这样是会错误的，第一次是对的，后面就都不对了
// 以后还是不要乱用string.size(), 有空的时候返回写一个(int)string.size() 强制转化成int类型

class Solution {
public:
    int* buildnext(string t) {
        int size = t.size();
        int* next = new int[size];
        next[0] = -1;
        int j = -1;
        int i = 0;
        while (i < size - 1)
            if (j < 0 || t[j] == t[i]) {
                j++; i++;
                next[i] = (t[i] != t[j]) ? j : next[j];
            }
            else
                j = next[j];
        return next;
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int m = needle.size(),j = 0;
        int n = haystack.size(),i = 0;
        if(m > n) return -1;
        int* next = buildnext(needle);
        while(j < m && i < n) {
            if (j < 0 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        delete[] next;
        if(i == n && (j != m)) return -1;
        return i - j;
    }
};
