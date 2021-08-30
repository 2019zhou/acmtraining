#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string ref;
    getline(cin, ref);
    getline(cin, ref);
    string cur;
    int j, k;
    int start = 0;
    int sign = 0;
    for(int i = 1;i < n;i++){
        getline(cin, cur);
        // cout << ref << endl;
        // cout << cur << endl;
        if(sign == 0){
            j = ref.size() - 1;
            k = cur.size() - 1;
            while(j >= 0 && k >= 0 && ref[j] == cur[k]){
                j--;
                k--;
            }
            // cout << j << " " << k<< endl;
            if(j == ref.size() - 1){
                sign = 1;
                continue;
            }
            start = max(start, j + 1);
        }
        
    }
    
    if(sign){
        cout << "nai" << endl;
    }else{
        cout << ref.substr(start, ref.size() - start + 1);
    }
    
    
    
    return 0;
}
