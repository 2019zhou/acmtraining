#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 105;

int a[N], l[N], r[N];
int d[N];
int idx = 0;

void inorder(int x){
    if(x == -1)
        return;
    if(l[x] != -1)
        inorder(l[x]);
    a[x] = d[idx++];
    if(r[x] != -1)
        inorder(r[x]);
}

int main(){
    int n;
    cin >> n;
    int left, right;
    for(int i = 0;i < n;i++){
        cin >> l[i] >> r[i];
    }
    for(int i = 0;i < n;i++){
        cin >> d[i];
    }
    sort(d, d + n);
    inorder(0);
    
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int t = q.front();
        cout << a[t] << " ";
        q.pop();
        if(l[t] != -1)
            q.push(l[t]);
        if(r[t]!= -1)
            q.push(r[t]);
    }
    
    return 0;
}
