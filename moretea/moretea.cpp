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
void build (int id, int l, int r)
{
	t[id].l = l, t[id].r = r;
	if (l == r)
	{
		if (a[l] == m) t[i].mx = mp (-inf, 0) , t[i].cnt = 0;
		else t[i].mx = mp (a[l], l), t[i].cnt;
		t[i].sum = min (a[l], m);
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	merge_node (id);
}
int p, q, del_id;
ll v;
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
		while (t[id].mx.ft + x >= m)
		{
			del_id = t[id].mx.sc;
			delete_node (1);
		}
		t[id].mx.ft += v;
		t[id].sum += v * cnt;
		t[id].lz += v;
	}
	pass (id);
	update (id * 2);
	update (id * 2 + 1);

}
void solve ()
{

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