#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    string tmp;
    unordered_map<string,int> mp;
    string maxc;
    int sign = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> tmp;
            if(mp.count(tmp)){
                mp[tmp] ++;
                if(mp[tmp] > m * n /2){
                    sign = 1;
                    maxc = tmp;
                    break;
                }
            }else{
                mp[tmp] = 1;
            }
        }
        if(sign == 1){
            break;
        }
    }
    
    cout << maxc << endl;
    
    return 0;
}
