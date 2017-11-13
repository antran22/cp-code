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
	vec (ll xx, ll yy)
	{
		x = xx, y = yy;
	}
	vec (vec p, vec q)
	{
		x = q.x - p.x;
		y = q.y - p.y;
	}
	ll operator ^ (vec p, vec q)
	{
		return p.x * q.y - p.y * q.x;
	}
};
void input ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
	sort (a + 1, a + n + 1);
}
void solve ()
{

}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("poly.inp", "r", stdin);
	freopen ("poly.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}