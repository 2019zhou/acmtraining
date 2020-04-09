//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n = (int)S.size();
        int m = (int)T.size();
        int i = n - 1;
        int j = m -1;
        int mems[201] ={0};
        int memt[201] ={0};
        int count = 0;
        while(i >= 0){
            if(S[i] == '#'){
                count++;
                mems[i] = -1;
            }else{
                mems[i] = count;
                if(count > 0) count--;
            }
            i--;
        }
        count = 0;
        while(j >= 0){
            if(T[j] == '#'){
                count++;
                memt[j] = -1;
            }else{
                memt[j] = count;
                if(count> 0) count--;
            }
            j--;
        }
        i = 0;
        j = 0;
        while(i < n or j < m){
            while(i < n and mems[i] != 0)i++;
            while(j < m and memt[j] != 0)j++;
            if(i >= n and j>=m) return true;
            else if(i >= n or j>= m) return false;
            else{
                if(S[i] == T[j]){
                    i++;
                    j++;
                }
                else return false;
            }
        }
        return true;
    }
};

// 这是一种浪费空间而且不是很优美的解法，但是好像执行时间什么都挺好？？
// 注意开始的时候if(count> 0) count--; 之前的if(count)的条件没有写好

//solution中有两种完全思路不同的解法
class Solution(object):
    def backspaceCompare(self, S, T):
        def build(S):
            ans = []
            for c in S:
                if c != '#':
                    ans.append(c)
                elif ans:
                    ans.pop()
            return "".join(ans)
        return build(S) == build(T)
  
 
 // emmm 这个思路很对啊！！我是卡在哪里没想到。。。
 
 class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S.charAt(i) == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T.charAt(j) == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j))
                return false;
            // If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        return true;
    }
}

// 这个思路其实和我的差不多，但是大大优化了空间 做到了O(1) space;
// 感觉也很对啊，其实引入计数器就足够了，为什么还要开辟空间呢~~
// 改天用C++ 把这个写一遍
