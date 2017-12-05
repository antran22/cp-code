#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 55;
const int MAX = 1e6+111;

int n, k;
int dx[2*N], dy[2*N], dz[2*N];
int fx[MAX], fy[MAX], fz[MAX];
int maxX, maxY, maxZ;
int F[2*N][2*N][2*N];
ll res;

struct Point{
    int x, y, z;
} A[N][2];

void magic(map<int,bool> &X, int d[], int f[], int &mx){
    memset(d,255,sizeof(d));
    memset(f,255,sizeof(f));
    int cur;
    cur = 0;
    for(auto i = X.begin(); i != X.end(); i++){
        d[++cur] = i->first;
        f[i->first] = cur;
    }
    mx = cur;
}

void compress(){
    map<int,bool> X, Y, Z;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            X[A[i][j].x] = 1;
            Y[A[i][j].y] = 1;
            Z[A[i][j].z] = 1;
        }
    }
    magic(X,dx,fx,maxX);
    magic(Y,dy,fy,maxY);
    magic(Z,dz,fz,maxZ);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            A[i][j].x = fx[A[i][j].x];
            A[i][j].y = fy[A[i][j].y];
            A[i][j].z = fz[A[i][j].z];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CUBE.inp", "r", stdin);
    freopen("CUBE.out", "w", stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            cin>>A[i][j].x>>A[i][j].y>>A[i][j].z;
        }
    }
    compress();
    memset(F,0,sizeof(F));
    for(int i = 1; i <= n; i++){
        Point a = A[i][0];
        Point b = A[i][1];
        F[a.x][a.y][a.z]++;
        F[b.x][a.y][a.z]--;
        F[a.x][b.y][a.z]--;
        F[a.x][a.y][b.z]--;
        F[a.x][b.y][b.z]++;
        F[b.x][a.y][b.z]++;
        F[b.x][b.y][a.z]++;
        F[b.x][b.y][b.z]--;
    }
    for(int x = 1; x <= maxX; x++){
        for(int y = 1; y <= maxY; y++){
            for(int z = 1; z <= maxZ; z++){
                F[x][y][z] += F[x-1][y][z]+F[x][y-1][z]+F[x][y][z-1];
                F[x][y][z] -= F[x][y-1][z-1]+F[x-1][y][z-1]+F[x-1][y-1][z];
                F[x][y][z] += F[x-1][y-1][z-1];
            }
        }
    }
    res = 0;
    for(int x = 1; x <= maxX; x++){
        for(int y = 1; y <= maxY; y++){
            for(int z = 1; z <= maxZ; z++){
                if(F[x][y][z]>=k){
                    ll c = (ll)(dx[x+1]-dx[x])*(dy[y+1]-dy[y])*(dz[z+1]-dz[z]);
                    res += c;
                }
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}