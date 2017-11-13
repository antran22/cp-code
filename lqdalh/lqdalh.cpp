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
struct vec
{
	ld x, y;
	vec () {}
	vec (ld xx, ld yy)
	{
		x = xx, y = yy;
	}
	vec (vec a, vec b)
	{
		x = b.x - a.x;
		y = b.y - a.y;
	}
	ld operator ^ (vec p)
	{
		return x * p.y - y * p.x;
	}
	ld operator * (vec p)
	{
		return x * p.x + y * p.y;
	}
	ld length ()
	{
		return sqrt (x * x + y * y);
	}
};
typedef vec point;
ld angle (vec a, vec b)
{
	return acos ((a * b) / (a.length () * b.length ()));
}
ld point_angle (point a)
{
	ld g = angle (vec (1, 0), a);
	if (a.y < 0) g = 2 * pi - g;
	return g;
}
ld three_point_angle (point a, point b, point c)
{
	return angle (vec (b, a), vec (b, c));
}
ld r;
point a, b, o = point (0, 0);
ld anga, angb;
ld deg (ld rad)
{
	return (rad / pi) * 180;
}
ld rad (ld deg)
{
	return (deg / 180) * pi;
}
point point_at_angle (ld angle)
{
	ld u = r * cos (angle);
	ld v = sqrt (r * r - u * u);
	if (angle > pi) v = -v;
	return point (u, v);
}
void input ()
{
	cin >> r >> a.x >> a.y >> b.x >> b.y;
	anga = point_angle (a);
	angb = point_angle (b);
	if (anga > angb) swap (anga, angb), swap (a, b);
}
void solve ()
{
	ld low = anga, high = angb;
	while (high - low > eps)
	{
		ld mid = (low + high) / 2;
		point x = point_at_angle (mid);
		ld axo = three_point_angle (a, x, o), bxo = three_point_angle (b, x, o);
		if (axo > bxo) low = mid;
		else high = mid;
	}
	point g = point_at_angle (low);
	g.x += eps;
	g.y += eps;
	// if (g.x < 0 and g.x - 0 < eps) g.x = 0;
	// if (g.y < 0 and g.y - 0 < eps) g.y = 0;
	cout << fixed << setprecision (4) << g.x << ' ' << g.y << '\n';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("lqdalh.inp", "r", stdin);
	freopen ("lqdalh.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		input ();
		solve ();
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}
