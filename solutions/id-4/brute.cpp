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

bool is_palindrome(int num) {
    int sec = 0;
    int fir = num;
    while(num) {
        sec = (sec * 10) + (num % 10);
        num /= 10;
    }
    if(fir == sec)    {
        return 1;
    }
    return 0;
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int mx = 0;

    int le = 100;
    int ri = 999;
    FOR(i, le, ri)   {
        FOR(j, i, ri)   {
            if(is_palindrome(i * j))    {
                mx = max(mx, i * j);
                cout << i << " * " << j << " : " << (i * j) << "\n";
            }
        }
    }
    cout << mx << "\n";
    return 0;
}
/**
faster solution
product of two 3-digit number should contain 6 digits.

let's say palindrome,
p = 100000x + 10000y + 1000z + 100z + 10y + x
p = 100001x + 10010y + 1100z
p = 11 (9091x + 910y + 100z)

p has a factor 11. if p = a * b. one of the number (a or b) has to be factor of 11. so bruteforce can be optimized using this

another solution: for differrent values of (0 <= x, y, z <= 9) palindrome can be found. complexity is 10 * 10 * 10
*/
