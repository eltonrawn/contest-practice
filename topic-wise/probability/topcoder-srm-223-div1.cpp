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

vector<LL> a_scores;
vector<LL> wagers;
double ans_prob;
LL ans_wager;
LL ora[2];

void func(int pos)  {
    if(pos == 2)    {
        LL taken = max(ora[0], ora[1]) + 1;
        if(taken > a_scores[pos] + a_scores[pos])    {
            return;
        }
        cout << ora[0] << " " << ora[1] << "\n";

        if(taken <= a_scores[pos])    {
            double prob = 1;
            if(taken <= a_scores[0] + wagers[0])    {
                prob *= 0.5;
            }
            if(taken <= a_scores[1] + wagers[1])    {
                prob *= 0.5;
            }

            if(prob == ans_prob)    {
                ans_wager = min(ans_wager, 0LL);
            }
            else if(prob > ans_prob)   {
                ans_prob = prob;
                ans_wager = 0;
            }
            cout << "fir : " << ans_prob << " " << ans_wager << "\n";
        }

        else if(taken <= a_scores[pos] + a_scores[pos])    {
            double prob = 0.5;
            if(taken <= a_scores[0] + wagers[0])    {
                prob *= 0.5;
            }
            if(taken <= a_scores[1] + wagers[1])    {
                prob *= 0.5;
            }


            if(prob == ans_prob)    {
                ans_wager = min(ans_wager, taken - a_scores[pos]);
            }
            else if(prob > ans_prob)   {
                ans_prob = prob;
                ans_wager = taken - a_scores[pos];
            }
            cout << "sec : " << ans_prob << " " << ans_wager << "\n";
        }
        return;
    }
    ///wager kom hole
    ora[pos] = a_scores[pos] - wagers[pos];
    func(pos + 1);
    ///wager beshi hole
    ora[pos] = a_scores[pos] + wagers[pos];
    func(pos + 1);
}

//void func()  {
//    ///duitai wager kom
//    int a = a_scores[0] - wagers[0];
//    int b = a_scores[1] - wagers[1];
//
//}

class QuizShow  {
public:
    int wager(vector<int> scores, int wager1, int wager2)  {
        a_scores.PB(scores[1]);
        a_scores.PB(scores[2]);
        a_scores.PB(scores[0]);
    //    wagers.PB(0);
        wagers.PB(wager1);
        wagers.PB(wager2);

        ans_prob = 0;
        ans_wager = 100000000000000000LL;

        func(0);

        if(ans_wager == 100000000000000000LL)    {
            return 0;
        }
    //    cout << ans_prob << " " << ans_wager << "\n";
    //    return max(0LL, ans_wager);
        return ans_wager;
    }
};


int wager(vector<int> scores, int wager1, int wager2)  {
    a_scores.PB(scores[1]);
    a_scores.PB(scores[2]);
    a_scores.PB(scores[0]);
//    wagers.PB(0);
    wagers.PB(wager1);
    wagers.PB(wager2);

    ans_prob = 0;
    ans_wager = 100000000000000000LL;

    func(0);

    if(ans_wager == 100000000000000000LL)    {
        return 0;
    }
//    cout << ans_prob << " " << ans_wager << "\n";
//    return max(0LL, ans_wager);
    return ans_wager;
}

int main()  {
//    freopen("input0.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    vector<int> scores;
    FOR(i, 0, 2)   {
        int tmp;cin >> tmp;
        scores.PB(tmp);
    }
    int wager1, wager2;
    cin >> wager1 >> wager2;
    cout << wager(scores, wager1, wager2) << "\n";
    return 0;
}
/**
429 23 238
23 214

2983 2348 3849
492
952

100 100 100
25
75

10 50 60
30
41

10 50 60
31
41
*/
