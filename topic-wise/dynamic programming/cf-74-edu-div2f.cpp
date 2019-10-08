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
vector<int> adjl[300010];
int pntD[300010], pntR[300010];
int pp[300010];

void make_sibling(int u, int par)  {
    pp[u] = par;
    vector<int> vs;
    FOR(i, 0, (int)adjl[u].size() - 1)   {
        int v = adjl[u][i];
        if(v == par)    {
            continue;
        }
        make_sibling(v, u);
        vs.PB(v);
    }
    if(vs.size())    {
        pntD[u] = vs[0];
    }
    FOR(i, 1, (int)vs.size() - 1)   {
        pntR[ vs[i - 1] ] = vs[i];
    }
}

int col_ref = 0;
int col[300010][2][2][2][2];
int dp[300010][2][2][2][2];

/**
l covers left part
r covers right part
m covers middle part
all covers all parts and beyond
*/
int func(int u, int l, int r, int all, int first)  {
    if(u == 0)    {
        return 0;
    }
    if(col[u][l][r][all][first] == col_ref)    {
        return dp[u][l][r][all][first];
    }
    int ans = 0;
    int tmp;
    if(first)    {
        ///ei node niye
        ans = 1 + func(pntD[u], 1, 1, 1, 0);

        ///ei node na niye
        FOR(i, 0, (int)adjl[u].size() - 1)   {
            int v = adjl[u][i];
            if(v == pp[u])    {
                continue;
            }
            tmp = func(v, 1, 1, 1, 1);
            ans = max(ans, tmp);
        }
    }
    else    {

        if(l)    {
            ///left tuku niye
            tmp = 1 + func(pntR[u], 0, r, 0, 0) + func(pntD[u], l, 0, 0, 0);
            ans = max(ans, tmp);
        }

            ///middle tuku niye
            tmp = 1 + func(pntR[u], l, r, 0, 0);
            ans = max(ans, tmp);

        if(r)    {
            ///right tuku niye
            tmp = 1 + func(pntR[u], l, 0, 0, 0) + func(pntD[u], 0, r, 0, 0);
            ans = max(ans, tmp);
        }
        if(all)    {
            ///taking all and beyond
            tmp = 1 + func(pntD[u], l, r, 0, 0);
            ans = max(ans, tmp);
        }

        ///kichu na niye
        tmp = func(pntR[u], l, r, all, 0);
        ans = max(ans, tmp);
    }

    col[u][l][r][all][first] = col_ref;
    return dp[u][l][r][all][first] = ans;
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int tc;
//    cin >> tc;
    scanf("%d", &tc);
    FOR(tt, 1, tc)   {
//        cin >> n;
        scanf("%d", &n);
        FOR(i, 1, n)   {
            adjl[i].clear();
        }
        FOR(i, 1, n - 1)   {
            int u, v;
//            cin >> u >> v;
            scanf("%d", &u);
            scanf("%d", &v);
            adjl[u].PB(v);
            adjl[v].PB(u);
        }
//        MEM(pntD, 0);
//        MEM(pntR, 0);
        FOR(i, 1, n)   {
            pntD[i] = 0;
            pntR[i] = 0;
        }
        make_sibling(1, 0);
//        FOR(i, 1, n)   {
//            cout << i << " : " << pntD[i] << " " << pntR[i] << "\n";
//        }
//        cout << func(1, 1, 1, 1, 1, 1) << "\n";
        col_ref++;
        printf("%d\n", func(1, 1, 1, 1, 1));
    }
    return 0;
}
