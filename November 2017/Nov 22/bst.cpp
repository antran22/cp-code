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
void init ()
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
void print (pnode x, int i)
{
	if (x == nil) return;
	print (x -> l, i + 1);
	for (int j = 1; j <= i; ++j) cout << ' ';
	cout << x -> value << '\n';
	print (x -> r, i + 1);
}
void input ()
{
	cin >> n;
	init ();
	print (root, 0);
	cout << '\n';
	pnode x = find (root, 5);
	uptree (x);
	print (root, 0);
}
void solve ()
{

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("bst.inp", "r", stdin);
	freopen ("bst.out", "w", stdout);
	input ();
	solve ();
}