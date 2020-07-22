//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/
// 写了一个dfs练习一下
// 这里使用了空间的record来记录有没有以前使用过
// 出现错误 开始的时候忘记了x对应的是board.size()
//         record之前是true的后来要改回false 下面的20, 38行都是这样
//         因为上面讲的两个错误尴尬的wa了两次。。。

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int l = board.size();
        int m = board[0].size();
        vector<vector<bool>> record(l, vector<bool>(m, 0));
        for(int i = 0;i < l;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == word[0]){
                    record[i][j] = true;
                    if(existHelper(board, record, i, j, word, 1))
                        return true;
                    record[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool existHelper(vector<vector<char>>& board, vector<vector<bool>>& record,int x, int y, string word, int index){
        if(index == word.size()) return true;
        int l = board.size();
        int m = board[0].size();
        bool tempjudge = false;
        if(x < l - 1){
            if(!record[x + 1][y] && word[index] == board[x + 1][y]){
                record[x + 1][y] = true;
                if(existHelper(board,record, x + 1, y, word, index + 1))
                    tempjudge = true;
                else record[x + 1][y] = false;
            }
        }
        if(x > 0){
            if(!record[x - 1][y] && word[index] == board[x - 1][y]){
                record[x - 1][y] = true;
                if(existHelper(board,record, x - 1, y, word, index + 1))
                    tempjudge = true;
                else record[x - 1][y] = false;
            }
        }
        if(y > 0){
            if(!record[x][y - 1] && word[index] == board[x][y - 1]){
                record[x][y - 1]= true;
                if(existHelper(board,record, x, y - 1, word, index + 1))
                    tempjudge = true;
                else record[x][y - 1] = false;
            }
        }
        
        if(y < m - 1){
            if(!record[x][y + 1] && word[index] == board[x][y + 1]){
                record[x][y + 1] = true;
                if(existHelper(board,record, x, y + 1, word, index + 1))
                    tempjudge = true;
                else record[x][y + 1] = false;
            }
        }
        return tempjudge;
    }
};