// 开始没写对因为dfs 之后还需要pop_back()
// 把之前push_back()的东西重新pop_back出来

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int ctree[1005];
int num;
int sign = 1;  
int boolMax = 0;

void dfs(int index, vector<int>& path) {
    int left = 2 * (index+1);
    int right = 2 * (index + 1) - 1;
    if (left >= num && right >= num) {
        for (int i = 0; i < path.size(); i++) {
            if(i != path.size() - 1)
                printf("%d ", ctree[path[i]]);
            else 
                printf("%d", ctree[path[i]]);
        }
        printf("\n");
        return;
    }
    // to judge whether it is a min heap
    if (boolMax == 0 && sign == 1) {
        if (left < num && ctree[index] < ctree[left]) {
            if (right < num && ctree[index] >= ctree[right]) {
                sign = 0;
            }
        }
        else if (left < num && ctree[index] >= ctree[left]) {
            sign = 0;
        }
    }

    // to judge whether it is a max heap
    if (boolMax == 1 && sign == 1) {
        if (left < num && ctree[index] > ctree[left]) {
            if (right < num && ctree[index] <= ctree[right]) {
                sign = 0;
            }
        }
        else if (left < num && ctree[index] <= ctree[left]) {
            sign = 0;
        }
    }

    if (left < num) {
        //printf("%d", ctree[left]);
        path.push_back(left);
        dfs(left, path);
        path.pop_back();
    }
    

    if (right < num) {
        //printf("%d", ctree[left]);
        path.push_back(right);
        dfs(right, path);
        path.pop_back();
    }

}

int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> ctree[i];
    }
    if (num >= 2) {
        if (ctree[0] < ctree[1]) {
            boolMax = 0;
        }
        else if (ctree[0] > ctree[1]) {
            boolMax = 1;
        }
        else {
            boolMax = 2;
            sign = 0;
        }
    }

    vector<int> path;
    path.push_back(0);
    dfs(0, path);

    if (sign == 0) {
        printf("Not Heap\n");
    }
    if (sign == 1 && boolMax == 0) {
        printf("Min Heap\n");
    }
    if (sign == 1 && boolMax == 1) {
        printf("Max Heap\n");
    }

    return 0;
}