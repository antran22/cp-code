//code.cpp
#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1001;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
char c[maxn][maxn];
bool g[maxn];
struct coord
{
	int x, y;
	coord () {}
	coord (int xx, int yy)
	{
		x = xx, y = yy;
	}
};
struct parcel
{
	coord tr, bl;
	parcel () {}
	parcel (int x, int y, int xx, int yy)
	{
		bl = coord (x, y);
		tr = coord (xx, yy);
	}
};
typedef vector <parcel> vp;
vector <vp> table;
void input ()
{
	cin >> n >> k;
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 'x') g[i] = 1;
		}
}
int cnt = 0;
void split (int row, int last_row)
{
	int last = 0;
	vp t_row;
	for (int i = 1; i <= n; ++i)
	{
		if (a[row][i] == 'x')
		{
			parcel h (i, row, last, last_row);
			t_row.pb (h);
			last = i;
			++cnt;
		}
	}
	table.pb (t_row);
}
parcel merge (parcel a, parcel b)
{
	int blx = min (a.bl.x, b.bl.x);
	int bly = min (a.bl.y, b.bl.y);
	int trx = max (a.tr.x, b.tr.x);
	int ty  = max (a.tr.y, b.tr.y);
	return parcel (blx, bly, trx, ty);
}
void solve ()
{
	int last_row = 0;
	for (int i = 1; i <= n; ++i)
		if (g[i]) split (i, last_row), last_row = i;
	assert (k <= cnt);
	for (vp &row : x)
	{
		if (cnt == k) break;
		for (int i = sz (row) - 2; i > -1; --i)
		{
			row[i] = merge (row[i], row[i + 1]);
			--cnt;
			row.pop_back ();
			if (cnt == k) break;
		}
	}
	vp xx;
	if (cnt > k)
	{
		for (vp h : x) xx.pb (h.back ());
		while (cnt > k)
		{
			int j = xx.size () - 1, i = j - 1;
			xx[i] = merge (xx[i], xx[j]);
		}

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
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}