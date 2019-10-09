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
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef pair<int, int> PII;

int n, m;
string str;
int cnt[22][22];

int dp[1 << 20];

vector<int> used;
vector<int> unused;

int func(int mask)  {
    used.clear();
    unused.clear();
    FOR(i, 0, m - 1)   {
        if(mask & (1 << i))    {
            used.PB(i);
        }
        else    {
            unused.PB(i);
        }
    }
//    cout << mask << " : " << used.size() << "\n";
    if(used.size() == m)    {
        return 0;
    }
    if(dp[mask] != -1)    {
        return dp[mask];
    }
    int ans = 1000000000;

    int tmp = 0;
    FOR(i, 0, (int)used.size() - 1)   {
        FOR(j, 0, (int)unused.size() - 1)   {
            tmp += cnt[ used[i] ][ unused[j] ];
        }
    }
    FOR(i, 0, m - 1)   {
        if(mask & (1 << i))    {
        }
        else    {
            ans = min(ans, tmp + func(mask | (1 << i)));
        }
    }
    return dp[mask] = ans;
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    FastIO;
    cin >> n >> m;
    cin >> str;
    FOR(i, 1, (int)str.size() - 1)   {
        cnt[ str[i] - 'a' ][ str[i - 1] - 'a' ]++;
        cnt[ str[i - 1] - 'a' ][ str[i] - 'a' ]++;
    }
    MEM(dp, -1);
    cout << func(0);
    return 0;
}

