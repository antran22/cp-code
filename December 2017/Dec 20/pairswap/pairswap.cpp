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
int a[maxn];
vector <pair <int,int>> val;
void input ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		val.pb (mp (a[i], i));
	}
	sort (whole (val));
	reverse (whole (val));
}
set <int> s;
int res [maxn];
int ming[maxn], id[maxn] = {};
void solve ()
{
	for (auto x : val)
	{
		auto it = s.lower_bound (x.second - k);
		if (it != s.end () and *it < x.second)
		{
			res[x.second] = *it;
		}
		else res[x.second] = inf;
		s.ins (x.second);
	}
	for (int i = 1; i <= n; ++i)
	{
		ming[i] = inf;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (res[i] == inf) continue;
		if (ming[res[i]] >= a[i])
		{
			ming[res[i]] = a[i];
			id[res[i]] = i;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (ming[i] != inf)
		{
			swap (a[i], a[id[i]]);
			break;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << ' ';
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
	freopen ("pairswap.inp", "r", stdin);
	freopen ("pairswap.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}