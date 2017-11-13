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
vi adj[maxn];
int low[maxn] = {}, num[maxn] = {}, id[maxn] = {}, cmp_edge[maxn] = {}, cmp_node[maxn] = {}, cnt = 0, cmp_cnt = 0;
stack <int> st;
void tarjan (int i)
{
	st.push (i);
	low[i] = num[i] = ++cnt;
	for (int j : adj[i])
	{
		if (num[j]) low[i] = min (low[i], num[j]);
		else tarjan (j), low[i] = min (low[i], low[j]);
	}
	if (low[i] == num[i])
	{
		++cmp_cnt;
		int j;
		do
		{
			j = st.top ();
			st.pop ();
			id [j] = cmp_cnt;
			++cmp_node [cmp_cnt];
		} while (j != i);
	}
}
int u[maxn], v[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> u[i] >> v[i], adj[u[i]].pb (v[i]), adj[v[i]].pb (u[i]);
	++n;
	for (int i = 1; i <= n; ++i)
		if (!num[i]) tarjan (i);
	for (int i = 1; i < n; ++i)
		if (id[u[i]] == id[v[i]]) cmp_edge[id[u[i]]] ++;
}
ll res = 0;
void solve ()
{
	ll tree_node_cnt;
	for (int i = 1; i <= cmp_cnt; ++i)
	{
		if (cmp_node[i] != cmp_edge[i] and cmp_node[i] != cmp_edge[i] + 1)
		{
			cout << 0;
			return;
		}
		if (cmp_edge[i] == cmp_node[i] - 1)
		{
			tree_node_cnt = cmp_node[i];
			break;
		}
	}
	res += tree_node_cnt * (tree_node_cnt - 1) / 2;
	for (int i = 1; i <= cmp_cnt; ++i)
	{
		if (cmp_edge[i] == cmp_node[i])
			res += (tree_node_cnt * cmp_edge[i]);
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
	freopen ("voroom.inp", "r", stdin);
	freopen ("voroom.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}