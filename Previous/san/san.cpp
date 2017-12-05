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
typedef pair<int,int> way;
#define h first
#define g second
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9;
int n, k, m;
ll h[maxn], g[maxn];
int beg = 0, en;
int max_h = 0;
vector <way> w[2];
void attempt (int last, ll gold)
{
	for (int i = last + 1; i <= en; ++i)
		if (h[i] >= h[last])
		{
			if (beg) w[1].pb (mp (max_h - beg, gold + g[i]));
			else w[0].pb (mp (max_h - h[i], gold + g[i]));
			attempt (i, gold + g[i]);
		}
}
void input ()
{
	vi rank_h;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> h[i] >> g[i], rank_h.pb (h[i]);
	sort (whole (rank_h));
	for (int i = 1; i <= n; ++i) h[i] = lower_bound (whole (rank_h), h[i]) - rank_h.begin ();
	max_h = *max_element (h + 1, h + n + 1) + 2;
}
void divide ()
{
	beg = 0;
	en = n / 2;
	attempt (0, 0);
	en = n;
	for (int i = n / 2 + 1; i <= n; ++i)
	{
		beg = h[i];
		w[1].pb (mp(max_h - h[i], g[i]));
		attempt (i, g[i]);
	}
}
ll ft[maxn];
void update (int i)
{
	for (; i < maxn; i += i & (-i))
		++ft[i];
}
ll query (int i)
{
	int res = 0;
	for (; i > 0; i &= (i - 1))
		res += ft[i];
	return res;
}
void solve ()
{
	divide ();
	sort (whole (w[0]), [] (way a, way b)
	{
		return a.g < b.g;
	});
	sort (whole (w[1]), [] (way a, way b)
	{
		return a.g > b.g;
	});
	ll res = 0;
	for (auto x : w[0]) if (x.g >= k) res ++;
	for (auto x : w[1]) if (x.g >= k) res ++;
	int i = -1;
	for (way a : w[0])
	{
		while (i + 1 < w[1].size () and w[1][i + 1].g + a.g >= k)
		{
			++i;
			update (w[1][i].h);
		}
		// cerr << i << ' ';
		res += query (a.h);
	}
	cout << res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	// freopen ("san.inp", "r", stdin);
	// freopen ("san.out", "w", stdout);
	input ();
	solve ();
}