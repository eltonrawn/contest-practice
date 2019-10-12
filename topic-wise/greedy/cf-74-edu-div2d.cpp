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

int n;
string str;
LL con[300010];

int last_p[2];
int last[300010];

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n;
    cin >> str;
    LL ans = 0;

    last_p[0] = -1;
    last_p[1] = -1;

    FOR(i, 0, (int)str.size() - 1)   {
//        cout << i - 1 << " : " << ans << "\n";
        int ch = str[i] - 'A';

        if(i == 0)    {
            con[i] = 0;
            last[i] = last_p[ch];
            last_p[ch] = i;
            continue;
        }
        if(str[i - 1] != str[i])    {
            ans += (last_p[ch] + 1);
            con[i] = (last_p[ch] + 1);
            last[i] = last_p[ch];
            last_p[ch] = i;
            continue;
        }

        if(i == 1)    {
            ans += 1;
            con[i] = 1;
            last[i] = i - 1;
            last_p[ch] = i;
            continue;
        }
        if((str[i] == str[i - 1]) && (str[i] != str[i - 2]))    {
            ans += last[i - 1] + 1 + 1 + (i - 1 - last[i - 1] - 2);
            con[i] = last[i - 1] + 1 + 1 + (i - 1 - last[i - 1] - 2);
            last[i] = i - 1;
            last_p[ch] = i;
            continue;
        }
        if((str[i] == str[i - 1]) && (str[i] == str[i - 2]))    {
            ans += con[i - 1] + 1;
            con[i] = con[i - 1] + 1;
            last[i] = i - 1;
            last_p[ch] = i;
            continue;
        }

    }
    cout << ans << "\n";
    return 0;
}

