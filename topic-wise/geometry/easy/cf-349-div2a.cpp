
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

double circle_area(double r)   {
    return pi * r * r;
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int d, h, v, e;
    cin >> d >> h >> v >> e;
    ///increases by e cm
    /**
    (pi * r * r * h) ml for h cm
    v ml for (h * v) / (pi * r * r * h) cm
    so, decreases by (h * v) / (pi * r * r * h) cm
    */
    double r = d / 2.0;
    double inc = e;
    double dec = (h * v) / (pi * r * r * h);
    if(inc >= dec)    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << fixed << setprecision(9) << h / (dec - inc);
    return 0;
}
/**
*/
