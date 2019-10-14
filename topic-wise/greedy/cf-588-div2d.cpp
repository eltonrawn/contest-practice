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

//class Data  {
//public:
//    LL a;
//    int b;
//};
LL a[7010];
LL b[7010];
map<LL, int> cnt;
map<LL, bool> taken;
int n;
int is_dub[7010];

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n;
    FOR(i, 0, n - 1)   {
        cin >> a[i];
        cnt[ a[i] ]++;
    }
    FOR(i, 0, n - 1)   {
        cin >> b[i];
    }

    FOR(i, 0, n - 1)   {
        if(cnt[ a[i] ] > 1)    {
            is_dub[i] = 1;
        }
    }

    LL ans = 0;
    FOR(i, 0, n - 1)   {
        if(is_dub[i])    {
            ans += b[i];
            continue;
        }

        bool chk = 0;
        FOR(j, 0, n - 1)   {
            if(!is_dub[j])    {
                continue;
            }
            if((a[i] | a[j]) == a[j])    {
                chk = 1;
                break;
            }
        }
        if(chk)    {
            ans += b[i];
        }
    }
    cout << ans;
    return 0;
}
