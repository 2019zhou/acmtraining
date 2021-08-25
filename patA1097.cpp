// 这次看测试数据看出了错误，qaq, debug --->>>>
#include <iostream>
#include <set>
using namespace std;

const int N = 1000010;
int a[N];
int ne[N];

int main(){
    int astart;
    cin >> astart;
    int n;
    cin >> n;
    int curadd;
    int tmp;
    int next;
    while(n--){
        cin >> curadd >> tmp >> next;
        a[curadd] = tmp;
        ne[curadd] = next;
    }
    int bstart = -1;
    int bend = -1;
    set<int> s;
    int p = astart;
    int pre = -1;
    while(p != -1){
        int np = ne[p];
        if(s.count(abs(a[p]))){
            if(bstart == -1){
                bstart = p;
                bend = p;
                ne[pre] = ne[p];
                ne[p] = -1;
            }else{
                ne[bend] = p;
                bend = p;
                ne[pre] = ne[p];
                ne[p] = -1;
            }
        }else{
            s.insert(abs(a[p]));
            pre = p;
        }
        p = np;
    }
    
    
    p = astart;
    while(p!= -1){
        if(ne[p] == -1)
            printf("%.5d %d \-1\n", p, a[p]);
        else
            printf("%.5d %d %.5d\n", p, a[p], ne[p]);
        p = ne[p];
    }
    
    p = bstart;
    while(p!= -1){
        if(ne[p] == -1)
            printf("%.5d %d \-1\n", p, a[p]);
        else
            printf("%.5d %d %.5d\n", p, a[p], ne[p]);
        p = ne[p];
    }
    
    
    return 0;
}
