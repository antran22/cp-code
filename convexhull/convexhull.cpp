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
struct vec
{
	ll x, y;
	vec () {}
	vec (ll aa, ll bb)
	{
		x = aa, y = bb;
	}
	vec (vec p, vec q)
	{
		x = q.x - p.x;
		y = q.y - p.y;
	}
	ll operator ^ (vec p)
	{
		return x * p.y - y * p.x;
	}
	bool operator == (vec p)
	{
		return x == p.x and y == p.y;
	}
};
typedef vec point;
point piv;
point a[maxn];
ll tri_area (point a, point b, point c)
{
	return (vec (a, b) ^ vec (a, c));
}
bool counter_clockwise (point a, point b, point c)
{
	return (tri_area (a, b, c)) > 0;
}
bool clockwise (point a, point b, point c)
{
	return (tri_area (a, b, c)) <= 0;
}
void input ()
{
	cin >> n;
	piv = point (inf, inf);
	for (int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	sort (a + 1, a + n + 1, [] (point a, point b)
		{
			if (a.y == b.y) return a.x < b.x;
			return a.y < b.y;
		});
	piv = a[1];
	// cerr << piv.x << ' ' << piv.y << '\n';
}
vector <point> hull;
string NAME = "convexhull";
void solve ()
{
	sort (a + 2, a + n + 1, [] (point a, point b)
	{
		return counter_clockwise (piv, a, b);
	});
	a[++n] = a[1];
	/*ofstream test((NAME+ ".check").c_str());
	for (int i = 1; i <= n; ++i) test << a[i].x << ' ' << a[i].y << '\n';
	test.close ();*/
	for (int i = 1; i <= n; ++i)
	{
		for (int h = hull.size (); h >= 2 and clockwise (hull[h - 2], hull[h - 1], a[i]); --h) hull.pop_back ();
		hull.push_back (a[i]);
	}
	ll area = 0;
	for (int i = 1; i < hull.size (); ++i) area += tri_area (piv, hull[i - 1], hull[i]);
	cout << hull.size () - 1 << '\n';
	cout << area / 2 << (area % 2 ? ".5\n" : ".0\n");
	for (int i = 0; i < hull.size () - 1; ++i) cout << hull[i].x << ' ' << hull[i].y << '\n';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("convexhull.inp", "r", stdin);
	freopen ("convexhull.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}