
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
    int n;
    cin >> n;
    vector<int> rads;
    FOR(i, 0, n - 1)   {
        int tmp;cin >> tmp;
        rads.PB(tmp);
    }
    sort(rads.begin(), rads.end(), greater<int>());
    double tot_area = 0;
    for(int i = 0; i < (int)rads.size(); i += 2)   {
        tot_area += circle_area(rads[i]);
        if(i + 1 < (int)rads.size())    {
            tot_area -= circle_area(rads[i + 1]);
        }
    }
    cout << fixed << setprecision(9) << tot_area;
    return 0;
}
/**
*/


