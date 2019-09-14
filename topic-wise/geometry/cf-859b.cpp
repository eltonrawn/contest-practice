
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

int ans[1000010];

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int pos = 1;
    ans[pos++] = 4;
    ans[pos++] = 6;

    int lim = 1000000;
//    lim = 10;

    int foo = 2;
    while(pos <= lim) {
        int past = ans[pos - 1];
        for(int i = 1; (i <= foo) && (pos <= lim); i++)   {
            ans[pos++] = past + 2;
//            cout << pos - 1 << " : " << ans[pos - 1] << "\n";
        }
        past = ans[pos - 1];
        for(int i = 1; (i <= foo) && (pos <= lim); i++)   {
            ans[pos++] = past + 2;
//            cout << pos - 1 << " : " << ans[pos - 1] << "\n";
        }
        foo++;
    }
    int n;cin >> n;
    cout << ans[n] << "\n";
    return 0;
}
/**
*/
