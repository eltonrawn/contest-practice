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

int n;
vector<int> vv;

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n;
    FOR(i, 0, n - 1)   {
        int tmp;cin >> tmp;
        vv.PB(tmp);
    }
    sort(vv.begin(), vv.end());
    bool yes = 0;
    FOR(i, 2, n - 1)   {
//        cout << vv[i] << " " << vv[i - 1] << " " << vv[i - 2] << "\n";
        if(vv[i] < vv[i - 1] + vv[i - 2])    {
            yes = 1;
            break;
        }
    }
    if(yes)    {
        cout << "YES";
    }
    else    {
        cout << "NO";
    }
    return 0;
}
/**
*/

