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

typedef pair<int, int> PII;

vector<PII> vv;

double get_dis(int x1, int y1, int x2, int y2)   {
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    FOR(i, 0, n - 1)   {
        int a, b;
        cin >> a >> b;
        vv.PB(MP(a, b));
    }
    double dis = 0;
    FOR(i, 1, n - 1)   {
        dis += get_dis(vv[i - 1].F, vv[i - 1].S, vv[i].F, vv[i].S);
    }
    cout << fixed << setprecision(9) << dis * k / 50.0;
    return 0;
}
/**
*/
