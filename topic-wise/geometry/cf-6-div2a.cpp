

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

typedef pair<int, int> PII;

vector<int> vv;
vector<int> taken;

int ans;

void func(int pos, bool exclude)  {
    if(pos == 4)    {
        if(exclude)    {
            return;
        }
        if(taken[0] + taken[1] > taken[2])    {
            ans = max(ans, 2);
        }
        else if(taken[0] + taken[1] == taken[2])    {
            ans = max(ans, 1);
        }
        return;
    }
    ///niye
    taken.PB(vv[pos]);
    func(pos + 1, exclude);
    taken.pop_back();
    ///na niye
    if(exclude)    {
        func(pos + 1, 0);
    }
}

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    FOR(i, 0, 3)   {
        int tmp;cin >> tmp;
        vv.PB(tmp);
    }
    sort(vv.begin(), vv.end());

    ans = 0;
    func(0, 1);
    if(ans == 0) {
        cout << "IMPOSSIBLE";
    }
    else if(ans == 1) {
        cout << "SEGMENT";
    }
    else {
        cout << "TRIANGLE";
    }
    return 0;
}
/**
*/
