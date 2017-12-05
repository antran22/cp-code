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
const int inf = 1e9, maxn = 1e5 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct vec
{
	ll x, y, z;
	vec () {}
	vec (ll xx, ll yy, ll zz)
	{
		x = xx, y = yy, z = zz;
	}
	vec (vec a, vec b)
	{
		x = b.x - a.x;
		y = b.y - a.y;
		z = b.z - a.z;
	}
	vec operator ^ (vec a)
	{
		ll rx = y * a.z - z * a.y;
		ll ry = z * a.x - x * a.z;
		ll rz = x * a.y - y * a.x;
		return vec (rx, ry, rz);
	}
};
typedef vec point;
point p [maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		p[i] = point (x, y, z);
	}
}
ll pa, pb, pc, pd;
bool point_on_plane (point a)
{
	return (pa * a.x + pb * a.y + pc * a.z + pd) == 0;
}
bool collinear (vec a, vec b)
{
	return a.x * b.y == a.y * b.x and a.y * b.z == a.z * b.y and a.z * b.x == a.x * b.z;
}
void solve ()
{
	if (n <= 3) 
	{
		cout << "TAK";
		return;
	}
	vec a = vec (p[1], p[2]);
	vec b = vec (p[1], p[3]);
	int id = 3;
	if (collinear (a, b))
	{
		for (int i = 4; i <= n; ++i)
		{
			vec x = vec (p[1], p[i]);
			if (!collinear (a, x)) 
			{
				id = i;
				goto tcvan;
			}
		}
		cout << "TAK";
		return;
	}
	tcvan:;
	b = vec (p[1], p[id]);
	vec c = a ^ b;
	pa = c.x;
	pb = c.y;
	pc = c.z;
	pd = - pa * p[1].x - pb * p[1].y - pc * p[1].z;
	// cerr << pa << ' ' << pb << ' ' << pc << ' ' << pd << '\n';
	for (int i = 1; i <= n; ++i)
	{
		if (i != 1 and i != 2 and i != id)
		{
			if (!point_on_plane (p[i])) 
			{
				cout << "NIE";
				return;
			}
		}
	}
	cout << "TAK";
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("krz.inp", "r", stdin);
	freopen ("krz.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}