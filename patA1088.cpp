#include <iostream>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b){
    return b?gcd(b, a%b):a;
}

void prin(LL a, LL b){
    if(a == 0){
        printf("0");
        return;
    }
    bool ism = 1;

    if((a < 0 or b < 0) && !(a < 0 && b < 0)){
        ism = 0;
        printf("(-");
        a = abs(a);
        b = abs(b);
    }
    // cout << endl;
    // cout << a << " " << b << endl;
    
    a = abs(a);
    b = abs(b);
    LL num = a/b;
    if(num != 0){
        printf("%lld", num);
    }
    a = a - num * b;
    if(a!= 0){
        LL t = gcd(a, b);
        a = a/t;
        b = b/t;
        if(num!= 0)
            printf(" ");
        printf("%lld/%lld", a, b);
    }
    if(!ism){
        printf(")");
    }
}



void add(LL a1, LL b1, LL a2, LL b2){
    prin(a1, b1);
    cout << " + ";
    prin(a2, b2);
    cout << " = ";
    LL t = b2 / gcd(b1, b2) * b1;
    a1 = t/b1 * a1 + t/b2 * a2;
    b1 = t;
    prin(a1, b1);
    cout << endl;
}


void sub(LL a1, LL b1, LL a2, LL b2){
    prin(a1, b1);
    cout << " - ";
    prin(a2, b2);
    cout << " = ";
    LL t = b2 / gcd(b1, b2) * b1;
    a1 = t/b1 * a1 - t/b2 * a2;
    b1 = t;
    prin(a1, b1);
    cout << endl;
}


void pl(LL a1, LL b1, LL a2, LL b2){
    prin(a1, b1);
    cout << " * ";
    prin(a2, b2);
    cout << " = ";
    a1 = a1 * a2;
    b1 = b1 * b2;
    prin(a1, b1);
    cout << endl;
}

void di(LL a1, LL b1, LL a2, LL b2){
    prin(a1, b1);
    cout << " / ";
    prin(a2, b2);
    cout << " = ";
    if(a1==0){
        printf("0\n");
        return;
    }else if(a2 == 0){
        printf("Inf\n");
        return;
    }
    a1 = a1 * b2;
    b1 = b1 * a2;
    prin(a1, b1);
    cout << endl;
}

int main(){
    LL a1, a2, b1, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    LL num1, num2;
    LL t;
    if(a1!= 0){
        t = gcd(a1, b1);
        a1 = a1/t;
        b1 = b1/t;
    }
    if(a2!= 0){
        t = gcd(a2, b2);
        a2 = a2/t;
        b2 = b2/t;
    }
    // 和 差 积 商
    
    add(a1, b1, a2, b2);
    sub(a1, b1, a2, b2);
    pl(a1, b1, a2, b2);
    di(a1, b1, a2, b2);
    
    return 0;
}
