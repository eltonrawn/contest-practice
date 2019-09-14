
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
#define pi 2.0*acos(0.0)

typedef pair<int, int> PII;

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n;
    cin >> n;
    vector<LL> ara;
    LL sum = 0;
    LL mx = 0;
    FOR(i, 0, n - 1)   {
        LL tmp;cin >> tmp;
        ara.PB(tmp);
        sum += tmp;
        mx = max(mx, tmp);
    }
    sum -= mx;
    if(sum > mx)    {
        cout << 0;
    }
    else    {
        cout << mx - sum + 1;
    }
    return 0;
}
/**
*/

