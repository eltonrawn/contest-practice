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

vector<int> pr;
bool chk[10000000 + 10];

void sieve(LL lim) {
    pr.PB(2);
    for(LL i = 3; i <= lim; i += 2)   {
        if(chk[i] == 0)    {
            pr.PB(i);
        }
        for(LL j = i * i; j <= lim; j += i)   {
            chk[j] = 1;
        }
    }
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    sieve(10000000);
//    FOR(i, 0, 10)   {
//        cout << pr[i] << " ";
//    }
    cout << pr[10000];
    return 0;
}
/**
10001
664579
*/


