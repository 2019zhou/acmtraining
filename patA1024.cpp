#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
vi add(vi & a, vi & b)
{
    vi ans;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i ++)
    {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        ans.push_back(t % 10);
        t /= 10;
    }
    if (t) ans.push_back(t);
    return ans;
}
bool is_s(vi a, vi b)
{
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i ++)
        if (a[i] != b[i])
            return false;
    return true;
}
bool is_pa(vi a)
{
    vi b = a;
    reverse(a.begin(), a.end());
    return a == b;
}
int main()
{
    vi n;
    int k;
    string in;
    cin >> in >> k;
    for (int i = in.size() - 1; i >= 0; i --) n.push_back(in[i] - '0');
    for (int i = 0; i < k; i ++)
    {
        if (is_pa(n))
        {
            for (int i = 0; i < n.size(); i ++) cout << n[i];
            cout << endl << i;
            return 0;
        }
        vi m = n;
        reverse(m.begin(), m.end());
        n = add(n, m);
    }
    for (int i = n.size() - 1; i >= 0; i --) cout << n[i];
    cout << endl << k;
}
