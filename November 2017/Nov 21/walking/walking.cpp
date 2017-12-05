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
int n, k, m;
int t[maxn], v[maxn], l, x[maxn], y[maxn];
double f_time (int i)
{
	return t[i] + double (l) / v[i];
}
int pos[maxn];
void input ()
{
	cin >> l >> n;
	for (int i = 1; i <= n; ++i) cin >> t[i] >> v[i], x[i] = i, y[i] = i;
	sort (x + 1, x + n + 1, [] (int i, int j)
	{
		return t[i] < t[j];
	});
	sort (y + 1, y + n + 1, [] (int i, int j)
	{
		return f_time (i) < f_time (j);
	});
	for (int i = 1; i <= n; ++i) pos[x[i]] = i;
	for (int i = 1; i <= n; ++i) y[i] = pos[y[i]];
}
int d[maxn] = {}, ml = 0;
void solve ()
{
	for (int i = 1; i <= n; ++i)
	{
		int k = lower_bound (d + 1, d + ml + 1, y[i]) - d;
		d[k] = y[i];
		ml = max (ml, k);
	}
	cout << ml;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("walking.inp", "r", stdin);
	freopen ("walking.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}
