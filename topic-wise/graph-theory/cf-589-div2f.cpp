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

int deg[140000];
int edge_cnt[140000];
vector<int> adjl[140000];

vector<int> depth[140000];
int par_idx[140000];

int func1(int u, int par) {
    int ans = 0;
    FOR(i, 0, (int)adjl[u].size() - 1)   {
        int v = adjl[u][i];
        if(v == par)    {
            depth[u].PB(0);
            par_idx[u] = i;
            continue;
        }
        int dep = func1(v, u);
        depth[u].PB(1 + dep);
        ans = max(ans, 1 + dep);
    }
    return ans;
}

int func2(int u, int par) {
    int ans = 0;
    FOR(i, 0, (int)adjl[u].size() - 1)   {
        int v = adjl[u][i];
        if(v == par)    {
            continue;
        }
        int mx = 0;
        FOR(j, 0, (int)adjl[u].size() - 1)   {
            if(i == j)    {
                continue;
            }
            mx = max(mx, depth[u][j]);
        }
        depth[v][ par_idx[v] ] = mx + 1;
    }
    FOR(i, 0, (int)adjl[u].size() - 1)   {
        int v = adjl[u][i];
        if(v == par)    {
            continue;
        }
        func2(v, u);
    }
    return ans;
}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int n;
    cin >> n;
    int node_no = (1 << n) - 1;
//    cout << node_no << "\n";
    FOR(i, 1, node_no - 2)   {
        int u, v;
        cin >> u >> v;
        adjl[u].PB(v);
        adjl[v].PB(u);
        deg[u]++;
        deg[v]++;
    }
    FOR(i, 1, node_no)   {
        edge_cnt[ deg[i] ]++;
//        cout << i << " : " << deg[ i ] << "\n";
    }

    int leaf_node_no = (1 << (n - 1));

    if(n == 2)    {
        cout << n << "\n";
        FOR(i, 1, 3)   {
            if(deg[i])    {
                cout << i << " ";
            }
        }
        return 0;
    }

    int root;
    /**
    if middle node is cut (from level 3 to level_before_leaf)
    par       edge -> 4, no.of node -> 1
    root node edge -> 2, no.of node -> 1
    leaf      edge -> 1, no.of node -> (2 ^ (n - 1))
    non-leaf  edge -> 3, no.of node -> (2 ^ n) - 1 - (2 ^ (n - 1)) - 3
    */
    if((edge_cnt[4] == 1) && (edge_cnt[2] == 1) && (edge_cnt[1] == leaf_node_no) && (edge_cnt[3] == node_no - leaf_node_no - 3))    {
        FOR(i, 1, node_no)   {
            if(deg[i] == 2)    {
                root = i;
                break;
            }
        }
        func1(root, 0);

        int u;///parent node
        FOR(i, 1, node_no)   {
            if(deg[i] == 4)    {
                u = i;
                break;
            }
        }

        vector<int> moo;
        FOR(i, 0, (int)adjl[u].size() - 1)   {
            if(par_idx[u] == i)    {
                continue;
            }
            moo.PB(depth[u][i]);
        }
        sort(moo.begin(), moo.end());
        if(moo[0] == moo[1] && moo[2] == moo[1] + 1)    {
            cout << 1 << "\n";
            cout << u;
//            if(u == 23261)    {
//                cout << "hi1";
//            }
            return 0;
        }
    }
    /**
    if leaf node is cut
    par       edge -> 2, no.of node -> 1
    root node edge -> 2, no.of node -> 1
    leaf      edge -> 1, no.of node -> (2 ^ (n - 1)) - 1
    non-leaf  edge -> 3, no.of node -> (2 ^ n) - 1 - (2 ^ (n - 1)) - 2
    */
    if((edge_cnt[2] == 2) && (edge_cnt[1] == leaf_node_no - 1) && (edge_cnt[3] == node_no - leaf_node_no - 2))    {

        int cut_leaf = -1;
        FOR(u, 1, node_no)   {
            if(deg[u] == 2)    {
                bool chk = 1;
                for(int i = 0; i < (int)adjl[u].size(); i++)   {
                    int v = adjl[u][i];
                    if(deg[v] == 1)    {
                        cut_leaf = u;
                        chk = 0;
                    }
                }
                if(chk)    {
                    root = u;
                }
            }
        }
        func1(root, 0);
        if(depth[root][0] == depth[root][1])    {
            cout << 1 << "\n";
            cout << cut_leaf << "\n";
//            if(cut_leaf == 23261)    {
//                cout << "hi2";
//            }
            return 0;
        }


    }
    /**
    if root-child node is cut
    leaf      edge -> 1, no.of node -> (2 ^ (n - 1))
    non-leaf  edge -> 3, no.of node -> (2 ^ n) - 1 - (2 ^ (n - 1)) - 1
    */
    if((edge_cnt[1] == leaf_node_no) && (edge_cnt[3] == node_no - leaf_node_no - 1))    {
//        cout << 2 << "\n";
        if(deg[1] != 0)    {
            func1(1, 0);
            func2(1, 0);
//            FOR(u, 1, node_no)   {
//                cout << u << " : ";
//                FOR(i, 0, (int)depth[u].size() - 1)   {
//                    int v = depth[u][i];
//                    cout << depth[u][i] << " ";
//                }
//                cout << "\n";
//            }
        }
        else    {
            func1(2, 0);
            func2(2, 0);
        }
        vector<int> foo;
        FOR(u, 1, node_no)   {
            if(deg[u] != 3)    {
                continue;
            }
            sort(depth[u].begin(), depth[u].end());
            if(depth[u][0] == (n - 2) && depth[u][1] == (n - 2) && depth[u][2] == (n - 1))    {
//                cout << u << " ";
                foo.PB(u);
            }
        }
        if(foo.size() == 2)    {
            cout << 2 << "\n";
            cout << foo[0] << " " << foo[1];
            return 0;
        }

    }
    cout << 0;
    return 0;
}
