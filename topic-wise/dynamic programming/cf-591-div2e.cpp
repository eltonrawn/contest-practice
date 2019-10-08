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

class Data  {
public:
    LL a, b;
    Data()  {}
    Data(LL aa, LL bb)  {
        a = aa;
        b = bb;
    }
};

class cmp   {
public:
    bool operator()(Data fir, Data sec)   {
        return (fir.a - fir.b) > (sec.a - sec.b);
//        if(fir.a == sec.a)    {
//            return fir.b > sec.b;
//        }
//        return fir.a > sec.a;
    }
};

int n, k;
vector<int> adjl[500010];
vector<LL> cost[500010];
int col[500010][2];
LL dp[500010][2];
int col_ref = 0;

LL func(int u, int chk, int par)  {
//    cout << "u : " << u << " : " << "\n";
    if(col[u][chk] == col_ref)    {
        return dp[u][chk];
    }
    vector<Data> foo;
    FOR(i, 0, (int)adjl[u].size() - 1)   {
//        cout << "i : " << i << " : \n";
        int v = adjl[u][i];
        if(v == par)    {
            continue;
        }
        LL w = cost[u][i];
        Data data;
        ///ei edge niye
        data.a = w + func(v, 1, u);
        ///ei edge na niye
        data.b = func(v, 0, u);
        foo.PB(data);
    }
    sort(foo.begin(), foo.end(), cmp());
    int take = k - chk;

    LL ans = 0;
    FOR(i, 0, (int)foo.size() - 1)   {
        if(foo[i].a > foo[i].b && take)    {
            take--;
            ans += foo[i].a;
        }
        else    {
            ans += foo[i].b;
        }
    }

    col[u][chk] = col_ref;
    return dp[u][chk] = ans;
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);

    int foo = 3;
    for(int i = 0; i < 10; i++)   {
        if(foo--)    {
            cout << i << " " << foo << "\n";
        }
    }

    int tc;
//    cin >> tc;
    scanf("%d", &tc);
//    cout << tc << ": \n";
    FOR(tt, 1, tc)   {
//        cout << tt << ": \n";
//        cin >> n >> k;
        scanf("%d", &n);
        scanf("%d", &k);
        FOR(i, 1, n)   {
            adjl[i].clear();
            cost[i].clear();
        }
        FOR(i, 1, n - 1)   {
            int u, v;
            int w;
//            cin >> u >> v >> w;
            scanf("%d", &u);
            scanf("%d", &v);
            scanf("%d", &w);

            adjl[u].PB(v);
            adjl[v].PB(u);
            cost[u].PB(w);
            cost[v].PB(w);
        }
        col_ref++;
//        cout << func(1, 0, 0) << "\n";
        printf("%lld\n", func(1, 0, 0));
    }
    return 0;
}
