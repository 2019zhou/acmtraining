// 这个并查集确实写的不容易哎

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int vpSize = 1001;
int father[1005];
vector<int> vp[vpSize];

int findfather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findfather(a);
    int faB = findfather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

int main() {
    freopen("input.txt", "r",stdin);
    int n;
    cin >> n;
    int tempNum;
    int temp;

    // father 初始化
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d:", &tempNum);
        for (int j = 0; j < tempNum; j++) {
            cin >> temp;
            vp[temp].push_back(i);
        }
    }

    for (int i = 0; i < vpSize; i++) {
        if (vp[i].size() == 0 || vp[i].size() == 1)
            continue;
        else {
            for (int j = 1; j < vp[i].size(); j++) {
                //cout << vp[i][0] << "  " << vp[i][j] << endl;
                Union(vp[i][0], vp[i][j]);
                //cout << father[vp[i][0]] <<  "  " << father[vp[i][j]] << endl;
            }
        }
    }

    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        findfather(i);
        ans[father[i] + 1] ++;
    }
    printf("%d\n", ans.size());
    int tempcnt = 0;
    vector<int> ansvp;
    for(auto iter = ans.begin();iter != ans.end();iter++){
        ansvp.push_back(iter->second);
    }
    sort(ansvp.begin(), ansvp.end());
    for (int i = ansvp.size() - 1; i >= 0; i--) {
        if (i == ansvp.size() - 1)
            printf("%d", ansvp[i]);
        else
            printf(" %d", ansvp[i]);
    }

    return 0;
}