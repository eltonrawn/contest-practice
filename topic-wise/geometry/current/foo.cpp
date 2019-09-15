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
typedef long double LD;

/**
get angle A given three sides a, b and c using law of cosine. A is opposite to a.
cosA = ((b * b) + (c * c) - (a * a)) / (2 * b * c)
*/
LD angle_sss(LD a, LD b, LD c) {
    return acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
}

LD herons_area_sss(LD a, LD b, LD c) {
    LD s = (a + b + c) / (LD)2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

LD triangle_area(LD b, LD h)  {
    return 0.5 * b * h;
}
/**
In this isosceles triangle, a is base, h is height and b is other two sides
A, B and H are opposite angle for a, b and h.
*/

LD n, h, a, b;
LD A, B;

LD get_base(LD cur_b)  {
    return (cur_b / sin(B)) * sin(A);
}

LD prev_area;
LD prev_b;
bool binary_b(LD area) {
    LD lo = 0, hi = b - prev_b;
    for(int i = 0; i < 100; i++)   {
//        LD mid = lo + ((hi - lo) / (LD)2.0);
        LD mid = (lo + hi) / (LD)2;

        LD tot_b = prev_b + mid;
        LD new_a = get_base(tot_b);
        LD new_area = herons_area_sss(new_a, tot_b, tot_b) - prev_area;

        cout << lo << " " << hi << " " << mid << " : " << fixed << setprecision(13) << new_area << "\n";

        if(new_area <= area)    {
            lo = mid;
        }
        else    {
            hi = mid;
        }
    }

    LD tot_b = prev_b + lo;
    LD new_a = get_base(tot_b);
    LD new_area = herons_area_sss(new_a, tot_b, tot_b) - prev_area;
    prev_area = new_area;
    prev_b = tot_b;
    return 1;
//    return 0;
}

vector<LD> ans;
bool chk(LD area)   {
    ///binary search on side b
    ans.clear();
    prev_area = 0;
    prev_b = 0;
    FOR(i, 1, n - 1)   {
        binary_b(area);
        ans.PB(prev_b);
//        if(binary_b(area))  {
//            ans.PB(prev_b);
//        }
//        else    {
//            return 0;
//        }
    }
    return 1;
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);

    cin >> n >> h;
    a = 1;
    b = sqrt((h * h) + ((a * a) / 4));
    A = angle_sss(a, b, b);
    B = (pi - A) / 2;

    cout << "h : " << h << "\n";
    cout << "b : " << b << "\n";
    cout << "a : " << a << "\n";
    cout << "A : " << A << "\n";
    cout << "B : " << B << "\n";

    ///binary search on area
//    LD lo = 0, hi = 100000;
//    for(int i = 0; i < 100; i++)   {
//        LD mid = lo + (hi - lo) / 2.0;
////        cout << mid << " : " << chk(mid) << "\n";
//        if(chk(mid))    {
//            lo = mid;
//        }
//        else    {
//            hi = mid;
//        }
//    }
    cout << "tot area : "  << fixed << setprecision(13) << triangle_area(a, h) / n << "\n";
    chk(triangle_area(a, h) / n);
    FOR(i, 0, (int)ans.size() - 1)   {
        cout << ans[i] << " ";
    }
    return 0;
}

