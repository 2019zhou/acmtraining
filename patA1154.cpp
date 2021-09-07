// 卡set, unordered_set

#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
const int N = 10010;

struct edge {
    int a;
    int b;
};

edge edges[N];
int color[N];

int main() {
    //scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> edges[i].a >> edges[i].b;
    //scanf("%d%d", &edges[i].a, &edges[i].b);
    int k;
    //scanf("%d", &k);
    cin >> k;
    for (int i = 0; i < k; i++) {
        unordered_set<int> s;
        for (int j = 0; j < n; j++) {
            cin >> color[j];
            //scanf("%d", color[j]);
            s.insert(color[j]);
        }
        int sign = 0;
        for (int j = 0; j < m; j++) {
            if (color[edges[j].a] == color[edges[j].b]) {
                sign = 1;
                break;
            }
        }

        if (sign == 1) {
            printf("No\n");
        }
        else {
            printf("%d-coloring\n", s.size());
        }
    }
    return 0;
}

