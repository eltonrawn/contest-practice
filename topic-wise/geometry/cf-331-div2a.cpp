
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

class Point {
public:
    double x, y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
};

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n;
    cin >> n;
    vector<Point> vv;

    vector<int> xs, ys;

    FOR(i, 0, n - 1)   {
        int x, y;
        cin >> x >> y;
        vv.PB(Point(x, y));
        xs.PB(x);
        ys.PB(y);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

//    cout << xs[0] << " " << xs[1] << "\n";
//    cout << ys[0] << " " << ys[1] << "\n";

    if(xs.size() == 2 && ys.size() == 2)    {
        cout << (xs[1] - xs[0]) * (ys[1] - ys[0]);
    }
    else    {
        cout << -1;
    }
    return 0;
}
/**
*/
