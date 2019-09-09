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

LL lcm(LL a, LL b)   {
    return a * b / __gcd(a, b);
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    LL ans = 1;
    FOR(i, 2, 20)   {
        ans = lcm(ans, i);
    }
    cout << ans;
    return 0;
}
/**
optimization is described in website pdf
*/
