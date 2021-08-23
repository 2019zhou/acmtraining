#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    string a;
    getline(cin, a);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    unordered_map<string,int> mp;
    string tmp = "";
    string strm;
    int n = 0;
    //cout << a << endl;
    for(int i = 0;i < a.size();i++){
        if(isdigit(a[i]) or isalpha(a[i])){
            tmp += a[i];
            //cout << a[i] << endl;
        }else{
            if(tmp != ""){
               if(mp.count(tmp)){
                    mp[tmp] ++;
                    if(mp[tmp] > n){
                        n = mp[tmp];
                        strm = tmp;
                    }else if(mp[tmp] == n){
                        strm = tmp < strm? tmp:strm;
                    }
                    }
                else{
                    mp[tmp] = 1;
                }
                tmp = "";   
            }
              
        }
        //cout << tmp << endl;
    }
    
    if(tmp!= ""){
        if(mp.count(tmp)){
                mp[tmp] ++;
                if(mp[tmp] > n){
                    n = mp[tmp];
                    strm = tmp;
                }else if(mp[tmp] == n){
                    strm = tmp < strm? tmp:strm;
                }
        }
    }
    
    
    // cout <<mp.size() << endl;
    // for (auto item = mp.begin(); item != mp.end(); item ++ ){
    //     cout << item->first << " " << item->second << endl;
    // }  
    cout << strm << " " << n << endl;
    return 0;
}
