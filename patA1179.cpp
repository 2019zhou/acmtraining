#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long double res = 0;

    for (int i = 1; i <= n; i ++)
    {
        long double x;
        cin >> x;

        //先写x 因为 i * (n - i + 1)在10^5会溢出
        res += x * i * (n - i + 1);
    }

    printf("%.2LF", res);

    return 0;
}
