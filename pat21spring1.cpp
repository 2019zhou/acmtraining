#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for (int i = 2; i <= n; i ++ ){
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
	int n, maxp;
	cin >> n >> maxp;
	get_primes(maxp);
	vector<int> ans;
	int ap;
	int tmp;
	int curap = 0;
	if(n == 1){
		ans.push_back(primes[cnt - 1]);
	}else{
		for(int i = 0;i < cnt;i++){
			for(int j = i + 1;j < cnt;j++){
				ap = primes[j] - primes[i];
				int sign = 1;
				for(int k = 1;k <= n - 2;k++){
					tmp = primes[j] + ap * k;
					if(tmp > maxp || st[tmp] == true){
						sign = 0;
						break;
					}
				}
				if(sign == 1 && ap >= curap){
					ans.clear();
					ans.push_back(primes[i]);
					ans.push_back(primes[j]);
					curap = ap;
				}
			}
		}
	}
	// cout << ans.size();

	if(ans.size() == 1)
		cout << ans[0];
	else if(ans.size() == 0)
		cout << primes[cnt - 1];
	else{
		ap = ans[1] - ans[0];
		cout << ans[0];
		for(int i = 0;i < n - 1;i++){
			printf(" %d", ans[1] + ap * i);
		}
	}

	return 0;
}
