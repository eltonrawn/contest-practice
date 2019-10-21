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

int n, m;
int ara[100010];

bool func1(int pos)  {
    int cur = pos;
    FOR(i, 0, m - 1)   {
        if(cur == (ara[i] - 1))    {
            continue;
        }
        cur++;
    }
    cur++;
    if(cur >= n)    {
        return 1;
    }
    return 0;
}

bool func2(int pos)  {
    int cur = pos;
    FOR(i, 0, m - 1)   {
        if(cur == (ara[i] + 1))    {
            continue;
        }
        cur--;
    }
    cur--;
    if(cur <= 1)    {
        return 1;
    }
    return 0;
}

int main()  {
    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n >> m;
    FOR(i, 0, m - 1)   {
        cin >> ara[i];
    }

//    cout << func2(4) << "\n";

    int lo, hi;
    lo = 1;hi = n;
    while(lo < hi) {
        int mid = lo + ((hi - lo) / 2);
        if(func1(mid))    {
            hi = mid;
        }
        else    {
            lo = mid + 1;
        }
    }
    LL ans = n * (LL)(n);
    ans -= (LL)(lo - 1LL);
//    cout << lo << "\n";

    lo = 1;hi = n;
    while(lo < hi) {
        int mid = lo + ((hi - lo + 1) / 2);
        if(func2(mid))    {
            lo = mid;
        }
        else    {
            hi = mid - 1;
        }
    }
//    cout << lo << "\n";
    ans -= (LL)(n - lo);
    cout << ans;

    return 0;
}

