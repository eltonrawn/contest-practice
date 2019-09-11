#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 1000000007
#define INF 1000000000
#define MX 300010

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
//    cout
//    for(int i = 1;; i++)   {
//        if(i * i > 1000)    {
//            break;
//        }
//        cout << i << " : " << i * i << "\n";
//    }
    int lim = 1000;

    for(LL a = 1; a <= lim; a++)    {
        for(LL b = a + 1; b <= lim; b++)    {
            LL c = lim - a - b;
            if(c <= b)    {
                break;
            }
            if(a * a + b * b == c * c)    {
                cout << a << " " << b << " " << c << "\n";
                cout << 1LL * a * b * c << "\n";
            }
        }
    }
    return 0;
}
/**
31875000
*/
