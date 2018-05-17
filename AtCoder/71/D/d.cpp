#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=1e5;
const int MAXX=1e9;
const int MOD = 1e9+7;
int n, m;
int x[MAXN], y[MAXN], fac[MAXN+1], inv[MAXN+1], ifac[MAXN+1];

int comb(int n, int r) {
    return (ll)fac[n] * ifac[r] % MOD * ifac[n-r] % MOD;
}

int rects(int w, int h) {
    return comb(w,2) * comb(h,2);
}

int main(int argc, char *argv[])
{
    int ans = 0;
    
    cin >> n >> m;
    FOR(i,n) cin >> x[i];
    FOR(i,m) cin >> y[i];

    fac[0]=1;
    FOR1(i,1,n+1) fac[i]=(ll)fac[i-1]*i%MOD;
    inv[1]=1;
    FOR1(i,2,n+1) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    ifac[0]=1;
    FOR1(i,1,n+1) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

    FOR(i,n-1) {
        FOR(j,m-1) {
            ans += (ll)(x[i+1]-x[i]) * (y[j+1]-y[j]) % MOD
                * (rects(n,m)
                   - (rects(n,j+1) + rects(n,m-j-1) + rects(i+1,m) + rects(n-i-1,m))
                   + (rects(i+1,j+1) + rects(i+1,m-j-1) + rects(n-i-1,j+1) + rects(n-i-1,m-j-1))) % MOD;
            ans %= MOD;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
