#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int n = s.size();
    vector<vector<bool>> vp(n, vector<bool>(n,false));
    for(int i = 0;i < n;i++){
        vp[i][i] = true;
    }
    int maxl = 1;
    for(int L = 2;L <= n;L++){
        for(int i = 0;i < n;i++){
            int j = i + L -1;
            if(j >= n)
                break;
            if(s[i] == s[j]){
                if(j - i < 3){
                    vp[i][j] = true;
                }else{
                    vp[i][j] = vp[i + 1][j - 1];
                }
            }else{
                vp[i][i + L -1] = false;
            }
            if(vp[i][j])
                maxl = j - i + 1;
        }
    }
    
    cout << maxl << endl;
    return 0;
    
    
}
