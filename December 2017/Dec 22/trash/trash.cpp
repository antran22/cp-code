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
struct vec;
typedef vec point;
struct vec
{
	ll x, y;
	vec () {}
	vec (point a, point b)
	{
		x = b.x - a.x, y = b.y - a.y;
	}
	ll operator ^ (vec v)
	{
		return x * v.y - y * v.x;
	}
	ld dist ()
	{
		return sqrt (x * x + y * y);
	}
};
point a[maxn], piv;
bool ccw (point g, point h, point k)
{
	return (vec (g, h) ^ vec (g, k)) > 0;
}
vector <point> hull;
void convex_hull ()
{
	sort (a + 1, a + n + 1, [] (point p, point q)
	{
		return p.x < q.x;
	});
	piv = a[1];
	sort (a + 1, a + n + 1, [] (point p, point q)
	{
		return ccw (piv, p, q);
	});
	hull.clear ();
	// for (int i = 1; i <= n; ++i) cout << a[i].x << ' ' << a[i].y << '\n';
	for (int i = 1; i <= n; ++i)
	{
		while (hull.size () >= 2)
		{
			int g = hull.size ();
			point p = hull[g - 2], q = hull[g - 1];
			if (!ccw (p, q, a[i])) hull.pop_back ();
			else break;
		}
		hull.pb (a[i]);
	}
	for (point x : hull) cerr << x.x << ' ' << x.y << '\n';
	cerr << '\n';
}
ll area (point a, point b, point c)
{
	return abs (vec (a, b) ^ vec (a, c));
}
int test_case = 0;
void input ()
{
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i].x >> a[i].y;
	}
	convex_hull ();
}
void solve ()
{
	n = hull.size ();
	hull.pb (hull[0]);
	ld res = inff;
	for (int i = 1; i <= n; ++i)
	{
		ll max_area = 0;
		ld dist = vec (hull[i], hull[i - 1]).dist ();
		int jj;
		for (int j = 0; j <= n; ++j)
		{
			max_area = max (max_area, area (hull[i], hull[i - 1], hull[j]));
		}
		res = min (max_area / dist, res);
	}
	cout << "Case " << test_case << ": " << fixed << setprecision (2) << res << '\n';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("trash.inp", "r", stdin);
	freopen ("trash.out", "w", stdout);
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		++test_case;
		input ();
		solve ();
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}