/*给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到
 一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
 
 例如，我们从6767开始，将得到
 
 7766 - 6677 = 1089
 9810 - 0189 = 9621
 9621 - 1269 = 8352
 8532 - 2358 = 6174
 7641 - 1467 = 6174
 ... ...
 
 现给定任意4位正整数，请编写程序演示到达黑洞的过程。
*/
// 结果是对的，可是测试点显示内存超限

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a,int b)
{
    return a>=b;
}

int vec2int(vector<int> vp){
	int res = 0;
	for(int i = 0;i < vp.size();i++){
		res = res * 10 + vp[i];
	}
	return res;
}

vector<int> int2vec(int num){
	vector<int> res;
	while(num!= 0){
		int temp;
		temp = num%10;
		res.push_back(temp);
		num = num/10;
	}
	return res;
}
int main(){
	int N;
	cin >> N;
	int num[4];
	int i = 0;
	while(N!= 0){
		int temp = N%10;
		N = N/10;
		num[i++] = temp;
	}
	if(vp[0] == vp[1] && vp[1] == vp[2] && vp[2] == vp[3]){
		cout << "N - N = 0000";
		return 0;
	}
	int diff = 0;
	vector<int> temp1;
	vector<int> temp2;
	while(diff != 6174){
		temp1.insert(temp1.end(), vp.begin(), vp.end());
		temp2.insert(temp2.end(), vp.begin(), vp.end());
		sort(temp1.begin(), temp1.end());
		sort(temp2.begin(), temp2.end(), compare);
		int temp1int = vec2int(temp1);
		int temp2int = vec2int(temp2);
		diff = temp2int -temp1int;
		if(diff == 6174)
			printf("%04d - %04d = %04d", temp2int, temp1int, diff);
		else 
			printf("%04d - %04d = %04d\n", temp2int, temp1int, diff);
		vp.clear();
		temp1.clear();
		temp2.clear();
		vp = int2vec(diff);
	}

	return 0;
}

// 下面是学习字符串和数字的转化
// 巧妙使用atoi 和 strstream

// 这里使用了stoi 和to_string

#include<bits/stdc++.h>
#include<algorithm>
#include <iomanip>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    string s;
    cin>>s;
    s.insert(0,4-s.length(),'0');//在没满4位的数字前插入0
    do{
        string a =s,b=s;
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end());
        int result = stoi(a)-stoi(b);
        s=to_string(result);
        s.insert(0,4-s.length(),'0');
        cout<<a<<" - "<<b<<" = "<<s<<endl;
    } while(s!="6174"&&s!="0000");
    return 0;
}