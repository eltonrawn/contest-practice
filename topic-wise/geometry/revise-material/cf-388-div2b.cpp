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
    double x, y;
    Vector() {}
    Vector(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
};

class Cmp  {
public:
    bool operator()(Vector a, Vector b) {
        if(a.x == b.x)    {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};

class Equal  {
public:
    bool operator()(Vector a, Vector b) {
        if((a.x == b.x) && (a.y == b.y))    {
            return true;
        }
        return false;
    }
};

Vector vector_add(Vector a, Vector b)   {
    return Vector(a.x + b.x, a.y + b.y);
}
Vector vector_sub(Vector a, Vector b)   {
    return Vector(a.x - b.x, a.y - b.y);
}

vector<Vector> ans;

void print_ans()    {
    cout << ans.size() << "\n";
    FOR(i, 0, (int)ans.size() - 1)   {
        cout << ans[i].x << " " << ans[i].y << "\n";
    }
}

/**
two points a, b are fixed where they are connected.
segment between c and d are going to be parallel with ab

two ways d can be created.
a is connected with c and b is connected with d
b is connected with c and a is connected with d
*/
void fourth_point(Vector a, Vector b, Vector c)  {
    ans.PB(vector_add(a, vector_sub(c, b)));
    ans.PB(vector_add(b, vector_sub(c, a)));
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    vector<Vector> vectors;
    FOR(i, 0, 2)   {
        int x, y;cin >> x >> y;
        vectors.PB(Vector(x, y));
    }
    fourth_point(vectors[0], vectors[1], vectors[2]);
    fourth_point(vectors[0], vectors[2], vectors[1]);
    fourth_point(vectors[1], vectors[2], vectors[0]);
    sort(ans.begin(), ans.end(), Cmp());
//    print_ans();
    ans.erase(unique(ans.begin(), ans.end(), Equal()), ans.end());
    print_ans();
    return 0;
}
