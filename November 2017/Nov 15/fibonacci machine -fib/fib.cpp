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
const int inf = 1e9, maxn = 1e5 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
int mod = 1e9 + 7;
struct mat
{
	ll a[2][2] = {};
	mat () {}
	mat (vi x)
	{
		int cnt = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				a[i][j] = x[cnt++];
	}
	mat operator * (mat x)
	{
		mat res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int p = 0; p < 2; ++p)
					res.a[i][j] = ((res.a[i][j]) + (((ll) a[i][p]) * x.a[p][j]) % mod) % mod;
		return res;
	}
	mat operator + (mat x)
	{
		mat res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				res.a[i][j] = (a[i][j] + x.a[i][j]) % mod;
		return res;
	}
};
mat mat_pow (mat a, int p)
{
	if (p == 0) return mat ({1, 0, 0, 1});
	mat x = mat_pow (a, p / 2);
	x = x * x;
	if (p % 2) x = x * a;
	return x;
}
struct node
{
	mat sum;
	int lazy, val = 0;
} t[4 * maxn];
void build (int i, int l, int r)
{
	if (l == r)
	{
		t[i].sum = mat ({0, 1, 1, -1});
		return;
	}
	int mid = (l + r) / 2;
	build (i * 2, l, mid);
	build (i * 2 + 1, mid + 1, r);
	t[i].sum = t[i * 2].sum + t[i * 2 + 1].sum;
}
int p, q;
mat trans = mat ({1, 1, 1, 0});
void pass (int i)
{
	int l = t[i].lazy;
	if (l == 0) return;
	mat g = mat_pow (trans, l);
	t[i * 2].sum = t[i * 2].sum * g;
	t[i * 2 + 1].sum = t[i * 2 + 1].sum * g;
	t[i * 2].lazy = l;
	t[i * 2 + 1].lazy = l;
	t[i].lazy = 0;
}
void update (int i, int l, int r)
{
	if (p > r or l > q) return;
	if (p <= l and r <= q)
	{
		t[i].sum = t[i].sum * trans;
		t[i].lazy ++;
		return;
	}
	pass (i);
	int mid = (l + r) / 2;
	update (i * 2, l, mid);
	update (i * 2 + 1, mid + 1, r);
	t[i].sum = t[i * 2].sum + t[i * 2 + 1].sum;
}
ll query (int i, int l, int r)
{
	if (p > r or l > q) return 0;
	if (p <= l and r <= q)
	return t[i].sum.a[0][0];
	pass (i);
	int mid = (l + r) / 2;
	return (query (i * 2, l, mid) + query (i * 2 + 1, mid + 1, r)) % mod;
}
void input ()
{
	cin >> n >> m;
	build (1, 1, n);
}
void tree_update (int l, int r)
{
	p = l, q = r;
	update (1, 1, n);
}
ll tree_query (int l, int r)
{
	p = l, q = r;
	return query (1, 1, n);
}
void solve ()
{
	for (int i = 1; i <= m; ++i)
	{
		char c;
		cin >> c >> p >> q;
		if (c == 'D') update (1, 1, n);
		if (c == 'S') cout << query (1, 1, n) << '\n';
	}
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("fib.inp", "r", stdin);
	freopen ("fib.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}