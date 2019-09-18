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

double ara[100010];
//double ulta_ara[100010];

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n;
    double a;
    cin >> n >> a;
    double ext_angle = 360.0 / n;
    double int_angle = 180.0 - ext_angle;
    double angle_inc = int_angle / (n - 2.0);

    ara[1] = ara[2] = 0;

    FOR(i, 3, n)   {
        ara[i] = ara[i - 1] + angle_inc;
    }


    int v1, v2, v3;
    double diff = 10000000;

    ROF(i, n, 3)   {
//        int tot = int_angle;
//        tot -= ulta_ara[n];
        double tot = ara[i];

        int lo, hi;
        ///a er cheye boro/shoman
        lo = 2, hi = i - 1;
        while(lo < hi) {
            int mid = lo + ((hi - lo + 1) / 2);
            if((tot - ara[mid]) < a)    {
                hi = mid - 1;
            }
            else    {
                lo = mid;
            }

        }
        if((lo >= 2 && lo <= i - 1) && (abs((tot - ara[lo]) - a) < diff))    {
            diff = abs((tot - ara[lo]) - a);
            v1 = i;v2 = 1;v3 = lo;
        }

        ///a er cheye choto/shoman
        lo = 2, hi = i - 1;
        while(lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            if((tot - ara[mid]) > a)    {
                lo = mid + 1;
            }
            else    {
                hi = mid;
            }
        }
        if((lo >= 2 && lo <= i - 1) && (abs((tot - ara[lo]) - a) < diff))    {
            diff = abs((tot - ara[lo]) - a);
            v1 = i;v2 = 1;v3 = lo;
        }
    }
    cout << v1 << " " << v2 << " " << v3;
    return 0;
}
