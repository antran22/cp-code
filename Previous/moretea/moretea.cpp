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
#define ft first
#define sc second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pii;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct node
{
	int l, r, cnt;
	ll sum, lz;
	pii mx;
} t [maxn];
pii max (pii a, pii b)
{
	if (a.ft > b.ft) return a;
	return b;
}
void merge_node (int id)
{
	t[id].cnt = t[id * 2].cnt + t[id * 2 + 1].cnt;
	t[id].sum = t[id * 2].sum + t[id * 2 + 1].sum;
	t[id].mx = max (t[id * 2].mx, t[id * 2 + 1].mx);
}
int a[maxn];
void build (int id, int l, int r)
{
	t[id].l = l, t[id].r = r;
	if (l == r)
	{
		if (a[l] == m) t[id].mx = mp (-inf, 0) , t[id].cnt = 0;
		else t[id].mx = mp (a[l], l), t[id].cnt = 1;
		t[id].sum = min (a[l], m);
		return;
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	merge_node (id);
}
int p, q, del_id;
ll v;
void add_node (int id, int v)
{
	t[id].sum += v * t[id].cnt;
	t[id].lz += v;
	t[id].mx.ft += v;
}
void pass (int id)
{
	if (t[id].lz == 0) return;
	add_node (id * 2, t[id].lz);
	add_node (id * 2 + 1, t[id].lz);
	t[id].lz = 0;
}
void delete_node (int id)
{
	int l = t[id].l, r = t[id].r;
	if (del_id < l or r < del_id) return;
	if (del_id == q)
	{
		t[id].sum = m;
		t[id].cnt = 0;
		t[id].mx = mp (-inf, 0);
		return;
	}
	pass (id);
	delete_node (id * 2);
	delete_node (id * 2 + 1);
	merge_node (id);
}
void update (int id)
{
	int l = t[id].l, r = t[id].r;
	if (q < l or r < p) return;
	if (p <= l and r <= q)
	{
		if (t[id].mx.ft == -inf) return;
		while (t[id].mx.ft + v >= m)
		{
			del_id = t[id].mx.sc;
			delete_node (1);
		}
		add_node (id, v);
		return;
	}
	pass (id);
	update (id * 2);
	update (id * 2 + 1);
	merge_node (id);
}
ll query (int id)
{
	int l = t[id].l, r = t[id].r;
	if (q < l or r < q) return 0;
	if (p <= l and r <= q)
		return t[id].sum + m * (r - l + 1 - t[id].cnt);
	return query (id * 2) + query (id * 2 + 1);
}
void input ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	build (1, 1, n);
}
void debug (int i, int h)
{
	for (int j = 1; j <= h; ++j) cout << ' ';
	cout << t[i].l << ' ' << t[i].r << ' ' << t[i].sum << ' ' << t[i].mx.ft << '\n';
	if (t[i].l == t[i].r) return;
	debug (i * 2, h + 1);
	debug (i * 2 + 1, h + 1);
}
void solve ()
{
	p = 2, q = 3, v = 2;
	update (1);
	debug (1, 0);

	// p = 1, q = 5;
	// cout << query (1);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("moretea.inp", "r", stdin);
	freopen ("moretea.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}