// 1-300 枚举x
// y=x^2-->转换为B进制
// 核心转化进制：
// 短除法
// 原理：
// (n)[10]=(akak-1.....a2a1a0)[k]
// n=ak*b^k+ak-1*b^(k-1)+.....+a0*b^0;
// n%b=a0
// [n/b](下取整)%b=a1
// ...
// ...
// ...以此类推
// 如何判断是否是回文数
// 双指针
// sum:
// 1.10进制转化为其他进制：短除法
// 2.其他进制转化为10进制：秦九韶
// an*x^n+an-1*x^n-1+....a0*x^0;
// ((anx+an-1)*x+an-1)x+.....;
// 3.其他进制转化为其他进制（ACwing 124：数的进制转化）
// a.十进制过渡  b.直接短除法
// C++ 代码
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char get(int x)//转化为字符（也包括10->A） 
{
    if(x<=9) return x+'0';
    return  (x-10+'A');
}
string base(int n,int b)//短除法 
{
    string num;
    while(n) num+=get(n%b),n/=b;
    reverse(num.begin(),num.end());
    return num;
}
bool check(string num)
{
    for(int i=0,j=num.size()-1;i<j;i++,j--)
    {
        if(num[i]!=num[j])   return false;
    }
    return true;
}
int main()
{
    int b;
    cin>>b;
    for(int i=1;i<=300;i++)
    {
        string num = base(i*i,b);
        if(check(num))//判断是否是回文数 
        {
            cout<<base(i,b)<<" "<<num<<endl;
        }
    }
    return 0;
}

10进制转化为其它进制

int uget(char c)
{
    if(c<=9) return c-'0';
    return  c-'A'+10;
}
int base10(string num,int b)
{
    int res = 0;
    for(auto c:num) 
        res=res*b+uget(c);
    return res;
}
