//biweekly contest for leetcode

// problem 2
/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.
Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.
*/

// my solution, I think is perfect for C++
class Solution {
private:
    int spacenum(string a){
        int num = 0;
        for(int i = 0;i < a.size();i++){
            if(a[i] == ' ')
                num ++;
        }
        return num;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2){
            return true;
        }
        int i, j;
        int m, k;
        m = sentence1.size() - 1;
        k = sentence2.size() - 1;
        int num = 0;
        int sign = 0;
        for(;i < sentence1.size() && j < sentence2.size();i++, j++){
            if(sentence1[i] == ' ' && sentence2[j] == ' '){
                num++;
            }       
            if(sentence1[i] != sentence2[j])
                break;
        }
        if(i == sentence1.size() && sentence2[j] == ' ')
            num++;
        if(j == sentence2.size() && sentence1[i] == ' ')
            num++;
        for(;m >= 0 && k >= 0;m--, k--){
            if(sentence1[m] == ' ' && sentence2[k] == ' '){
                num++;
            }   
            if(sentence1[m] != sentence2[k])
                break;
        }
        if(m == -1 && sentence2[k] == ' ')
            num++;
        if(k == -1 && sentence1[m] == ' ')
            num++;
        //cout << num << endl;
        if(num == min(spacenum(sentence1) + 1, spacenum(sentence2)+1))
            return true;
        else
            return false;
    }
};

// Yet due to the inability of C++ split function, python probably is in nature a better choice than C++ 

class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        w1 = sentence1.split(" ")
        w2 = sentence2.split(" ")
        n1, n2 = len(w1) ,len(w2)
        if n1<n2:
            w1, w2 = w2, w1
            n1, n2 = n2, n1
        s, e = 0, n2-1
        i=0
        # print w1, w2
        while s<n2:
            if w1[i]!=w2[s]: break
            i+=1
            s+=1
        i=n1-1
        while e>=s:
            if w1[i]!=w2[e]: break
            i-=1
            e-=1
        return s>e


// problem C is what is perceived as the most typical one
// mark the trick he uses
// just a min to submit & pass SADDD!!



class Solution {
    int rev(int x) {
        static char buf[11];
        int len = sprintf(buf, "%d", x);
        reverse(buf, buf + len);
        sscanf(buf, "%d", &x);
        return x;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> ctr;
        for(int x : nums)
            ++ctr[x - rev(x)];
        const int mod = (int)1e9 + 7;
        int ans = 0;
        for(auto &it : ctr)
            ans = (ans + it.second * (it.second - 1LL) / 2) % mod;
        return ans;
    }
};



class Solution(object):
    def countNicePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cs = {}
        for v in nums:
            v2 = int(str(v)[::-1])
            # print v, v2
            v2 -= v
            if v2 not in cs: cs[v2]=0
            cs[v2]+=1
        r = 0
        for k in cs:
            c = cs[k]
            r += c*(c-1)/2
            r %= 1000000007
        return r