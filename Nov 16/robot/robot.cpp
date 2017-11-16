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
bool c[1001][1001];
int d[2][1001][1001];
struct coord
{
	int x, y;
	coord () {}
	coord (int xx, int yy)
	{
		x = xx, y = yy;
	}
	void operator = (coord c)
	{
		x = c.x;
		y = c.y;
	}
	coord operator + (coord c)
	{
		return coord (x + c.x, y + c.y);
	}
}s, t;
bool &gc (coord a)
{
	return c[a.x][a.y];
}
int &dist (coord a, bool i)
{
	return d[i][a.x][a.y];
}
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> c[i][j];
	int x, y;
	cin >> x >> y; s = coord (x,y);
	cin >> x >> y; t = coord (x,y);
}
struct node
{
	coord p;
	bool skip;
	int w, ldir;
	node () {}
	node (coord pp, bool ss, int ww, int dd)
	{
		p = pp, skip = ss, w = ww, ldir = dd;
	}
};
coord dir [4] = {coord (0, 1), coord (0, -1), coord (1, 0), coord (-1, 0)};
// opposite dir = dir ^ 1;
struct cmp
{
	bool operator () (const node &a, const node &b)
	{
		return a.w > b.w;
	}
};
typedef priority_queue <node,vector <node>,cmp> minheap;
void init ()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int p = 0; p < 2; ++p)
				d[p][i][j] = inf;
}
bool in_range (coord c)
{
	return c.x >= 1 and c.x <= n and c.y >= 1 and c.y <= n;
}
int cnt[1001][1001] = {};
int &gcnt (coord x)
{
	return cnt[x.x][x.y];
}
void dijkstra ()
{
	init ();
	minheap pq;
	dist (s, 0) = dist (s, 1) = 0;
	pq.push (node (s, 0, 0, 4));
	pq.push (node (s, 1, 0, 4));
	gcnt (s) = 1;
	while (pq.size ())
	{
		node t = pq.top ();
		pq.pop ();
		int ldir = t.ldir;
		if (dist (t.p, t.skip) != t.w) continue;
		// cerr << t.p.x << ' ' << t.p.y << ' ' << t.w << ":::\n";
		for (int i = 0; i < 4; ++i)
		{
			if (i == (ldir ^ 1)) continue;
			// cerr << i << ' ' << (ldir ^ 1) << '\n';
			int nw;
			if (i == ldir or ldir == 4) nw = t.w;
			else nw = t.w + 1;
			coord np = t.p + dir[i];
			if (!in_range (np))
			{
				// cerr << '\n';
				continue;
			}
			if (!gc (np))
			{
				if (!t.skip)
				{
					if (dist (np, 0) > nw)
					{
						dist (np, 0) = nw;
						pq.push (node (np, 0, nw, i));
					}
				}
				if (dist (np, 1) > nw)
				{
					dist (np, 1) = nw;
					if (t.skip) gcnt (np) = gcnt (t.p);
					pq.push (node (np, t.skip, nw, i));
				}
				else if (dist (np, 1) == nw)
					gcnt (np) += gcnt (t.p);
			}
			else
			{
				if (t.skip) continue;
				if (dist (np, 1) > nw)
				{
					dist (np, 1) = nw;
					gcnt (np) = gcnt (t.p);
					pq.push (node (np, 1, nw, i));
				}
				else if (dist (np, 1) == nw)
					gcnt (np) += gcnt (t.p);
			}
		}
	}
	coord x (5, 1);
	// cout << gcnt (x) << '\n';
	cout << dist (t, 0) << ' ' << dist (t, 1) << ' ' << gcnt (t);
}
void solve ()
{
	dijkstra ();
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("robot.inp", "r", stdin);
	freopen ("robot.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}