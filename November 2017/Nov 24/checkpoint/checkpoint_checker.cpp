#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cassert>
using namespace std;
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _b; ++i)
#define fd(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(x) ((int)(x).size())
#define db(x) cout << #x << " == " << x << endl
#define _ << ", " <<
#define X first
#define Y second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define endl '\n'
#define pc putchar
#define gc getchar
#define bit(i) (1<<(i))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
inline void read(int &x){register int c = gc();x = 0;int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void write(int x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) pc('-');while(i>=0) pc(buffor[i--]);}
inline void writeln(int x){write(x);pc('\n');}

const int nTest=1000;

int Rand(int lo,int hi){
    assert(hi-lo+1>0);
    return rand()%(hi-lo+1)+lo;
}

int main(){
    // fast IO phai xoa
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    srand(time(NULL));

    int n,k;

    ff(iTest,1,nTest){
        ofstream cout("checkpoint.inp");

        n=Rand(1,200); k=Rand(1,min(n,15));
        cout<<n<<' '<<k<<endl;
        ff(i,1,n) cout<<Rand(-100,100)<<' ';
        cout<<endl;

        cout.close();

        system("./checkpoint");
        system("./checkpoint_trau");
        if (system("diff checkpoint.out checkpoint.ans")) return -1;
    }

    return 0;
}