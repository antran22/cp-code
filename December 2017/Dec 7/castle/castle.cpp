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
struct coord 
{
	int i, j;
	coord operator + (coord g)
	{
		return coord {i + g.i, j + g.j};
	}
};
bool b[1001][1001];
coord d[4] = {coord {1, 0}, coord {-1, 0}, coord {0, -1}, coord {0, 1}};
int _room[1001][1001];
void input ()
{
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			char c;
			cin >> c;
			b[i][j] = (c == '1');
		}
}
bool &get_type (coord a)
{
	return b[a.i][a.j];
}
int &room (coord a)
{
	return _room[a.i][a.j];
}
bool _vst [1001][1001];
bool &vst (coord a)
{
	return _vst[a.i][a.j];	
}
bool in_range (coord a)
{
	return (1 <= a.i and a.i <= m and 1 <= a.j and a.j <= n);
}
bool visitable (coord a)
{
	return (!get_type (a) and !vst (a) and in_range (a));
}
void print (coord a)
{
	cout << a.i << ' ' << a.j << '\n';
}
int room_id;
int room_size [maxn] = {};
void dfs (coord a)
{
	// print (a);
	vst (a) = 1;
	room (a) = room_id;
	++ room_size [room_id];
	for (int i = 0; i < 4; ++i)
	{
		coord g = a + d[i];
		if (!visitable (g)) continue;
		dfs (g);
	}
}
int get_del (coord a)
{
	set <int> r;
	for (int i = 0; i < 4; ++i)
	{
		coord g = a + d[i];
		if (!get_type (g) and in_range (g))
		{
			r.ins (room (g));
		}
	}
	int res = 0;
	for (int i : r)
	{
		res += room_size [i];
	}
	return res + 1;
}
int res = 0;
void solve ()
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (!_vst[i][j] and !b[i][j]) ++room_id, dfs (coord {i, j}), res = max (res, room_size[room_id]);
		}
	// cout << room_id;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (b[i][j])
			{
				res = max (res, get_del (coord {i, j}));
			}
		}
	cout << res;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("castle.inp", "r", stdin);
	freopen ("castle.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}