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

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n = 100;

    int sum = n * (n + 1) / 2;
    int sq_of_sum = sum * sum;

//    int sum_of_sq = 0;
//    FOR(i, 1, n)   {
//        sum_of_sq += (i * i);
//    }

    int sum_of_sq = ((2 * n) + 1) * (n + 1) * n / 6;
    cout << sq_of_sum << " " << sum_of_sq << "\n";
    cout << sq_of_sum - sum_of_sq << "\n";
    return 0;
}
/**
formula for 1^2 + 2^2 + 3^2 + ..... + n^2 = n/6(2n + 1)(n + 1)
*/

