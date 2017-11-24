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
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct node;
typedef node* pnode;
struct node
{
	char val;
	int size;
	pnode p, l, r;
};
pnode root, root2, nil;
string s;
void init (pnode &root, int n)
{
	root = nil;
	for (int i = 0; i <= n + 1; ++i)
	{
		pnode x = new node {s[i], i + 1, nil, root, nil};
		root -> p = x;
		root = x;
	}
}
pnode find (pnode t, int i)
{
	while (true)
	{
		int j = t -> l -> size;
		if (j + 1 == i) return t;
		if (j >= i) t = t -> l;
		else t = t -> r, i -= j + 1;
	}
}
void update (pnode t)
{
	t -> size = t -> l -> size + t -> r -> size + 1;
}
void link (pnode p, pnode c, bool l)
{
	if (l) p -> l = c;
	else p -> r = c;
	c -> p = p;
}
void uptree (pnode x)
{
	pnode y = x -> p, z = y -> p;
	bool side = (x == y -> l), side2 = (y == z -> l);
	pnode t = (side ? x -> r : x -> l);
	link (y, t, side);
	link (x, y, !side);
	link (z, x, side2);
}
void tree_print (pnode x, int i)
{
	if (x == nil) return;
	tree_print (x -> l, i + 1);
	for (int j = 1; j <= i; ++j) cout << ' ';
	cout << x -> val << '\n';
	tree_print (x -> r, i + 1);
}
void print (pnode root)
{
	tree_print (root, 0);
	cout << '\n';
}
void strprint (pnode x)
{
	if (x == nil) return;
	strprint (x -> l);
	cout << x -> val;
	strprint (x -> r);
}
void splay (pnode x)
{
	while (true)
	{
		pnode y = x -> p;
		if (y == nil) break;
		pnode z = y -> p;
		if (z != nil)
		{
			if ((z -> l == y) == (y -> l == x))
				uptree (y);
			else uptree (x);
		}
		uptree (x);
	}
}
void split (pnode t, int i, pnode &a, pnode &b)
{
	if (i == 0)
	{
		a = nil, b = t;
		return;
	}
	pnode x = find (t, i);
	splay (x);
	a = x; b = x -> r;
	a -> r = nil;
	b -> p = nil;
	update (a);
}
void join (pnode &a, pnode &b)
{
	while (a -> r != nil) a = a -> r;
	splay (a);
	link (a, b, 0);
	update (a);
}
void rev_string (int l, int r)
{
	pnode a1, b1, c1, a2, b2, c2;
	split (root, r + 1, a1, c1);
	split (root2, n - l, a2, c2);
	split (a1, l, a1, b1);
	split (a2, n - 1 - r, a2, b2);
	join (a1, b2);
	join (a1, c1);
	join (a2, b1);
	join (a2, c2);
	root = a1;
	root2 = a2;
}
void input ()
{
	nil = new node;
	*nil = node {0, 0, nil, nil, nil};
	cin >> s;
	n = s.length ();
	s.ins (n, " ");
	s.ins (0, " ");
	init (root, n);
	reverse (whole (s));
	init (root2, n);
	n += 2;
}
void solve ()
{
	// cin >> m;
	// int l, r;
	// for (int i = 1; i <= 1; ++i)
	// {
	// 	cin >> l >> r;
	rev_string (3, 5);
	// rev_string (3, 5);
	print (root2);
	// }
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("so.inp", "r", stdin);
	freopen ("so.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}
