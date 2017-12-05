//code.cpp
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
const int inf = 1e9, maxn = 1e6 + 1, maxn2 = 65540;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
struct fenwick_tree
{
	vi f = vi (maxn2, 0);
	void update (int i, int d)
	{
		for (; i < maxn2; i += i & (-i)) f[i] += d;
	}
	int query (int i)
	{
		int res = 0;
		for (; i > 0; i &= (i - 1)) res += f[i];
		return res;
	}
	int find (int k)
	{
		int low = 1, high = maxn2 - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (query (mid) >= k) high = mid - 1;
			else low = mid + 1;
		}
		return low;
	}
};
struct solution
{
	int n, k, m;
	int seed, add, mod = 65536;
	ll mul;
	vi a = vi (maxn, 0);
	void input ()
	{
		cin >> seed >> mul >> add >> n >> k;
		gen_array ();
	}
	void gen_array ()
	{
		a[1] = seed;
		for (int i = 2; i <= n; ++i)
			a[i] = (a[i - 1] * mul + add) % mod;
		for (int i = 1; i <= n; ++i) ++a[i];
	}
	fenwick_tree t;
	ll res = 0;
	void solve ()
	{
		for (int i = 1; i <= k; ++i)
			t.update (a[i], 1);
		res = t.find ((k + 1) / 2) - 1;
		for (int i = 1, j = k + 1; j <= n; ++j, ++i)
		{
			t.update (a[j], 1);
			t.update (a[i], -1);
			int g = t.find ((k + 1) / 2) - 1;
			res += g;
		}
		// cout << res << '\n';
	}
};
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("median.inp", "r", stdin);
	freopen ("median.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		solution x;
		x.input ();
		x.solve ();
		cout << "Case #" << i << ": " << x.res << '\n';
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}