#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string a;
    string b;
    cin >> a >> b;
    unordered_map<int, int> mp;
    for(auto item:a){
        if(mp.count(item))
            mp[item]++;
        else
            mp[item] = 1;
    }
    int sign = 1;
    int cnt = 0;
    for(auto tt:b){
        if(!mp.count(tt)){
            cnt++;
            sign = 0;
        }else{
            mp[tt]--;
            if(mp[tt] < 0){
                cnt++;
                sign = 0;
            }
        }
    }
    if(sign == 1){
        int cc = a.size() - b.size();
        cout << "Yes " << cc << endl;
    }else{
        cout << "No ";
        cout << cnt << endl;
    }
}
