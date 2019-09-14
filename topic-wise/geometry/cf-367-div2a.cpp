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

double dis(int x1, int y1, int x2, int y2)   {
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

int a, b;
int n;

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> a >> b;
    cin >> n;
    double ans = 1000000000;
    FOR(i, 0, n - 1)   {
        int x, y, spd;
        cin >> x >> y >> spd;
        ans = min(ans, dis(a, b, x, y) / spd);
    }
    cout << fixed << setprecision(9) << ans;
    return 0;
}
/**
*/
