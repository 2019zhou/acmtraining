// pat 输入玄妙。。。。。
#include <iostream>
using namespace std;

const int N = 1000010;
int ne[N];

int main(){
    int n;
    int astart;
    int bstart;
    char tmp;
    int cadd;
    int nadd;
    cin >> astart >>bstart >> n;
    while(n--){
        cin >> cadd >> tmp >> nadd;
        ne[cadd] = nadd;
    }
    if(astart == -1 or bstart == -1)
        cout << "-1" << endl;
    else{
        int pa = astart;
        int pb = bstart;
        while(pa != pb){
            pa = (pa == -1)? bstart: ne[pa];
            pb = (pb == -1)? astart: ne[pb];
        }
        
        if(pa == -1)
            cout << "-1";
        else{
            printf("%.5d", pa);
        }
    }
    
    
    return 0;
}
