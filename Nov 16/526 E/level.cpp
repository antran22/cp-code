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
int a[maxn * 2 + 1], nx[maxn * 2 + 1];
ll sum[maxn * 2] = {};
void FI(int &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(;(c < 48 or c > 57) && c != '-';c = getchar());
    if (c == '-') neg = 1, c = getchar();
    for(; c > 47 && c < 58;c = getchar()) x = (x<<1) + (x<<3) + c - 48;
    if(neg) x = -x;
}
void FI(ll &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(;(c < 48 or c > 57) && c != '-';c = getchar());
    if (c == '-') neg = 1, c = getchar();
    for(; c > 47 && c < 58;c = getchar()) x = (x<<1) + (x<<3) + c - 48;
    if(neg) x = -x;
}
void input ()
{
	// cin >> n >> m;
	FI (n), FI (m);
	for (int i = 1; i <= n; ++i) FI (k), a[i] = a[i + n] = k;
	for (int i = 1; i <= 2 * n; ++i) sum[i] = sum[i - 1] + a[i];
}
void calc_next (int k)
{
	for (int i = 1, j = 0; i <= n * 2; ++i)
	{
		while (j <= 2 * n and sum[j + 1] - sum[i - 1] <= k) ++j;
		nx[i] = j;
	}
}
int walk (ll s)
{
	int t = s + n - 1, i = s, res = 0;
	while (i <= t)
	{
		// cerr << i << ' ';
		i = nx [i] + 1;
		res ++;
	}
	return res;
}
void solve ()
{
	ll k;
	FI (k);
	calc_next (k);
	int g = inf, x, h = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (g > nx[i] - i) g = nx[i] - i, h = a[i], x = i;
		else if (a[i] > h) h = a[i], x = i;
	}
	int res = inf;
	// cerr << x << ' ' << nx[x] << '\n';6
	for (int i = x; i <= nx[x] + 1; ++i) res = min (res, walk (i));
	cout << res << '\n';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("level.inp", "r", stdin);
	freopen ("level.out", "w", stdout);
	input ();
	for (int i = 1; i <= m; ++i)
		solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}