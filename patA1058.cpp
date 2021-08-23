#include <iostream>
using namespace std;

int main(){
    //Galleon.Sickle.Knut 
    int g1, s1, k1;
    int g2, s2, k2;
    scanf("%d.%d.%d", &g1, &s1, &k1);
    scanf("%d.%d.%d", &g2, &s2, &k2);
    g1 = g1 + g2;
    s1 = s1 + s2;
    k1 = k1 + k2;
    s1 += k1 /29;
    k1 = k1%29;
    g1 += s1/17;
    s1 = s1%17;
    printf("%d.%d.%d", g1, s1, k1);
    return 0;
}
