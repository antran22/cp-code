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
int col[500][500] = {};
int &point (int x, int y)
{
	return col[x + 200][y + 200];
}
void input ()
{
	cin >> n;
	int x, y, c;
	for (int i = 1; i <= n; ++i)
		cin >> x >> y >> c,
		point (x, y) = c;
}
int bitize (int x, int y)
{
	if (x == 0 or y == 0) return -1;
	return (1 << (x - 1)) + (1 << (y - 1));
}
ll res = 0;
void solve ()
{
	for (int i = -200; i <= 200; ++i)
		for (int j = -200; j < i; ++j)
		{
			int f[20] = {};
			for (int k = -200; k <= 200; ++k)
			{
				int x = bitize (point (i, k), point (j, k));
				if (x == -1) continue;
				++f[x];
			}
			for (int k = 3; k <= 6; ++k)
			{
				res += f[k] * f[15 - k];
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
	freopen ("colorec.inp", "r", stdin);
	freopen ("colorec.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}