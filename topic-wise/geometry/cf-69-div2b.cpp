
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

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    string str;
    cin >> str;
    int hour = ((str[0] - '0') * 10) + (str[1] - '0');
    int minute = ((str[3] - '0') * 10) + (str[4] - '0');
    hour = hour % 12;
//    cout << hour << " " << minute << "\n";
    cout << ((360.0 / 12.0) * hour) + ((360.0 / 12.0) * (minute / 60.0)) << " ";
    cout << ((360.0 / 60.0) * minute);
    return 0;
}
/**
*/

