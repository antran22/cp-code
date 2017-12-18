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
typedef pair <int,int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
string s, t;
void input ()
{
	cin >> s >> t;
	n = s.length ();
	m = t.length ();
	s.ins (0, " ");
	t.ins (0, " ");
}
int f[2001][2001];
struct lcs
{
	void calc ()
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				if (s[i] == t[j])
				{
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				f[i][j] = max (f[i][j], max (f[i][j - 1], f[i - 1][j]));
			}
	}
	string out;
	void trace (int i, int j)
	{
		if (i == 0 or j == 0) return;
		if (s[i] == t[j])
		{
			out.pb (s[i]);
			trace (i - 1, j - 1);
		}
		else
		{
			if (f[i - 1][j] == f[i][j - 1])
			{
				if (i > j) trace (i - 1, j);
				else trace (i, j - 1);
			}
			else if (f[i][j] == f[i - 1][j]) trace (i - 1, j);
			else trace (i, j - 1);
		}
	}
	void print ()
	{
		reverse (whole (out));
		cout << out;
	}
};
void lex ()
{
	s.pb (char ('z' + 1));
	t.pb (char ('z' + 1));
	for (int i = 1, j = 1; i <= n + 1 and j <= m + 1;)
	{
		if (s[i] == t[j])
		{
			cout << s[i];
			++i, ++j;
		}
		else if (s[i] == t[j + 1])
	}
};
void solve ()
{
	lcs s;
	s.calc ();
	s.trace (n, m);
	s.print ();
	cout << '\n';
	lex ();
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("lexlcs.inp", "r", stdin);
	freopen ("lexlcs.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}