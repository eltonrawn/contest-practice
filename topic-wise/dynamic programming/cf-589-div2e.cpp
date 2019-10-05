
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


LL ndp[1010][1010];

LL nCr(int n,int r)
{
    if(r == 0)return 1;
    if(r == 1) return n;
    if(n == r) return 1;
    if(ndp[n][r] != -1)  {
        return ndp[n][r];
    }
    return ndp[n][r] = ((nCr(n-1, r) + nCr(n-1, r-1))) % MOD;
}

//LL power(int a, int b) {
//    LL ans = 1;
//    FOR(i, 1, b)   {
//        ans = (ans * a) % MOD;
//    }
//    return ans;
//}

LL bm(LL base, int power) {    //bm represents bigmod
    if(power == 0)  {
        return 1;
    }
    if(power % 2 == 0)  {
        LL ret = bm(base, power / 2);
        return (ret * ret) % MOD;
    }
    else    {
        return (base * bm(base, power - 1)) % MOD;
    }
}
LL kbm[300];
LL k1bm[300];


int n, k;
LL dp[300][300];

LL func(int row, int col_filled)  {
    int col_rest = n - col_filled;
    if(row > n)    {
        if(col_rest)    {
            return 0;
        }
        return 1;
    }

    if(dp[row][col_filled] != -1)    {
        return dp[row][col_filled];
    }

    LL ans = 0;

//      fill col_rest with 1 and other and col_filled with all
    FOR(i, 1, col_rest)   {
        LL gun = nCr(col_rest, i) % MOD;
//        gun = (gun * bm(k - 1, col_rest - i)) % MOD;
        gun = (gun * k1bm[col_rest - i]) % MOD;
//        gun = (gun * bm(k, col_filled)) % MOD;
        gun = (gun * kbm[col_filled]) % MOD;
        gun = (gun * func(row + 1, col_filled + i)) % MOD;
        ans = (ans + gun) % MOD;
//        ans = ans + (nCr(col_rest, i) * power(k - 1, col_rest - i) * power(k, col_filled) * func(row + 1, col_filled + i));
    }
//      fill col_rest with other and col_filled with 1 and other
    FOR(i, 1, col_filled)   {
        LL gun = nCr(col_filled, i) % MOD;
//        gun = (gun * bm(k - 1, col_filled - i)) % MOD;
        gun = (gun * k1bm[col_filled - i]) % MOD;
//        gun = (gun * bm(k - 1, col_rest)) % MOD;
        gun = (gun * k1bm[col_rest]) % MOD;
        gun = (gun * func(row + 1, col_filled)) % MOD;
        ans = (ans + gun) % MOD;
//        ans = ans + (nCr(col_filled, i) * power(k - 1, col_filled - i) * power(k - 1, col_rest) * func(row + 1, col_filled));
    }
    return dp[row][col_filled] = ans;
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    MEM(ndp, -1);
    MEM(dp, -1);

    cin >> n >> k;
    FOR(i, 0, n)   {
        kbm[i] = bm(k, i);
//        cout << i << " : " << kbm[i] << "\n";
    }
    FOR(i, 0, n)   {
        k1bm[i] = bm(k - 1, i);
    }

    cout << func(1, 0);
    return 0;
}
/**
250 1000000000
*/
