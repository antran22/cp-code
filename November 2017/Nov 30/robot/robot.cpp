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
int l_end, r_end, u_end, d_end;
int x, y;
char c;
vi l, r, u, d;
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c;
		if (c == 'L') l.pb (i);
		else if (c == 'R') r.pb (i);
		else if (c == 'U') u.pb (i);
		else if (c == 'D') d.pb (i);
	}
	cin >> x >> y;
}
void solve ()
{
	if (x > sz(r) or (-x) > sz(l) or y > sz(u) or (-y) > sz(d))
	{
		cout << -1;
		return;
	}
	if (x == 0) r_end = l_end = 0;
	if (x > 0) 
	{
		l_end = 0;
		r_end = r[x - 1];
	}
	if (x < 0)
	{
		r_end = 0;
		l_end = l[-x - 1];
	}
	if (y == 0) d_end = u_end = 0;
	if (y > 0) 
	{
		d_end = 0;
		u_end = u[y - 1];
	}
	if (y < 0) 
	{
		u_end = 0;
		d_end = d[-y - 1];
	}

	cout << l_end << ' ' << u_end << ' ' << r_end << ' ' << d_end;
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