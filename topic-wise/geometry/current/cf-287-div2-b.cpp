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

class Vector {
public:
    vector<double> dim;///dim means dimensions
    Vector()    {
    }
    Vector(double x, double y)    {
        dim.PB(x);
        dim.PB(y);
    }
};

double dot_product(Vector a, Vector b)   {
    if(a.dim.size() != b.dim.size())    {
        return -1;
    }
    double ans = 0;
    FOR(i, 0, (int)a.dim.size() - 1)   {
        ans += (a.dim[i] * b.dim[i]);
    }
    return ans;
}

double vec_len(Vector a)    {
    return sqrt(dot_product(a, a));
}

double vec_dis(Vector a, Vector b)    {
    double ans = 0;
    FOR(i, 0, (int)a.dim.size() - 1)   {
        ans += ((a.dim[i] - b.dim[i]) * (a.dim[i] - b.dim[i]));
    }
    return sqrt(ans);
}

bool is_equal(Vector a, Vector b)  {
    FOR(i, 0, (int)a.dim.size() - 1)   {
        if(a.dim[i] != b.dim[i])    {
            return false;
        }
    }
    return true;
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    Vector v1 = Vector(x1, y1);
    Vector v2 = Vector(x2, y2);
    double dis = vec_dis(v1, v2);
    if(is_equal(v1, v2))    {
        cout << 0;
        return 0;
    }
    cout << max((int)(dis / r) - 1, 1);
    return 0;
}
/**
100 0 0 0 1
*/
