#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int tmp;
    int sum = 0;
    unordered_map<int, int> mp;
    while(n--){
        cin >> tmp;
        sum = 0;
        while(tmp){
            sum += tmp%10;
            tmp = tmp/10;
        }
        if(mp.count(sum)){
            mp[sum]++;
        }else{
            mp[sum]=1;
        }
    }
    
    cout << mp.size() << endl;
    
    vector<int> vp;
    for(auto t:mp){
        //cout << t.first << " ";
        vp.push_back(t.first);
    }
    sort(vp.begin(), vp.end());
    for(auto item:vp){
        cout << item << " ";
    }
    
    return -0;
}
