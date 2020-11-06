// 说反话
// 感觉这类题目还不是很熟悉

// #include <cstdio>

int main(){
	int num = 0; //单词的个数
	char ans[90][90];
	while(scanf("%s", ans[num]) != EOF){
		num++;
	}
	for(int i = num - 1; i>= 0;i--){
		printf("%s", ans[i]);
		if(i > 0) printf(" ");
	}
	return 0;
}

// possible solution 
#include <cstdio>
#include <cstring>

int main(){
	char str[90];
	gets(str);
	int len = strlen(str), r = 0, c = 0; 		// r =  row, c = col
	char ans[90][90];
	for(int i = 0;i < len;i++){
		if(str[i] != ' '){
			ans[r][c++] = str[i];
		}else{
			ans[r][c] = '\0';
			r++;
			c = 0;
		}
	}
	for(int i = r; i>= 0;i--){
		printf("%s", ans[i]);
		if(i > 0) printf(" ");
	}
	return 0;
}