// pat的输入输出跪了
// c_str() 背一下
// st[i] = {attr1, attr2, attr3};

#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    int id;
    string name;
    int g;
};


const int N = 100010;

stu st[N];

bool cmp1(stu a, stu b){
    return a.id < b.id;
}

bool cmp2(stu a, stu b){
    if(a.name == b.name){
        return a.id < b.id;
    }else{
        return a.name <= b.name;
    }
}

bool cmp3(stu a, stu b){
    if(a.g == b.g){
        return a.id < b.id;
    }else{
        return a.g <= b.g;
    }
}

int main(){
    int n, c;
    cin >> n >> c;
    int idd, grade;
    char name[10];
    for(int i = 0;i < n;i++){
        scanf("%d%s%d", &idd, name, &grade);
        st[i] = {idd, name, grade};
    //     cin >> st[i].id >> st[i].name >> st[i].g;
    //   // scanf("%d%s%d", &st[i].id, st[i].name, &st[i].g);
    }
    if(c == 1){
        sort(st, st + n, cmp1);
    }else if(c == 2){
        sort(st, st + n, cmp2);
    }else if(c == 3){
        sort(st, st + n, cmp3);
    }
    
    for(int i = 0;i < n;i++){
        printf("%.6d %s %d\n", st[i].id, st[i].name.c_str(), st[i].g);
        // cout << st[i].name << " "<< st[i].g << endl;
        // printf()
    }
    
    return 0;
}
