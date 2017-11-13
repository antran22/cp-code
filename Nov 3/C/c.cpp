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
struct tab
{
	ll c[51][51] = {};
	void init ()
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j < i; ++j)
				c[i][j] = c[j][i] = inff;
	}
	tab operator * (tab x)
	{
		tab res;
		res.init ();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int p = 1; p <= n; ++p)
					res.c[i][j] = min (res.c[i][j], c[i][p] + x.c[p][j]);
		return res;
	}
	void print ()
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (c[i][j] == inff) cout << "oo ";
				else cout << c[i][j] << ' ';
			}
			cout << '\n';
		}
	}
} in, f1;
struct edge
{
	int u, v;
	ll w;
	edge () {}
	edge (int uu, int vv, ll ww)
	{
		u = uu, v = vv, w = ww;
	}
};
vector <edge> ve;
void input ()
{
	cin >> n >> m;
	in.init ();
	int u, v; ll w;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		in.c[u][v] = min (in.c[u][v], w);
		ve.pb (edge (u, v, w));
	}
	cin >> k;
}
void floyd_warshal ()
{
	for (int p = 1; p <= n; ++p)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				in.c[i][j] = min (in.c[i][j], in.c[i][p] + in.c[p][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f1.c[i][j] = in.c[i][j];
	for (edge g : ve)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f1.c[i][j] = min (f1.c[i][j], in.c[i][g.u] + in.c[g.v][j] - g.w);
}
tab mat_pow (tab x, int i)
{
	if (i == 1) return x;
	tab h = mat_pow (x, i / 2);
	h = h * h;
	if (i % 2) h = h * x;
	return h;
}
void solve ()
{
	floyd_warshal ();
	tab x = mat_pow (f1, k);
	// x.print ();
	cout << x.c[1][n];
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("c.inp", "r", stdin);
	freopen ("c.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}