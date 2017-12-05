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
const int inf = INT_MAX - 10, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct coord {ll x, y;};
// ld cs = cos (pi * (0.25)), sn = cos (pi * (0.25)), h = 1 / sqrt (2);
coord rotate (coord a)
{
	ll nx = a.x + a.y, ny = a.x - a.y;
	return coord {nx, ny};
}
struct rec {ll x1; ll y1; ll x2; ll y2;};
rec r [maxn];
void input ()
{
	cin >> n;
	ll x, y;
	for (ll i = 1; i <= n; ++i)
	{
		ll x1 = inff, x2 = -inff, y1 = inff, y2 = -inff;
		for (ll j = 1; j <= 4; ++j)
		{
			cin >> x >> y;
			coord g = rotate (coord {x, y});
			x1 = min (x1, g.x);
			x2 = max (x2, g.x);
			y1 = min (y1, g.y);
			y2 = max (y2, g.y);
		}
		r[i] = (rec {x1, y1, x2, y2});
	}
}
rec intersect (rec a, rec b)
{
	ll
	x1 = max (a.x1, b.x1), x2 = min (a.x2, b.x2),
	y1 = max (a.y1, b.y1), y2 = min (a.y2, b.y2);
	return rec {x1, y1, x2, y2};
}
void solve ()
{
	rec gg {-inff, -inff, inff, inff};
	if (n == 0) 
	{
		cout << 0;
		return;
	}
	for (ll i = 1; i <= n; ++i)
	{
		gg = intersect (gg, r[i]);
	}
	ll mm = gg.x2 - gg.x1 - 1, nn = gg.y2 - gg.y1 - 1;
	// cerr << mm << ' ' << nn << '\n';
	if (nn <= 0 or mm <= 0) cout << 0;
	else
	{
	
		cout << (nn * mm) / 2;
		// cerr << nn << ' ' << mm << '\n';
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
	freopen ("pins.inp", "r", stdin);
	freopen ("pins.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}