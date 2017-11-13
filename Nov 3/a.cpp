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
struct block
{
	ll x, a;
} c[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i].x >> c[i].a;
	sort (c + 1, c + n + 1, [] (block p, block q)
	{
		return p.x < q.x;
	});
	cin >> k;
}
ll last2 = -inff, last1 = -inff;
int cnt = 0;
void solve ()
{
	for (int i = 1; i <= n; ++i)
	{
		if (c[i].x - last2 <= k) continue;
		else
		{
			if (c[i].a <= 2 * k + 1)
			{
				int g = max (last1 + 1, c[i].x - k);
				if (c[i].x + k - g + 1 >= c[i].a)
				{
					last1 = c[i].x + k;
					continue;
				}
			}
			last2 = c[i].x + k, ++cnt;
		}
	}
	cout << cnt;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("a.inp", "r", stdin);
	freopen ("a.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}