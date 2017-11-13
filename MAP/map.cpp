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
int n, k, m, w, h, x, y;
coord dif [4] = {mp (0, 1), mp (0, -1), mp (1, 0), mp (-1, 0)};
char difc [4] = {'^', 'v', '>', '<'};
bool adj[300][300][4] = {};
bool &g_a (coord p, int d)
{
	return adj[p.y][p.x][d];
}
coord operator + (coord a, coord b)
{
	return mp (a.x + b.x, a.y + b.y);
}
vector <coord> p;
void mark_adj (coord p, coord q)
{
	for (int i = 0; i < 4; ++i)
		if (p + dif[i] == q)
		{
			g_a (p, i) = 1;
			return;
		}
}
bool color [201][201];
void make_h_edge (int x1, int x2, int y)
{
	for (int i = x1 + 1; i <= x2; ++i)
	{
		coord p = mp (i, y + 1), q = mp (i, y);
		mark_adj (p, q), mark_adj (q, p);
	}
}
void make_v_edge (int x, int y1, int y2)
{
	for (int i = y1 + 1; i <= y2; ++i)
	{
		coord p = mp (x + 1, i), q = mp (x, i);
		mark_adj (p, q), mark_adj (q, p);
	}
}
void make_edge (coord a, coord b)
{
	int x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
	if (x1 > x2) swap (x1, x2);
	if (y1 > y2) swap (y1, y2);
	if (x1 == x2) make_v_edge (x1, y1, y2);
	if (y1 == y2) make_h_edge (x1, x2, y1);
}
void input ()
{
	cin >> n >> w >> h;
	for (int i = 1; i <= n; ++i)
		cin >> x >> y, p.pb (mp (x, y));
	p.pb (p[0]);
	for (int i = 1; i <= n; ++i)
		make_edge (p[i], p[i - 1]);
}
void debug ()
{
	for (int i = h; i >= 1; --i)
	{
		for (int j = 1; j <= w; ++j)
		{
			for (int d = 0; d < 4; ++d)
			{
				if (adj[i][j][d]) cout << difc[d];
				else cout << '_';
			}
			cout << ' ';
		}
		cout << '\n';
	}
}
bool in_range (coord p)
{
	return 0 <= p.x and p.x <= w + 1 and 0 <= p.y and p.y <= h + 1;
}
bool visited[300][300];
bool &g_v (coord p)
{
	return visited[p.y][p.x];
}
void dfs (coord g)
{
	g_v (g) = 1;
	for (int i = 0; i < 4; ++i)
	{
		coord h = g + dif[i];
		if (g_v (h) or !in_range (h) or g_a (g, i)) continue;
		dfs (h);
	}
}
void solve ()
{
	// debug ();
	dfs (mp (0, 0));
	for (int i = h; i >= 1; --i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (visited[i][j]) cout << '.';
			else cout << '#';
		}
		cout << '\n';
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
	freopen ("map.inp", "r", stdin);
	freopen ("map.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}