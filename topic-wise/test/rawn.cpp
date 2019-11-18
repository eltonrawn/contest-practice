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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int n, m;
int ara[200010];

void print_vec(vector<int> vv) {
    FOR(i, 0, (int)vv.size() - 1)   {
        cout << vv[i] << " ";
    }
    cout << "\n";
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    while(cin >> n) {
        FOR(i, 0, n - 1)   {
            cin >> ara[i];
        }
        sort(ara, ara + n);

        vector<int> vv;

        int pos = 0;
        vv.PB(1);pos++;
        FOR(i, 0, n - 1)   {
            int pp = ara[i];
            while(pos < pp) {
                vv.PB(0);
                pos++;
            }
            vv.PB(1);pos++;
        }
//        print_vec(vv);
        vv = multiply(vv, vv);
//        print_vec(vv);
        cin >> m;
        FOR(i, 0, m - 1)   {
            cin >> ara[i];
        }
        sort(ara, ara + m);

        int ans = 0;
        for(int i = 0; i < m; i++)   {
            if(ara[i] >= vv.size())    {
                break;
            }
            if(vv[ ara[i] ])    {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
