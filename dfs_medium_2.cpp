// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3400/

// 一个有一点点浪费的dfs,但是整个比较容易理解
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int l = graph.size();
        vector<vector<int>> paths;
        if(l == 0) return paths;
        vector<int> path;
        dfs(graph, paths, path, 0, l - 1);
        return paths;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int> path, int src, int dst){
        path.push_back(src);
        if(src == dst){
            paths.push_back(path);
        }
        for(auto node : graph[src])
            dfs(graph, paths, path, node, dst);
    }
};


//这个有一点点改进~
class Solution{
public:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& res, vector<int>& path, int cur) {
            path.push_back(cur);
            if (cur == g.size() - 1)
                res.push_back(path);
            else for (auto it: g[cur])
                dfs(g, res, path, it);
            path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(g, paths, path, 0);
        return paths;
    }
}

// 注意到这里使用的是backtracting的思想
// path.pop_back() 和vector<int> & path的使用大大减少了使用的时间
// 还有这一题不适合使用memorization有关的任何算法, 因为需要尝试所有的可能解法