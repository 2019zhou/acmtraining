// 很自然的需要考虑到 A + B = 0 的情况，这个时候不要放入map中
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;


double A[1005] = {0};
double B[1005] = {0};

int main(){
    int k;
    int exp;
    double coeff;
    for(int i = 0;i < 2;i++){
        scanf("%d", &k);
        for(int j = 0;j < k;j++){
            scanf("%d%lf", &exp, &coeff);
            if(i == 0) A[exp] = coeff;
            else B[exp] = coeff;
        }
    }

    map<int, double, greater<int>> mp;
    for(int i = 0;i < 1005;i++){
        if(A[i] != 0 || B[i]!= 0){
            if(A[i] != 0 && B[i]!= 0 ){
                if(A[i] + B[i] == 0) continue;
                mp[i] = A[i] + B[i];
            }else if(A[i]!= 0 && B[i] == 0){
                mp[i] = A[i];
            }else if(A[i] == 0 && B[i] != 0)
                mp[i] = B[i]; 
        }
    }
    printf("%d", mp.size());
    for(auto iter = mp.begin();iter!=mp.end();iter++){
        printf(" %d %.1f", iter->first, iter->second);
    }

    return 0;
}