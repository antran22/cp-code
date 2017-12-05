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
int n, k, m, mod = 1e9 + 7;
struct matrix
{
	vector <vi> a;
	int size;
	void resize (int s)
	{
		size = s;
		a.resize (size, vi (size, 0));
	}
	void init (vi b, int s)
	{
		resize (s);
		int x = 0;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j) a[i] [j] = b[x++];
		}
	}
	void print ()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j) cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
	matrix operator * (matrix h)
	{
		matrix res;
		res.resize (size);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				for (int p = 0; p < size; ++p)
					res.a[i][j] = (res.a[i][j] + (ll) (a[i][p]) * h.a[p][j]) % mod;
		return res;
	}
	void operator = (matrix h)
	{
		if (size != h.size)
			resize (h.size);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				a[i][j] = h.a[i][j];
	}
};
mat indentity (int size)
{
	mat res;
	res.resize (size);
	for (int i = 0; i < size; ++i)
		res[i][i] = 1;
	return res;
}
mat i[3] = indentity (2);
mat mat_mul (mat a, ll p)
{
	if (p == 0) return i[a.size];
	mat x = mat_mul (a, p / 2);
	x = x * x;
	if (p % 2) x = x * a;
	return x;
}
void calc_f (int beg)
{
	matrix trans;
	trans.init ({0, 1, 1, 1}, 2);
}
void input ()
{
	
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
	freopen ("dna.inp", "r", stdin);
	freopen ("dna.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}
