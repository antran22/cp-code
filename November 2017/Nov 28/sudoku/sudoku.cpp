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
struct coord {int x, y;};
set <int> row[401], col[401], tab[401];
int tab_id (coord a)
{
	int x = (a.x - 1) / n, y = (a.y - 1) / n;
	return y * n + x + 1 ;
}
int a[401][401];
int &ga (coord b)
{
	return a[b.y][b.x];
}
int nn;
void input ()
{
	cin >> n;
	nn = n * n;
	for (int i = 1; i <= nn; ++i)
		for (int j = 1; j <= nn; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= nn; ++i)
		for (int j = 1; j <= nn; ++j)
		{
			col[i].ins (j);
			row[i].ins (j);
			tab[i].ins (j);
		}
}
vi get_digit (coord h)
{
	vi res;
	int t = tab_id (h);
	for (int i : col[h.x])
	{
		if (row[h.y].count (i) and tab[t].count (i)) res.pb (i);
	}
	return res;
}
int cnt_row[401], cnt_col[401], cnt_tab[401];
void set_digit (coord h)
{
	int t = tab_id (h);
	col[h.x].erase (ga (h)), ++cnt_col[h.x];	
	row[h.y].erase (ga (h)), ++cnt_row[h.y];	
	tab[t].erase (ga (h)), ++cnt_tab[t];	
}
void unset_digit (coord h)
{
	int t = tab_id (h);
	col[h.x].ins (ga (h)), --cnt_col[h.x];	
	row[h.y].ins (ga (h)), --cnt_row[h.y];	
	tab[t].ins (ga (h)), --cnt_tab[t];
	ga (h) = 0;
}
int possibility (coord h)
{
	int t = tab_id (h);
	return min (min (cnt_col[h.x], cnt_row[h.x]), cnt_tab[t]);
}
vector <coord> blank;
bool found = 0;
void attempt (int id)
{
	cerr << id << ' ';
	if (found) return;
	else if (id == m) 
	{
		found = 1;
		return;
	}
	coord x = blank[id];
	vi cand = get_digit (x);
	for (int i : cand)
	{
		ga (x) = i;
		// cerr << i << ' ';
		set_digit (x);
		attempt (id + 1);
		if (found) return;
		unset_digit (x);
	}
}
void solve ()
{
	for (int i = 1; i <= nn; ++i)
		for (int j = 1; j <= nn; ++j)
			if (a[i][j]) 
				set_digit (coord {j, i});
	for (int i = 1; i <= nn; ++i)
		for (int j = 1; j <= nn; ++j)
			if (a[i][j] == 0) blank.pb (coord {j, i});
	m = blank.size ();
	stable_sort (whole (blank), [] (coord x, coord y)
	{
		int dx = possibility (x), dy = possibility (y);
		return dx < dy;
	});
	// for (coord x : blank) cerr << x.x << ' ' << x.y << "   ";
	attempt (0);
	for (int i = 1; i <= nn; ++i)
	{
		for (int j = 1; j <= nn; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
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
	freopen ("sudoku.inp", "r", stdin);
	freopen ("sudoku.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}