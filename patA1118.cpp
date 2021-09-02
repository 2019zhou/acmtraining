#include <iostream>
using namespace std;

const int N = 10010;
int p[N];

int find(int x){
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main(){
    int n;
    cin >> n;
    int k;
    for(int i = 1;i < N;i++) p[i] = i;
    int cur;
    int maxcur = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cin >> k;
        cin >> cur;
        maxcur = max(cur, maxcur);
        int pa = find(cur);
        for(int j = 0;j < k - 1;j++){
            cin >> cur;
            maxcur = max(cur, maxcur);
            int pb = find(cur);
            if(pa != pb){
                p[pb] = pa;
                cnt++;
            }
        }
    }
    cout << maxcur - cnt << " " << maxcur << endl;
    int q;
    cin >> q;
    int a, b;
    while(q--){
        cin >> a >> b;
        int pa = find(a);
        int pb = find(b);
        //cout << pa << " " << pb <<endl;
        if(pa == pb){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
    return 0;
}
