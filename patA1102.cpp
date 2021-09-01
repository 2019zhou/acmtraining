// 找根节点的方法
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 11;
int p[N];
int l[N], r[N];
bool hasf[N];


void inorder(int x){
    if(x == -1)
        return;
    if(r[x] != -1) inorder(r[x]);
    cout << x << " ";
    if(l[x]!= -1) inorder(l[x]);
}

void levelorder(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        cout << t << " ";
        q.pop();
        if(r[t] != -1)
            q.push(r[t]);
        if(l[t]!= -1)
            q.push(l[t]);
    }
}


int main(){
    int n;
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);

    char left, right;
    for(int i = 0;i < n;i++){
        cin >> left >> right;
        l[i] = (left == '-') ? -1:left - '0';
        if(l[i] >= 0)
            hasf[l[i]] = true;
        r[i] = (right == '-') ? -1:right - '0';
        if(r[i] >= 0)
            hasf[r[i]] = true;
       // cout << l[i] << r[i] << endl;
    }
    int root =  0;
    while(hasf[root] == true) root++;
    //cout << root << endl;
    
    levelorder(root);
    cout << endl;
    inorder(root);
    
    cout << endl;
    
}
