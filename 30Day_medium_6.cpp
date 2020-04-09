//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3288/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> temp;
        if(strs.size() == 1){
            temp.push_back(strs[0]);
            res.push_back(temp);
            return res;
        }
        auto copy = strs;
        vector<pair<string,int>> vp;
        
        for (int i = 0; i < strs.size(); ++i) { 
            sort(copy[i].begin(), copy[i].end());
            vp.push_back(make_pair(copy[i], i)); 
        } 
        sort(vp.begin(), vp.end());
        
        temp.push_back(strs[vp[0].second]);
        for(int i = 1;i < strs.size();i++){
            if(vp[i].first == vp[i - 1].first) temp.push_back(strs[vp[i].second]);
            else{
                res.push_back(temp);
                temp.clear();
                temp.push_back(strs[vp[i].second]);
            }
            // for(int i = 0;i < temp.size();i++)
            //     cout << vp[i].first << ends <<temp[i] << ends;
            // cout << endl;
        }
        res.push_back(temp);
        return res;
    }
};


// 我的方法还是挺暴力的，注意到vector<pair<int,int>> 这里的方法很好用
// 第一次样例没有过，原因是比较的时候忘记了直接用了vp[i] == vp[i -1]，应该是vp[i].first == vp[i -1].first
// 这里也用到了如何不改变原来的string的情况下把string的顺序调换 auto copy = strs 将copy 调换就可以了
// 这边下面的对于构建那个vector<pair<int,int>> 基本上起到了cheatsheet的作用
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortArr(int arr[], int n)
{

    // Vector to store element 
    // with respective present index 
    vector<pair<int, int> > vp;

    // Inserting element in pair vector 
    // to keep track of previous indexes 
    for (int i = 0; i < n; ++i) {
        vp.push_back(make_pair(arr[i], i));
    }

    // Sorting pair vector 
    sort(vp.begin(), vp.end());

    // Displaying sorted element 
    // with previous indexes 
    // corresponding to each element 
    cout << "Element\t"
        << "index" << endl;
    for (int i = 0; i < vp.size(); i++) {
        cout << vp[i].first << "\t"
            << vp[i].second << endl;
    }
}

// Driver code 
int main()
{
    int arr[] = { 2, 5, 3, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, n);

    return 0;
}


// very smart efficient method 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
//Moreover, since the string only contains lower-case alphabets, we can sort them using counting sort to improve the time complexity.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};

// 大神的算法多多学习了
