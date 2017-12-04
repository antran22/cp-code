#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
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
int a[maxn];
ll f[maxn] = {};
void input ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], f[i] = f[i - 1] + a[i];
}
void solve ()
{
	ll res = inff;
	for (int i = 1; i <= n; ++i)
	{
		ll cnt = 0;
		for (int j = 1; j <= i - k + 1; ++j)
		{
			cnt = max (f[j + k - 1] - f[j - 1], cnt);
		}
		for (int j = i + k; j <= n - k + 1; ++j)
		{
			cnt = max (f[j + k - 1] - f[j - 1], cnt);
		}
		res = min (res, cnt);
	}
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
	freopen ("gift.inp", "r", stdin);
	freopen ("gift.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}