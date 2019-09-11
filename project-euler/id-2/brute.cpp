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

int dp[500000];

LL func(int n)  {
    if(n <= 2)    {
        return n;
    }
    if(dp[n] != -1)    {
        return dp[n];
    }
    return dp[n] = func(n - 1) + func(n - 2);
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    MEM(dp, -1);
    LL sum = 0;
    for(int i = 1;; i++)   {
        if(func(i) > 4000000)  {
            break;
        }
        if(func(i) % 2 == 0)    {
            sum += func(i);
        }
    }
    cout << sum << "\n";

//    for(int i = 1; i <= 20; i ++)   {
//        cout << func(i) << " ";
//    }
//    cout << "\n\n";
//
//    int last = 0;
//    for(int i = 2; i <= 20; i += 3)   {
//        cout << func(i) << " " << func(i) - last << "\n";
//        last = func(i);
    }
}
/**
first sequences are
1 1 2 3 5 8 13 21 34 55 89 144
here you can see that every 3rd number is even. as two numbers before them are always odd.
fn can also be written as,
fn = 4 * f(n-3) + f(n - 6)
proof:
fn = f(n - 1) + f(n - 2)
   = f(n - 2) + f(n - 3) + f(n - 2)
   = 2 * f(n - 2) + f(n - 3)
   = 2 * f(n - 3) + 2 * f(n - 4) + f(n - 3)
   = 3 * f(n - 3) + 2 * f(n - 4)
   = 3 * f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)
   = 4 * f(n - 3) + f(n - 6)
*/

