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

int n;
LL val[100010];
vector<int> adjl[100010];

set<LL> ms;
map<LL, int> mp;
LL ans = 0;

void func(int u, int par)  {
    set<LL> tmp_ms = ms;
    map<LL, int> tmp_mp = mp;

//    for(auto it = ms.begin(); it != ms.end(); it++)   {
//        cout << u << " : " << (*it) << " " << mp[(*it)] << "\n";
//    }

    ans += val[u] % MOD;
    ans %= MOD;

    FOR(i, 0, (int)adjl[u].size() - 1)   {
        int v = adjl[u][i];
        if(v == par)    {
            continue;
        }


        ms.insert(val[u]);mp[ val[u] ]++;
        set<LL> n_ms;
        map<LL, int> n_mp;
        for(auto it = ms.begin(); it != ms.end(); it++)   {
            LL pgcd = (*it);
            LL cnt = mp[pgcd];
            LL ngcd = __gcd(pgcd, val[v]);
            ans += (ngcd * cnt) % MOD;
            ans %= MOD;
            n_ms.insert(ngcd);
            n_mp[ ngcd ] += mp[pgcd];
        }
        ms = n_ms;mp = n_mp;
        n_ms.clear();n_mp.clear();

        func(v, u);

        ms = tmp_ms;
        mp = tmp_mp;
    }
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n)   {
        cin >> val[i];
    }
    FOR(i, 1, n - 1)   {
        int u, v;
        cin >> u >> v;
        adjl[u].PB(v);
        adjl[v].PB(u);
    }

    func(1, 0);
    cout << ans;
    return 0;
}
