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
struct point
{
	ld x, y;
	point () {}
	point (ld xx, ld yy)
	{
		x = xx, y = yy;
	}
	bool operator == (point p)
	{
		return x == p.x and y == p.y;
	}
};
ld dist (point a, point b)
{
	ld dx = b.x - a.x;
	ld dy = b.y - a.y;
	return sqrt (dx * dx + dy * dy);
}
point p[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].x >> p[i].y;
	sort (p + 1, p + n + 1, [] (point a, point b)
	{
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	for (int i = 1; i <= n; ++i)
		if (p[i] == p[i - 1])
		{
			cout << "0.000";
			exit (0);
		}
}
point x[maxn];
int sz = 0;
ld min_dist (int l, int r)
{
	if (l == r) return inf;
	if (l + 1 == r) return dist (p[l], p[r]);
	int mid = (l + r) / 2;
	ld d = min (min_dist (l, mid), min_dist (mid + 1, r));
	int oldsize = sz + 1;
	for (int i = mid; i >= l and p[mid].x - p[i].x < d; --i) x[++sz] = p[i];
	for (int i = mid + 1; i <= r and p[i].x - p[mid].x < d; ++i) x[++sz] = p[i];
	sort (x + oldsize, x + sz + 1, [] (point p, point q)
		{
			return p.y < q.y;
		});
	for (int i = oldsize; i <= sz; ++i)
		for (int j = i + 1; j <= sz and x[j].y - x[i].y < d; ++j)
			// cerr << x[i].x << ' ' << x[i].y << ' ' << x[j].x << ' ' << x[j].y << '\n',
			d = min (d, dist (x[i], x[j]));
	return d;
}
void solve ()
{
	cout << fixed << setprecision (3) << min_dist (1, n);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("nearest.inp", "r", stdin);
	freopen ("nearest.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}