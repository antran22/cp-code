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
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct ajc
{
	int v, w;
	ajc () {}
	ajc (int vv, int ww)
	{
		v = vv;
		w = ww;
	}
};
vector <ajc> adj[maxn];
void input ()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb (ajc (v, w));
		adj[v].pb (ajc (u, w));
	}
}
ld d[maxn][11] = {};
struct path
{
	int v, k;
	ld w;
	path () {}
	path (int vv, int kk, ld ww)
	{
		v = vv;
		k = kk;
		w = ww;
	}
};
struct cmp
{
	bool operator () (const path &a, const path &b)
	{
		return a.w > b.w;
	}
};
typedef priority_queue <path,vector <path>,cmp> minheap;
void solve ()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			d[i][j] = inff;
	d[1][0] = 0;
	minheap pq;
	pq.push (path (1, 0, 0));
	while (pq.size ())
	{
		path x = pq.top ();
		pq.pop ();
		int u = x.v, i = x.k;
		if (d[u][i] != x.w) continue;
		for (ajc e : adj[u])
		{
			int v = e.v;
			ld w = e.w;
			for (int j = i; j <= k; ++j, w /= 2)
			{
				ld nw = d[u][i] + w;
				if (d[v][j] > nw)
					d[v][j] = nw,
					pq.push (path (v, j, nw));
			}
		}
	}
	cout << fixed << setprecision (2) << *min_element (d[n], d[n] + k + 1);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	// ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("netaccel.inp", "r", stdin);
	freopen ("netaccel.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}