//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/

// 都是经典的可以使用dfs, bfs做出来的题目 和之前写过的number of island一样
// 自己开始卡了一下，还没特别熟练。。说明模板还没背熟。。。


// dfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color != newColor) dfs(image, sr, sc, color, newColor);
        return image;     
    }
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor){
        if(image[r][c] == color){
            image[r][c] = newColor;
            if(r >= 1) dfs(image, r-1, c, color, newColor);
            if(c >= 1) dfs(image, r, c-1, color, newColor);
            if(r+1 < image.size()) dfs(image, r+1, c, color, newColor);
            if(c+1 <image[0].size()) dfs(image, r, c+1, color, newColor);
        }
    }
};

// 但是这题目和number of island唯一的区别就是dfs绝对比较好，拿到题目bfs可以做的更加好一些
