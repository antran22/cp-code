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
struct dice
{
	int t, d, r, l, f, b, sum;
	dice get_input ()
	{
		cin >> t >> d >> r >> l >> f >> b;
	}
	void summa ()
	{
		sum = t + d + r + l + f + b;
	}
	void rotate_right ()
	{
		int temp = l;
		l = d;
		d = r;
		r = t;
		t = temp;
	}
	void rotate_down ()
	{
		int temp = t;
		t = b;
		b = d;
		d = f;
		f = temp;
	}
	void operator = (dice gg)
	{
		t = gg.t, d = gg.d, r = gg.r, l = gg.l, f = gg.f, b = gg.b, sum = gg.sum;
	}
	void print ()
	{
		cout << t << ' ' << d << ' ' << r << ' ' << l << ' ' << f << ' ' << b << '\n';
	}
};
dice a[4];
vector <dice> s[4];
void make_state_list (int id)
{
	a[id].get_input ();
	dice temp = a[id];
	for (int i = 1; i <= 6; ++i, temp.rotate_down ());
	{
		dice temp2 = temp;
		for (int j = 1; j <= 6; ++j, temp2.rotate_right ())
		{
			s[id].pb (temp2);
			dice temp3 = temp2;
			temp3.rotate_down ();
			s[id].pb (temp3);
		}
	}
}
void input ()
{
	for (int i = 1; i <= 4; ++i)
	{
		make_state_list (i);
		// for (dice &g : s[i]) g.print ();
	}
}
int x[5] = {0, 1, 2, 3, 4};
dice cell[5];
int check ()
{
	if (cell[1].r == cell[2].l and cell[1].f == cell[3].b and cell[3].r == cell[4].l and cell[2].f == cell[3].b)
	{
		return cell[1].sum - cell[1].f - cell[1].r
		+ cell[2].sum - cell[2].l - cell[2].f
		+ cell[3].sum - cell[3].b - cell[3].r
		+ cell[4].sum - cell[4].l - cell[4].b;
	}
	return -1;
}
int it[5];
int res = -1;
void test ()
{
	for (it[1] = 0; it[1] < s[1].size (); ++it[1])
		for (it[2] = 0; it[2] < s[2].size (); ++it[2])
			for (it[3] = 0; it[3] < s[3].size (); ++it[3])
				for (it[4] = 0; it[4] < s[4].size (); ++it[4])
				{
					for (int i = 1; i <= 4; ++i)
					{
						cell[i] = s[x[i]][it[i]];
						cell[i].summa ();
					}
					res = max (res, check ());
				}
}
void solve ()
{
	for (int i = 1; i <= 24; ++i)
	{
		test ();
		// for (int j = 1; j <= 4; ++j) cout << x[j] << ' ';
		next_permutation (x + 1, x + 5);
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
	freopen ("sucsac.inp", "r", stdin);
	freopen ("sucsac.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}