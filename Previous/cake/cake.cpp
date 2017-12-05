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
typedef pair<int,int> coord;
#define x first
#define y second

//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
coord d[4] = {mp (0, 1), mp (0, -1), mp (1, 0), mp (-1, 0)};
char cdir [4] = {'^', 'v', '>', '<'};
coord operator + (coord a, coord b)
{
	return mp (a.x + b.x, a.y + b.y);
}
struct solution
{
	bool adj[300][300][4] = {};
	void mark_edge (coord a, coord b)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (a + d[i] == b)
				adj[a.y][a.x][i] = 1;
		}
	}
	void make_v_line (int x, int y1, int y2)
	{
		for (int i = y1; i < y2; ++i)
		{
			coord a = mp (x, i), b = mp (x - 1, i);
			mark_edge (a, b), mark_edge (b, a);
		}
	}
	void make_h_line (int x1, int x2, int y)
	{
		for (int i = x1; i < x2; ++i)
		{
			coord a = mp (i, y), b = mp (i, y - 1);
			mark_edge (a, b), mark_edge (b, a);
		}
	}
	int x1[100] = {}, y1[100] = {}, x2[100] = {}, y2[100] = {};
	void input ()
	{
		cin >> m >> n >> k;
		if (m == 0 and n == 0) exit (0);
		vi xx (1, 0), yy (1, 0);
		for (int i = 1; i <= k; ++i)
		{
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			xx.pb (x1[i]);
			xx.pb (x2[i]);
			yy.pb (y1[i]);
			yy.pb (y2[i]);
		}
		xx.pb (n);
		yy.pb (m);
		xx.resize (distance (xx.begin (), unique (whole (xx))));
		yy.resize (distance (yy.begin (), unique (whole (yy))));
		sort (whole (xx));
		sort (whole (yy));
		for (int i : yy) cerr << ":::" << i << ' ';
		n = lower_bound (whole (xx), n) - xx.begin ();
		m = lower_bound (whole (yy), m) - yy.begin ();
		cerr << n << ' ' << m << '\n';
		for (int i = 1; i <= k; ++i)
		{
			x1[i] = lower_bound (whole (xx), x1[i]) + 1 - xx.begin ();
			x2[i] = lower_bound (whole (xx), x2[i]) + 1 - xx.begin ();
			y1[i] = lower_bound (whole (yy), y1[i]) + 1 - yy.begin ();
			y2[i] = lower_bound (whole (yy), y2[i]) + 1 - yy.begin ();
			if (x1[i] > x2[i]) swap (x1[i], x2[i]);
			if (y1[i] > y2[i]) swap (y1[i], y2[i]);
			make_h_line (x1[i], x2[i], y1[i]);
			make_h_line (x1[i], x2[i], y2[i]);
			make_v_line (x1[i], y1[i], y2[i]);
			make_v_line (x2[i], y1[i], y2[i]);
		}
	}
	bool visited[300][300] = {};
	bool &gv (coord x)
	{
		return visited[x.y][x.x];
	}
	bool in_range (coord c)
	{
		int x = c.x, y = c.y;
		return 1 <= x and x <= n and 1 <= y and y <= m;
	}
	void dfs (coord g)
	{
		gv (g) = 1;
		for (int i = 0; i < 4; ++i)
		{
			coord h = g + d[i];
			if (gv (h) or !in_range (h) or adj[g.y][g.x][i]) continue;
			dfs (h);
		}
	}
	int res = 0;
	void debug ()
	{
		for (int i = m; i >= 1; --i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int x = 0; x < 4; ++x)
				{
					if (adj[i][j][x]) cerr << cdir[x];
					else cerr << '_';
				}
				cerr << ' ';
			}
			cerr << '\n';
		}
		cerr << '\n';
	}
	void solve ()
	{
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (!visited[i][j]) ++res, dfs (mp (j, i));
		cout << res << '\n';
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
	freopen ("cake.inp", "r", stdin);
	freopen ("cake.out", "w", stdout);

	while (true)
	{
		solution g;
		g.input ();
		g.debug ();
		g.solve ();
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}