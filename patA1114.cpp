// 很多基础堆起来就难了
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10010;
int p[N], c[N], hc[N], ha[N];
int st[N];


struct edge{
    int a, b;
}e[N];

struct Family{
    int id, c, hc, ha;
    bool operator< (const Family &t) const{
        if(ha * t.c != t.ha * c)  return ha*t.c > t.ha * c;
        return id < t.id;
    }
};


int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main(){
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i ++ ){
        int id, father, mother, k;
        scanf("%d%d%d%d", &id, &father, &mother, &k);
        st[id] = true;
        if(father != -1){
            e[m++] = {id, father};
        }
        if(mother != -1){
            e[m++] = {id, mother};
        }
        while(k--){
            int son;
            cin >> son;
            e[m++] = {id, son};
        }
        cin >> hc[id] >> ha[id];
    }
    
    for(int i = 0;i < N;i++)
        p[i] = i, c[i] = 1;
    for(int i = 0;i < m;i++){
        int a = e[i].a;
        int b = e[i].b;
        st[a] = st[b] = true;
        int pa = find(a), pb = find(b);
        if(pa!= pb){
            if(pb > pa)
                swap(pa, pb);
            c[pb] += c[pa];
            hc[pb] += hc[pa];
            ha[pb] += ha[pa];
            p[pa] = pb;
        }
    }
    
    vector<Family> family;
    for(int i = 0;i < N;i++){
        if(st[i] && p[i] == i){
            family.push_back({i, c[i], hc[i], ha[i]});
        }
    }
    sort(family.begin(), family.end());
    
    cout << family.size() << endl;
    for(auto f:family){
        printf("%04d %d %.3lf %.3lf\n", f.id, f.c, (double)f.hc / f.c, (double)f.ha / f.c);
        
    }
    
    return 0;
}
