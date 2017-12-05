//code.cpp
#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int ceildiv (int a, int b)
{
	return (a + b - 1) / b;
}
int n, k, m;
int w1, w2, h1, h2, res = 0;
void input ()
{
	cin >> w1 >> w2 >> h1 >> h2;
}
bool check (int k)
{
	int x = ceildiv (w1, k), y = w2 / k;
	int z = ceildiv (h1, k), t = h2 / k;
	return (x <= y and z <= t);
}
void solve ()
{
	res = 0;
	int s = sqrt (max (w2, h2));
	s = min (s, w2);
	s = min (s, h2);
	for (int i = 1; i <= s; ++i)
	{
		if (check (i)) res = max (i, res);
		if (check (w2 / i)) res = max (w2 / i, res);
		if (check (h2 / i)) res = max (h2 / i, res);
	}
	cout << res << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("teacareer.inp", "r", stdin);
	freopen ("teacareer.out", "w", stdout);
	int t;
	for (cin >> t; t; --t)
	{
		input ();
		solve ();
	}
}