// leetcode-cn的比赛
// medium解法非常暴力，居然也过了。。
// easy的第二题的知识可以重温一下，到达某一点的路径的指定步数的解法
// 矩阵的相乘- 相乘几次代表走几步（离散数学）

// 剧情触发时间
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        vector<int> res;
        vector<vector<int>> jr(requirements.size(),vector<int>(3, -1));
        int size = requirements.size();    
        vector< pair<int, int>> mpC;
        vector< pair<int, int>> mpR;
        vector< pair<int, int>> mpH;
        for(int i = 0;i < size;i++){
            mpC.push_back(make_pair(requirements[i][0],i));
            mpR.push_back(make_pair(requirements[i][1],i));
            mpH.push_back(make_pair(requirements[i][2],i));
        }
        sort(mpC.begin(), mpC.end());
        sort(mpR.begin(), mpR.end());
        sort(mpH.begin(), mpH.end());
        int sumC = 0;
        int sumR = 0;
        int sumH = 0;
        int itC = 0, itR = 0, itH = 0;
        for(int i = 0;i < increase.size();i++){
            sumC += increase[i][0];
            sumR += increase[i][1];
            sumH += increase[i][2];
            while(itC < size && sumC >= (mpC.begin()+itC)->first){
                jr[(mpC.begin()+itC)->second][0] = i + 1;
                itC ++; 
            }
            while(itR < size && sumR >= (mpR.begin()+itR)->first){
                jr[(mpR.begin()+itR)->second][1] = i + 1;
                itR ++; 
            }
            while(itH < size && sumH >= (mpH.begin()+itH)->first){
                jr[(mpH.begin()+itH)->second][2] = i + 1;
                itH ++; 
            }
            //cout << itC << ends << itR << ends << itH << endl;
        }
        //cout << endl;
        for(int i = 0;i < size;i++){
            for(int j = 0;j < 3;j++)
            if(requirements[i][j] == 0)
                jr[i][j] = 0;
        }
        for(int i = 0 ;i < requirements.size();i++){
            //cout << jr[i][0] << ends << jr[i][1] << ends <<jr[i][2]<< endl;
            if(jr[i][0] == -1 ||jr[i][1] == -1 ||jr[i][2] == -1) {
                res.push_back(-1);
                continue;
            }
            int temp = max(jr[i][0], max(jr[i][1], jr[i][2]));
            res.push_back(temp);
        }
        return res;
    }
};
// 枚举，用一下pair，排序之后标注，应该是我的解法里面唯一的优化了，该题的样例非常友好，还会提醒一种可能遗漏的情况
// 自己做时间长的原因主要还是容器用的不熟练，然后查了好久怎么用，

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<vector<int>> g(n, vector<int>(n, 0));
        for(int i = 0;i < relation.size();i++){
            graph[relation[i][0]][relation[i][1]] = 1;
            g[relation[i][0]][relation[i][1]] = 1;
        }
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i = 0;i < k -1;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++){
                    for(int l = 0;l < n;l++){
                        res[j][k] += g[j][l] * graph[l][k];
                    }
                }
            }
            for(int i=0; i<n; i++)  {  
                for(int j=0; j<n; j++)  { 
                    g[i][j] = res[i][j];  
                    //cout << g[i][j] << ends;
                    res[i][j] = 0;
                }  
                //cout << endl;
            }
        }
        return g[0][n-1];    
    }
};
// 矩阵相乘
