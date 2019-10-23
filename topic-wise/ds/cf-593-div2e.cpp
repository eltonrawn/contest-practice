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

class Data  {
public:
    int lazy, val, right, le;
    Data()  {
        lazy = 0;
        val = 0;
        right = 0;
        le = 0;
    }
};

Data tree[3 * 100010];
//LL ara[100010];
int n, m;

void updval(int node, int le_ran, int ri_ran, int lazy)    {
    tree[node].le += lazy;
    tree[node].right += lazy;
    tree[node].val += ((ri_ran - le_ran + 1) * lazy);
    tree[node].lazy += lazy;
//    cout << "updval " << node << " : " << tree[node].val << " " << tree[node].lazy << "\n";
    ///tree[node].lazy += lazy;
}

void update(int node, int le_ran, int ri_ran)    {
    if(tree[node].lazy)    {
        if(le_ran != ri_ran)    {
            int mid = (le_ran + ri_ran) / 2;
            updval(node * 2, le_ran, mid, tree[node].lazy);
            updval((node * 2) + 1, mid + 1, ri_ran, tree[node].lazy);
        }
        tree[node].lazy = 0;
    }
}

void update_range(int node, int le_ran, int ri_ran, int le, int ri, int val)  {///ran = range
//    cout << "node : " << node << "\n";
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return;
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        updval(node, le_ran, ri_ran, val);
        ///update(node, le_ran, ri_ran);
        return;
    }
    update(node, le_ran, ri_ran);

    int mid = (le_ran + ri_ran) / 2;
    update_range(node * 2, le_ran, mid, le, ri, val);
    update_range((node * 2) + 1, mid + 1, ri_ran, le, ri, val);
    tree[node].val = tree[node * 2].val + tree[(node * 2) + 1].val;
//    tree[node].right = max(tree[node * 2].right, tree[(node * 2) + 1].right);
    tree[node].right = tree[(node * 2) + 1].right;
    tree[node].le = tree[(node * 2)].le;
}


int query(int node, int le_ran, int ri_ran, int le, int ri)  {///ran = range
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return 0;
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        ///cout << node << " : " << tree[node].val << "\n";
        return tree[node].val;
    }
    update(node, le_ran, ri_ran);

    int mid = (le_ran + ri_ran) / 2;
    int ans = 0;
    ans += query(node * 2, le_ran, mid, le, ri);
    ans += query((node * 2) + 1, mid + 1, ri_ran, le, ri);
    ///cout << node << " : " << ans << "\n";
    return ans;
}

int query_le(int node, int le_ran, int ri_ran, int qq)  {///ran = range
    if(le_ran == ri_ran)    {
        if(tree[node].val <= (qq - 1))    {
            return le_ran;
        }
        return -1;
    }
    update(node, le_ran, ri_ran);

    int mid = (le_ran + ri_ran) / 2;
    if((tree[(node * 2) + 1].le) <= (qq - 1))    {
        return query_le((node * 2) + 1, mid + 1, ri_ran, qq);
    }
    else    {
        return query_le(node * 2, le_ran, mid, qq);
    }
}

int query_ri(int node, int le_ran, int ri_ran, int qq)  {///ran = range
//    cout << "node " << node << "\n";
    if(le_ran == ri_ran)    {
        if(tree[node].val >= (qq + 1))    {
            return le_ran;
        }
        return -1;
    }
    update(node, le_ran, ri_ran);

    int mid = (le_ran + ri_ran) / 2;

    if((tree[(node * 2)].right) >= (qq + 1))    {
        return query_ri(node * 2, le_ran, mid, qq);
    }
    else    {
        return query_ri((node * 2) + 1, mid + 1, ri_ran, qq);
    }
}

int q[100010];

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
//    cin >> n >> m;
    scanf("%d", &n);
    scanf("%d", &m);
    FOR(i, 0, m - 1)   {
//        cin >> q[i];
        scanf("%d", &q[i]);
    }

    if(n == 1)    {
        cout << 0;
        return 0;
    }


    LL ans = 0;

    FOR(i, 1, n)   {
        update_range(1, 1, n, i, i, i);
    }

    FOR(i, 0, m - 1)   {
        ///exclude positions which moved to position (q[i] - 1)

        ///find left range
        int pos = query_le(1, 1, n, q[i] - 1);
        if(pos != -1)    {
            update_range(1, 1, n, 1, pos, 1);
//            cout << "updating : " << 1 << " to " << pos << "\n";
        }
        ///find right range
        pos = query_ri(1, 1, n, q[i] - 1);
        if(pos != -1)    {
            update_range(1, 1, n, pos, n, 1);
//            cout << "updating : " << pos << " to " << n << "\n";
        }
    }

    FOR(i, 1, n)   {
        int val = query(1, 1, n, i, i) + 1;
        if(val >= n)    {
            break;
        }
        ans += (n - val);
    }


    ///initialize and run again
    MEM(tree, 0);
    FOR(i, 1, n)   {
        update_range(1, 1, n, i, i, i);
    }

    FOR(i, 0, m - 1)   {
        ///exclude positions which moved to position (q[i] + 1)

        ///find left range
        int pos = query_le(1, 1, n, q[i] + 1);
        if(pos != -1)    {
            update_range(1, 1, n, 1, pos, -1);
        }

        ///find right range
        pos = query_ri(1, 1, n, q[i] + 1);
        if(pos != -1)    {
            update_range(1, 1, n, pos, n, -1);
        }
//        break;
    }

    ROF(i, n, 1)   {
        int val = query(1, 1, n, i, i) - 1;
        if(val <= 1)    {
            break;
        }
        ans += (val - 1);
    }
//    cout << ans << "\n";

    ans = (n * (LL)n)- ans;
//    cout << ans << "\n";
    printf("%lld\n", ans);
    return 0;
}

