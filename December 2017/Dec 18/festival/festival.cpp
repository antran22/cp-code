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
typedef pair <int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e5 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m, q;
vi fest;
vpii xadj[maxn];
set <pii> adj[maxn];
bool check[maxn];
int dist[maxn];
struct cmp
{
	bool operator () (const pii &a, const pii &b)
	{
		return a.sd > b.sd;
	}
};
typedef priority_queue <pii,vector <pii>,cmp> minheap;
void dijkstra ()
{
	minheap pq;
	fill (dist, dist + maxn, inf);
	dist[n + 1] = 0;
	pq.push (mp (n + 1, 0));
	while (pq.size ())
	{
		pii a = pq.top ();
		pq.pop ();
		if (a.sd != dist[a.ft]) continue;
		for (pii b : adj[a.ft])
		{
			if (dist[b.ft] > b.sd + a.sd)
			{
				dist[b.ft] = b.sd + a.sd;
				pq.push (mp (b.ft, b.sd + a.sd));
			}
		}
	}
	// for (int i = 1; i <= n + 1; ++i) if (!check[i]) cout << dist[i] << ' ';
}
vi uncheck;
int p[20][maxn], min_edge[20][maxn];
struct tree
{
	map <pii, int> xedge;
	vector <pair <int, pii>> edge;
	vpii adj[maxn];
	void add_edge (int x, int y, int w)
	{
		if (x > y) swap (x, y);
		int newx = lower_bound (whole (uncheck), x) - uncheck.begin () + 1;
		int newy = lower_bound (whole (uncheck), y) - uncheck.begin () + 1;
		xedge.ins (mp (mp (newx, newy), w));
	}
	int lab[maxn];
	int root (int i)
	{
		return lab[i] < 0 ? i : lab[i] = root (lab[i]);
	}
	bool union (int a, int b)
	{
		int ra = root (a), rb = root (b);
		if (ra == rb) return 0;
		if (lab[ra] > lab[rb]) swap (ra, rb);
		lab[ra] += lab[rb];
		lab[rb] = ra;
		return 1;
	}
	void kruskal ()
	{
		fill (lab, lab + maxn, -1);
		for (auto g : xedge)
		{
			edge.pb (mp (g.sd, g.ft));
		}
		sort (whole (edge), [] (pair <int, pii> a, pair <int, pii> b)
		{
			return a.ft > b.ft;
		});
		for (auto g : edge)
		{
			if (union (g.sd.ft, g.sd.sd)) 
			{
				adj[g.sd.ft].pb (mp (g.sd.sd, g.ft));
				adj[g.sd.sd].pb (mp (g.sd.ft, g.ft));
			}
		}
		p[0][1] = 1;
		dfs (1);
	}
	int he[maxn];
	void dfs (int i)
	{
		for (pii j : adj[i])
		{
			if (j.ft == p[0][i]) continue;
			he[j.ft] 
			p[0][j.ft] = i;
			min_edge[0][j.ft] = j.sd;
			for (int h = 1; h < 20; ++i)
			{
				p[h][j.ft] = p[h - 1][p[h - 1][j.ft]];
				min_edge[h][j.ft] = min (min_edge[h - 1][j.ft], min_edge[h - 1][p[h - 1][j.ft]]);
			}
		}
	}
	int min_path (int u, int v)
	{
		for (int h = 0; h <)
	}
};
tree tr;
void input ()
{
	cin >> n >> m >> k >> q;
	int u, v, w;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		xadj[u].pb (mp (v, w));
		xadj[v].pb (mp (u, w));
	}
	fest.resize (k);
	for (int &i : fest)
	{
		cin >> i;
		check [i] = 1;
	}
	for (int i : fest)
	{
		for (pii j : xadj[i])
		{
			if (!check[j.ft]) adj[n + 1].ins (j), adj[j.ft].ins (mp (n + 1, j.sd));
		}
	}
	for (int i = 1; i <= n + 1; ++i)
	{
		if (!check[i])
		{
			for (pii j : xadj[i])
			{
				if (!check[j.ft])
				adj[i].ins (j);
				adj[j.ft].ins (mp (i, j.sd));
			}
			uncheck.pb (i);
		}
	}
	dijkstra ();
	uncheck.pb (n + 1);
}
void solve ()
{
	for (int i : uncheck)
	{
		for (auto j : adj[i])
		{
			tr.add_edge (i, j.ft, min (dist[i], dist[j.ft]));
		}
	}
	tr.kruskal ();
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("festival.inp", "r", stdin);
	freopen ("festival.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}