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

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int ab, bc, ca;
    cin >> ab >> bc >> ca;
    double a = sqrt((ab * ca) / bc);
    double c = ca / a;
    double b = bc / c;
    cout << (4 * a) + (4 * b) + (4 * c);
    return 0;
}
/**
*/

