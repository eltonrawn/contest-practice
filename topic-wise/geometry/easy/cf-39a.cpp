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

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    double x, y;
    cin >> x >> y;
    if(x == 0|| y == 0)    {
        cout << "black";
        return 0;
    }
    Vector vv = Vector(x, y);
    double vv_len = vec_len(vv);
    if(vv_len == (int)vv_len)    {
        cout << "black";
        return 0;
    }

    if(((x > 0) && (y > 0)) || ((x < 0) && (y < 0)))    {
        if((int)vv_len % 2 == 0)    {
            cout << "black";
        }
        else    {
            cout << "white";
        }
    }
    else    {
        if((int)vv_len % 2 == 0)    {
            cout << "white";
        }
        else    {
            cout << "black";
        }
    }
    return 0;
}

