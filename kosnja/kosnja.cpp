//code.cpp
#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x)
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
void input ()
{
	cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> n >> m;
		int x = min (n, m);
		cout << max ((x - 1) * 2, 0) << '\n';
	}
}
void solve ()
{

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	// freopen ("kosnja.inp", "r", stdin);
	// freopen ("kosnja.out", "w", stdout);
	input ();
	solve ();
}