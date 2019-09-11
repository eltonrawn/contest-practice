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

vector<int> primes;
bool prime_chk[1000000];

void sieve(LL lim) {
    primes.PB(2);

    for(LL i = 3; i <= lim; i += 2)   {
        if(prime_chk[i])    {
            continue;
        }
        primes.PB(i);
        prime_chk[i] = 1;
        for(LL j = i * i; j <= lim; j += i)   {
//            cout << j << "\n";
            prime_chk[j] = 1;
        }
    }
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    LL n = 600851475143;
    sieve(sqrt(n) + 10);

    vector<int> prime_facts;
    FOR(i, 0, (int)primes.size() - 1)   {
        if(n % primes[i] == 0)    {
            prime_facts.PB(primes[i]);
            while(n % primes[i] == 0) {
                n /= primes[i];
//                cout << "factors : " << primes[i] << "\n";
            }
        }
    }
    FOR(i, 0, (int)prime_facts.size() - 1)   {
        cout << prime_facts[i] << " ";
    }
    cout << "\n" << n;

//    cout << "\n";
//    FOR(i, 0, 30)   {
//        cout << primes[i] << " ";
//    }
    return 0;
}
/**
2 3 5 7 11 13 17 19
prime factors are factors that are prime. Factors are the numbers you multiply together to get another number.
Here we have to find largest prime factor.

Only by checking till square root of a number, all prime factors can be found.

proof:
n = route(n) * route(n)
if n = a * b and a >= route(n) then, b <= route(n)
*/
