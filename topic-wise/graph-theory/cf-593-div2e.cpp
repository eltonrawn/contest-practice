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
int ara[100010];

int func(int pos, int ara_p)  {
    ///make trick

    ///keep here
    if(ara[ ara_p ] == pos)    {
        func(pos + 1, val);
    }

}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n >> m;
    FOR(i, 0, m - 1)   {
        cin >> ara[i];
    }

    return 0;
}

