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

int n = 999;

int get_sum(int num)   {
    int seq = n / num;
    return num * seq * (seq + 1) / 2;
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int sum = 0;
    cout << get_sum(3) + get_sum(5) - get_sum(3 * 5) << "\n";
    return 0;
}
/**
inclusion exclusion used. let's solve for 20
3 5 6 9 10 12 15 18 20

for 3,
3 6 9 12 15 18

for 5,
5 10 15 20

both have 15 in common because 15 = 3 * 15
that's why get_sum(3) + get_sum(5) - get_sum(3 * 15)

how to write get_sum for a number?
let's solve for 3:
3 + 6 + 9 + 12 + 15 + 18 = 63
3 * (1 + 2 + 3 + 4 + 5 + 6) = 63
3 * [6 * (6 + 1) / 2] = 63 where, 20 / 3 = 6
*/
