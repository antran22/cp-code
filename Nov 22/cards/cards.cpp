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
struct splay_tree
{
	struct node;
	typedef node* pnode;
	struct node
	{
		int value;
		int size;
		pnode p, l, r;
	};
	pnode root, nil;
	// Đặt nút y làm con x
	void setlink (pnode x, pnode y, bool right)
	{
		y -> p = x;
		right ? x -> r = y : x -> l = y;
	}
	// Dựng cây biểu diễn 1, 2, 3,..., n
	inline void update (pnode x)
	{
		x -> size =  (x -> l -> size) + (x -> r -> size) + 1;
	}
	void init (int n)
	{
		nil = new node;
		*nil = {0, 0, nil, nil, nil};
		root = nil;
		for (int i = 1; i <= n; ++i)
		{
			pnode x = new node {i, i, nil, root, nil};
			root -> p = x;
			root = x;
			update (root);
		}
	}
	// In ra cây
	// tìm nút thứ i trong cây gốc T
	pnode find (pnode t, int i)
	{
		while (true)
		{
			// cerr << i << ' ';
			int lsize = t -> l -> size;
			if (lsize + 1 == i) return t;
			if (i <= lsize) t = t -> l;
			else i -= lsize + 1, t = t -> r;
		}
	}
	void uptree (pnode x)
	{
		pnode y = x -> p, z = y -> p;
		if (x == y -> l)
		{
			setlink (y, x -> r, false);
			setlink (x, y, true);
		}
		else
		{
			setlink (y, x -> l, true);
			setlink (x, y, false);
		}
		setlink (z, x, (z -> r) == y);
		update (y);
		update (x);
	}
	void print (pnode x)
	{
		if (x == nil) return;
		print (x -> l);
		// for (int j = 1; j <= i; ++j) cout << ' ';
		cout << x -> value << ' ';
		print (x -> r);
	}
	void splay (pnode x)
	{
		while (x -> p != nil) uptree (x);
	}
	void split (pnode t, int i, pnode &a, pnode &b)
	{
		if (i == 0) 
		{
			a = nil;
			b = t;
			return;
		}
		pnode  x = find (t, i);
		splay (x);
		a = x, b = x -> r;
		a -> r = nil;
		b -> p = nil;
		update (a);
	}
	pnode ra, rb, rc;
	pnode join (pnode a, pnode b)
	{
		while (a -> r != nil) a = a -> r;
		splay  (a);
		setlink (a, b, true);
		update (a);
	}
	void tree_print (pnode root)
	{
		print (root);
		cout << '\n';
	}
	void move_seg (int l, int m, int j)
	{
		int r = l + m - 1;
		// cerr << root << ' ';
		split (root, r, ra, rc);
		tree_print (ra);
		tree_print (rc);
		cout << '\n';
		split (ra, l - 1, ra, rb);
		tree_print (ra);
		tree_print (rb);
		tree_print (rc);
		cout << '\n';
		join (ra, rc);
		tree_print (ra);
		tree_print (rb);
		tree_print (rc);
		join (ra, rb);
		cout << '\n';
		tree_print (ra);
		tree_print (rb);
		tree_print (rc);
		root = ra
	}
};
splay_tree s;
void input ()
{
	cin >> n;
	s.init (n);
	// s.tree_print ();
	s.move_seg (2, 2, 1);
	cout << '\n';
	// s.tree_print ();
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
	freopen ("cards.inp", "r", stdin);
	freopen ("cards.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}