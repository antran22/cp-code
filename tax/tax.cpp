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
typedef pair<int,ll> edge;
#define v first
#define w second

//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
int in_id[maxn], out_id[maxn], cnt = 0;
vector <edge> adj[maxn], nadj[maxn];
void make_self_edge (int v, int w)
{
	int i = in_id[v], o = out_id[v];
	cerr << i << ' ' << o << ' ' << w << '\n';
	nadj[i].pb (mp (o, w));
}
void edge_graph (int i)
{
	vector <edge> &x = adj[i];
	sort (whole (x), [] (edge p, edge q)
	{
		return p.w < q.w;
	});
	for (int j = 1; j < x.size (); ++j)
	{
		edge p = x[j - 1], q = x[j];
		nadj[out_id[p.v]].pb (mp (out_id[q.v], q.w - p.w));
		nadj[out_id[q.v]].pb (mp (out_id[p.v], 0));
	}
}
void assign_id (int i)
{
	in_id [i] = i;
	out_id [i] = i + m + 2;
}
int w[maxn];
void input ()
{
	cin >> n >> m;
	int u, v;
	assign_id (0);
	assign_id (m + 1);
	for (int i = 1; i <= m; ++i)
		cin >> u >> v >> w[i], adj[u].pb (mp (i, w[i])), adj[v].pb (mp (i, w[i])), assign_id (i);
	for (int i = 0; i <= m + 1; ++i) make_self_edge (i, w[i]);
	adj[1].pb (mp (0, 0));
	adj[n].pb (mp (m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		edge_graph (i);
	}
}
struct cmp
{
	bool operator () (const edge &a, const edge &b)
	{
		return a.w > b.w;
	}
};
typedef priority_queue <edge,vector <edge>,cmp> minheap;
vector <ll> dist (maxn, inff);
void solve ()
{
	minheap pq;
	dist[0] = 0;
	pq.push (mp (0, 0));
	while (pq.size ())
	{
		edge x = pq.top ();
		pq.pop ();
		if (dist[x.v] != x.w) continue;
		for (edge g : nadj[x.v])
		{
			if (dist[g.v] > g.w + x.w)
				dist[g.v] = g.w + x.w,
				pq.push (mp (g.v, dist[g.v]));
		}
	}
	// for (int i = 0; i <= 2 * m + 1; ++i) cout << dist[i] << ' ';
	cout << dist[out_id[m + 1]];
	for (int i = 0; i <= m + 1; ++i)
	{
		cout << i << "::::\nin:\n" << in_id[i] << '\n';
		for (auto x : nadj[in_id[i]]) cout << x.v << ' ' << x.w << '\n';
		cout << "\nout:\n" << out_id[i] << '\n';
		for (auto x : nadj[out_id[i]]) cout << x.v << ' ' << x.w << '\n';
		cout << '\n';
	}

}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	freopen ("tax.inp", "r", stdin);
	freopen ("tax.out", "w", stdout);
	cin.tie (NULL);
	cout.tie (NULL);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}