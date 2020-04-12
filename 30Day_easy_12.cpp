//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3297/

//一个用对了数据结构就非常容易的题目

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for(auto x:stones){
            pq.push(x);
        }
        int bigone;
        int bigtwo;
        while(pq.size() > 1){
            bigone = pq.top();
            pq.pop();
            bigtwo = pq.top();
            pq.pop();
            if(bigone == bigtwo) continue;
            else pq.push(bigone-bigtwo);
        }
        return pq.size()==0 ?0:pq.top();
    }
};

// 用堆来不断的取最大值，priority_queue <int>
// 然后简单的simulate一下，数据结构万岁
