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
vi center[maxn];
vi fixed_point;
bool self[maxn];
vi &get_cen (double x)
{
	return center [int (x * 2)];
}
int a[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] == i) fixed_point.pb (a[i]), self [a[i]] ++;
		else get_cen ((a[i] + i) / 2.0).pb (i);
	}
}
int res = 0, frt, lst;
void count_fixed (double c)
{
	sort (whole (get_cen (c)), [&c] (int i, int j)
		{
			return abs (i - c) < abs (j - c);
		});
	int count = 0;
	int xsum = 0;
	for (int i : get_cen (c))
	{
		++count;
		double rad = abs (i - c);
		int maxpos = floor (c + rad), minpos = ceil (c - rad);
		int old_fix = upper_bound (whole (fixed_point), maxpos) - lower_bound (whole (fixed_point), minpos);
		if (c == int (c) and self[int (c)]) old_fix -= 2;
		int sum = count - old_fix;
		if (sum > res) res = sum, frt = minpos, lst = maxpos;
		xsum = max (xsum, sum);
	}
	// cout << c << ' ' << xsum << '\n';
}
void solve ()
{
	for (double g = 1; g <= n; g += 0.5)
		count_fixed (g);
	// cout << res << ' ' << frt << ' ' << lst << '\n';
	if (frt == 0 and lst == 0)
		cout << 1 << ' ' << 1;
	else cout << a[frt] << ' ' << a[lst];
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	// freopen ("doktor.inp", "r", stdin);
	// freopen ("doktor.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}