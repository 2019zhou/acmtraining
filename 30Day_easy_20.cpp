//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

// 写的又长又丑，终于过了，唉
// 顺便还学习了一下对于vector的某一列进行排序如何排，就是bool static中间的写法
// 

class Solution {
private:
    bool static sortcol(const vector<int>& v1, const vector<int>& v2 ){ 
        return v1[0] < v2[0]; 
    } 
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> candidate;
        int len = trust.size();
        if(len == 0){
            if(N == 1) return 1;
            else return -1;
        }
        sort(trust.begin(), trust.end(), sortcol);
        int initial = trust[0][0];
        int i = 0;
        while(i < len){
            int t = trust[i][0];
            if(t != initial) break;
            else candidate.push_back(trust[i][1]);
            i++;
        }
        int sz = candidate.size();
        int count = 0;
        vector<int> vp(N+1, 0);
        bool status = true;
        for(int i = 0;i < sz;i++){
            int target = candidate[i];
            count = 0;
            for(int j = 0;j < len;j++){
                vp[trust[j][0]]++;
                if(trust[j][1] == target)
                    count++;
            }
            if(vp[target] != 0) continue;
            if(count!= N-1) continue;
            for(int k = 1;k <= N;k++){
                if(k == target) continue;
                else if(vp[k] == 0) status = false;
            }
            if(status == false){
                status = true;
                continue;
            }
            return target;            
        }
        return -1;
    }
};

/*Intuition:
Consider trust as a graph, all pairs are directed edge.
The point with in-degree - out-degree = N - 1 become the judge.

Explanation:
Count the degree, and check at the end.

Time Complexity:
Time O(T + N), space O(N)
*/

// 这个思路真的很可以唉
// 好好学习~
int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N + 1, 0);
        for (auto& t : trust)
            count[t[0]]--, count[t[1]]++;
        for (int i = 1; i <= N; ++i) {
            if (count[i] == N - 1) return i;
        }
        return -1;
    }
 // 从vector 走向图算法！
