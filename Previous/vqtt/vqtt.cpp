//code.cpp
#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x	.size())
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
int n, k, m, t;
ll f[5001][5001];
int a[maxn];
void input ()
{
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) cin >> a[i];
}
void solve ()
{
	for (int i = 1; i <= n; ++i)
		f[i][0] = -inff;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
		{
			ll g = f[i - 1][j] - t;
			if (g < 0 or i == n) g = -inff;
			ll h = f[i - 1][j - 1] + a[i];
			if (h < 0) h = -inff;
			f[i][j] = max (g, h);
		}
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (f[n][i] >= 0)
		{
			cout << i;
			return;
		}
	}
	cout << -1;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("vqtt.inp", "r", stdin);
	freopen ("vqtt.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}