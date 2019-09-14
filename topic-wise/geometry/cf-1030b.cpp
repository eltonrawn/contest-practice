
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

class Point {
public:
    double x, y;
    Point() {}
    Point(double _x,double _y) {
        x = _x;y = _y;
    }
};

class Segment {
public:
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b)
    {
        a = _a;
        b= _b;
    }
};

double cross_product(Point a, Point b, Point c)   {
    return (a.x * (b.y - c.y)) - ((a.y) * (b.x - c.x)) + ((b.x * c.y) - (c.x * b.y));
}

int orientation(Segment seg, Point c) {
    Point a = seg.a;
    Point b = seg.b;
    double val = cross_product(a, b, c);
    int ret = 0;
    if(val > 0.0)ret = 1;
    else if(val < 0.0)ret = -1;
    return ret;
}

bool on_segment(Segment seg, Point pnt) {///works only if collinear
    if(orientation(seg, pnt) != 0)  {///means not collinear
        return false;
    }
    double mnx = min(seg.a.x, seg.b.x);
    double mxx = max(seg.a.x, seg.b.x);
    double mny = min(seg.a.y, seg.b.y);
    double mxy = max(seg.a.y, seg.b.y);
    if(((mnx <= pnt.x) && (pnt.x <= mxx)) && ((mny <= pnt.y) && (pnt.y <= mxy))){
        return true;
    }
    return false;
}

bool seg_seg_intr(Segment seg1, Segment seg2) {
    if(on_segment(seg1, seg2.a) || on_segment(seg1, seg2.b) || on_segment(seg2, seg1.a) || on_segment(seg2, seg1.b))return true;
    int o1 = orientation(seg1, seg2.a);
    int o2 = orientation(seg1, seg2.b);
    int o3 = orientation(seg2, seg1.a);
    int o4 = orientation(seg2, seg1.b);
    if (o1 != o2 && o3 != o4)return true;
    return false;
}

bool point_inside_polygon(vector<Point> poly, Point pnt1)  {
    Point pnt2 = Point(pnt1.x + 30000, pnt1.y + 30000);
    int cnt = 0;///intersection count

    FOR(i, 1, (int)poly.size() - 1)   {
        if(on_segment(Segment(poly[i], poly[i - 1]), pnt1))    {
            return true;
        }
        cnt += (int)seg_seg_intr(Segment(poly[i], poly[i - 1]), Segment(pnt1, pnt2));
    }
    if(cnt % 2) return true;
    return false;
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n, d, m;
    cin >> n >> d;

    vector<Point> poly;
    poly.PB(Point(0, d));
    poly.PB(Point(d, 0));
    poly.PB(Point(n, n - d));
    poly.PB(Point(n - d, n));

    cin >> m;
    FOR(i, 0, m - 1)   {
        int x, y;
        cin >> x >> y;
        if(point_inside_polygon(poly, Point(x, y))) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
/**
*/
