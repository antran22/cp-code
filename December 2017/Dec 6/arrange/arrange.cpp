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
typedef pair <int, int> pii;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m, a[maxn], r;
ll b[maxn], sumw[maxn], sum = 0;
int gw (int i)
{
	return b[i] > 0 ? 1 : - 1;
}
ll res = 0;
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], sum += a[i];
	int q = sum / n;
	r = sum % n;
	for (int i = 1; i <= n; ++i)
		a[i] -= q, b[i] = b[i - 1] + a[i];
	for (int i = n; i >= 1; --i)
		sumw[i] = sumw[i + 1] + gw (i), res += abs (b[i]);
}
bool vst [maxn] = {};
void brute_force ()
{
	for (int it = 1; it <= r; ++it)
	{
		ll sw = 0, max_w = -inf, id;
		for (int i = n; i >= 1; --i)
		{
			sw += gw (i);
			if (sw > max_w and !vst[i]) max_w = sw, id = i;
		}
		vst[id] = 1;
		for (int i = id; i <= n; ++i)
			b[i] --;
		res -= max_w;
	}
	cout << res;
}
struct node
{
	int l, r;
	int w_lz = 0, b_lz = 0;
	pii min_b, max_w;
} t[maxn];
pii min (pii a, pii b)
{
	if (a.ft > b.ft) return b;
	return a;
}
pii max (pii a, pii b)
{
	if (a.ft < b.ft) return b;
	return a;
}
void build (int id, int l, int r)
{
	node &x = t[id];
	x.l = l, x.r = r;
	if (l == r)
	{
		x.max_w = mp (sumw[l], l);
		if (b[l] > 0) x.min_b = mp (b[l], l);
		else x.min_b = mp (inf, 0);
		return;
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	x.min_b = min (t[id * 2].min_b, t[id * 2 + 1].min_b);
	x.max_w = max (t[id * 2 + 1].max_w, t[id * 2].max_w);
}
void pass (int id)
{
	int &w_lz = t[id].w_lz;
	int &b_lz = t[id].b_lz;
	t[id * 2].max_w.ft += w_lz;
	t[id * 2].w_lz += w_lz;
	t[id * 2].min_b.ft += b_lz;
	t[id * 2].b_lz += b_lz;
	t[id * 2 + 1].max_w.ft += w_lz;
	t[id * 2 + 1].w_lz += w_lz;
	t[id * 2 + 1].min_b.ft += b_lz;
	t[id * 2 + 1].b_lz += b_lz;
	w_lz = 0;
	b_lz = 0;
}
int p, q;
pii tree_query_w (int id)
{
	node &x = t[id];
	int l = x.l, r = x.r;
	if (l > q or r < p) return mp (-inf, 0);
	if (p <= l and r <= q)
	{
		return x.max_w;
	}
	pass (id);
	return max (tree_query_w (id * 2), tree_query_w (id * 2 + 1));
}
void tree_set_w (int id)
{
	node &x = t[id];
	int l = x.l, r = x.r;
	if (l > q or r < p) return;
	if (p <= l and r <= q)
	{
		x.max_w.ft -= 2;
		x.w_lz -= 2;
		return;
	}
	pass (id);
	tree_set_w (id * 2);
	tree_set_w (id * 2 + 1);
	x.max_w = max (t[id * 2].max_w, t[id * 2 + 1].max_w);
}
pii get_w (int l, int r)
{
	p = l, q = r;
	return tree_query_w (1);
}
void set_w (int l, int r)
{
	p = l, q = r;
	tree_set_w (1);
}
void tree_set_b (int id)
{
	node &x = t[id];
	int l = x.l, r = x.r;
	if (l > q or r < p) return;
	if (p <= l and r <= q)
	{
		x.min_b.ft --;
		x.w_lz --;
		return;
	}
	pass (id);
	tree_set_b (id * 2);
	tree_set_b (id * 2 + 1);
	x.min_b = min (t[id * 2].min_b, t[id * 2 + 1].min_b);
}
pii query_min_b (int id)
{
	node &x = t[id];
	int l = x.l, r = x.r;
	if (l > q or r < p) return;
	if (p <= l and r <= q)
	{
		return x.min_b;
	}
	return min (t[id * 2].min_b, t[id * 2 + 1].min_b);
}
int pos;
void del_point (int id)
{
	node &x = t[id];
	int l = x.l, r = x.r;
	if (pos < l or r < pos) return;
	if (l == r)
	{
		x.min_b = mp (inf, 0);
		return;
	}
	del_point (id * 2);
	del_point (id * 2 + 1);
}
void increase_seg (int l, int r)
{
	p = l, q = r;
	tree_set_b (1);
	while (true)
	{
		pii x = query_min_b (1);
		if (x.ft > 0) return;
	}
}
void print (int id, int deg)
{
	auto &x = t[id];
	for (int i = 0; i < deg; ++i) cout << ' ';
	cout << x.l << ' ' << x.r << ' ' << x.max_w.ft << ' ' << x.max_w.sd << ' ' << x.min_b.ft << ' ' << x.min_b.sd << '\n';
	if (x.l == x.r) return;
	print (id * 2, deg + 1);
	print (id * 2 + 1, deg + 1);
}
void solve ()
{
	// brute_force ();
	for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
		cout << '\n';
	for (int i = 1; i <= n; ++i) cout << sumw[i] << ' ';
		cout << '\n';
	build (1, 1, n);
	print (1, 0);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("arrange.inp", "r", stdin);
	freopen ("arrange.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}
