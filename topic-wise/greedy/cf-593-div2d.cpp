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

int n, m;
set<int> row[100010], col[100010];
LL tot;
int up, down, le, ri;

void func(int r, int c, int dir, int rot)  {
//    if(r == 1 && c == 3)    {
//        cout << r << " " << c << " " << dir << " " << rot << "\n";
//        return;
//    }
//    cout << r << " " << c << " " << dir << "\n";

    if(dir == 1)    {
        int pp = (*(row[r].lower_bound(c)));

        pp--;
        pp = min(pp, ri - 1);

//        if(r == 1 && c == 3)    {
//            cout << r << " " << c << " " << dir << " " << rot << "\n";
//            cout << pp << "\n";
//            return;
//        }

        if(pp == c)    {
            ri = pp;
            if(rot)    {
                func(r, c, 2, 0);
            }
        }
        else    {

//            row[r].insert(c);
//            col[c].insert(r);
            tot -= (pp - c);
            func(r, pp, dir, 1);
        }
    }

    if(dir == 3)    {
        auto it = (row[r].lower_bound(c));
        it--;
        int pp = (*it);

        pp++;
        pp = max(pp, le + 1);

        if(pp == c)    {
            le = pp;
            if(rot)    {
                func(r, c, 4, 0);
            }
        }
        else    {
//            row[r].insert(c);
//            col[c].insert(r);

            tot -= (c - pp);
            func(r, pp, dir, 1);
        }
    }

    if(dir == 2)    {
        int pp = (*(col[c].lower_bound(r)));

        pp--;
        pp = min(pp, down - 1);

        if(pp == r)    {
            down = pp;
            if(rot)    {
                func(r, c, 3, 0);
            }
        }
        else    {
//            row[r].insert(c);
//            col[c].insert(r);

            tot -= (pp - r);
            func(pp, c, dir, 1);
        }
    }
    if(dir == 4)    {
        auto it = (col[c].lower_bound(r));
        it--;
        int pp = (*it);

        pp++;
        pp = max(pp, up + 1);

        if(pp == r)    {
            up = pp;
            if(rot)    {
                func(r, c, 1, 0);
            }
        }
        else    {
//            row[r].insert(c);
//            col[c].insert(r);
            tot -= (r - pp);
            func(pp, c, dir, 1);
        }
    }
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n >> m;
    int k;
    cin >> k;
    FOR(i, 0, k - 1)   {
        int u, v;
        cin >> u >> v;
//        row[u].PB(v);
//        col[v].PB(u);
        row[u].insert(v);
        col[v].insert(u);
    }
//    FOR(i, 1, n)   {
//        sort(row[i].begin(), row[i].end());
//    }
//    FOR(i, 1, m)   {
//        sort(col[i].begin(), col[i].end());
//    }

    FOR(i, 1, n)   {
        row[i].insert(m + 1);
        row[i].insert(0);
    }
    FOR(i, 1, m)   {
        col[i].insert(n + 1);
        col[i].insert(0);
    }
    up = 0;
    down = n + 1;
    le = 0;
    ri = m + 1;

//    FOR(i, 1, n)   {
//        cout << i << " : ";
//        for(auto it=row[i].begin(); it != row[i].end(); it++)   {
//            cout << *(it) << " ";
//        }
//        cout << "\n";
//    }
//
//    FOR(i, 1, n)   {
//        cout << i << " : ";
//        for(auto it=col[i].begin(); it != col[i].end(); it++)   {
//            cout << *(it) << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

//    return 0;
    tot = n * ((LL)m);
    tot -= k;///not counting blocking cells
    tot--;///not counting initial cells


    up = 1;
    func(1, 1, 1, 1);

//    cout << tot << "\n";

    if(tot == 0)    {
        cout << "Yes";
    }
    else    {
        cout << "No";
    }

    return 0;
}
