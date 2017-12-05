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
bool g[maxn];
void input ()
{
	cin >> n;
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == '.') g[i] = 1;
		}

}
struct co
{
	int x, y;
	co (int xx, int yy)
	{
		x
	}
};
struct rec
{
	coord a, b;
};
void split (int row, int last_row)
{
	int last = 1;
	for (int j = 1; j <= n; ++j)
	{

	}
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