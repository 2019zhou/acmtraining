#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int n1 = (n + 2)/3;
    int n2 = n + 2 - 2 * n1;
    int i = 0;
    int j = n - 1;
    for(int m = 0;m < n1 - 1;m++){
        printf("%c", s[i]);
        for(int n = 0;n < n2 - 2;n++){
            printf(" ");
        }
        printf("%c\n", s[j]);
        i++;
        j--;
    }
    
    for(int k = i;k <=j;k++){
        printf("%c", s[k]);
    }
    
    
    return 0;
}
