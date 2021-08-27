#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    vector<int> vp;
};


node nodes[105];

int main(){
    int n, m;
    cin >> n >> m;
    int id1, id2;
    int k;
    for(int i = 0;i < m;i++){
        cin >> id1;
        cin >> k;
        while(k--){
            cin >> id2;
            nodes[id1].vp.push_back(id2);
        }
    }
    
    queue<int> q;
    int root = 1;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int sz = q.size();
        cnt = 0;
        for(int i = 0;i < sz;i++){
            int p = q.front();
            q.pop();
            if(nodes[p].vp.size() == 0){
                cnt++;
            }
            for(int j = 0;j < nodes[p].vp.size();j++){
                q.push(nodes[p].vp[j]);
            }
        }
        cout << cnt << " ";
    }
    
    return 0;
}
