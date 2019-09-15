
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

/**
Draw the line segments between the center of the inner circle and the centers of two adjacent outer circles.
These three line segments form a triangle. If the inner radius is r and the outer radius is R,
then the sides of the triangle are r + R, r + R, and 2R.
We also know that the angle of the triangle at the center of the inner circle is (2 * pi) / n.
From law of cosines,
  a^2 = b^2 + c^2 - 2bc*cosA
  (2R)^2 = (r+R)^2 + (r+R)^2 - 2(r+R)(r+R)*cosA
  (2R)^2 = 2(r+R)^2 - 2(r+R)^2*cosA
  (2R)^2 = 2(r+R)^2(1-cosA)
  (2R)^2 = 2(r+R)^2 * 2sin^2(A/2)
  (2R)^2 = 2(r+R)^2 * 2sin^2(A/2)
  R^2 = (r+R)^2 * sin^2(A/2)
  R^2/(r+R)^2 = sin^2(A/2)
  R/(r+R) = sin(A/2) ...... (1)
  R = r*sin(A/2) + R*sin(A/2)
  R(1-sin(A/2)) = r * sin(A/2)
  R = (r*sin(A/2))/(1-sin(A/2))
  R = (r*sin(pi/n))/(1-sin(pi/n))
  As, A = 2*pi/n

Another method,
If we divide A by half (a = A/2 = pi/n) it creates a right triangle and using sina = opposite/hypotenus
  sina = R/(r+R)
  sin(A/2) = R/(r+R), which is equivalent to (1)
*/

int main()  {
//    freopen("input.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    double n, r;
    cin >> n >> r;
    cout << fixed << setprecision(9) << (r * sin(pi / n)) / (1 - sin(pi / n));
    return 0;
}
/**
*/

