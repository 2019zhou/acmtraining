// 新发现pat系统也可以shift全选来做题

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void printNum(char c){
    switch(c){
            case '0':printf("zero");break;
            case '1':printf("one");break;
            case '2':printf("two");break;
            case '3':printf("three");break;
            case '4':printf("four");break;
            case '5':printf("five");break;
            case '6':printf("six");break;
            case '7':printf("seven");break;
            case '8':printf("eight");break;
            case '9':printf("nine");break;
    }
}

int main(){
    string num;
    cin >> num;
    int sum = 0;
    for(auto data:num){
        sum += data-'0';
    }
    string ans = to_string(sum);
    printNum(ans[0]);
    for(int i = 1;i < ans.size();i++){
        printf(" ");
        printNum(ans[i]);
    }
    return 0;
}