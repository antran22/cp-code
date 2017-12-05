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
const ld eps = 1e-9;
int n, k, m;
int a[3][maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 2; ++j)
			cin >> a[j][i];
	for (int j = 1; j <= 2; ++j)
		sort (a[j] + 1, a[j] + n + 1);
}
ll check (int id, int c)
{
	// cerr << id << ":::";
	vi g;
	for (int i = 1, t = 0; i <= n; ++t)
	{
		for (int j = 1; j <= c; ++i, ++j)
			g.pb (a[id][i] - t);
	}
	sort (whole (g));
	// for (int i : g) cerr << i << ' ';
	// cout << '\n';
	int m;
	if (n % 2) m = g[n/2];
	else m = (g[n/2] + g[n/2-1]) / 2;
	ll res = 0;
	for (int i : g) res += abs (i - m);
	cerr << '\n';
	return res;
}
ll res = inff;
void solve ()
{
	int s = sqrt (n);
	for (int i = 1; i <= s; ++i)
		if (n % i == 0)
			res = min (res, check (1, i) + check (2, n / i)),
			res = min (res, check (1, n / i) + check (2, i));
	cout << res;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("queue.inp", "r", stdin);
	freopen ("queue.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}