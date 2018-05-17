#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN = 2*1e5;
const int MOD = 1e9+7;

int N, X, Y;
int fac[MAXN+1], inv[MAXN+1], ifac[MAXN+1], mn[MAXN+1], c[MAXN+1], w[MAXN+1], same[MAXN+1], fr[MAXN+1];
pair<int, int> mna(0,1e9), mnb(0,1e9);

int comb(int n, int r) {
    return (ll)fac[n] * ifac[r] % MOD * ifac[n-r] % MOD;
}

int main(int argc, char *argv[])
{
    scanf("%d%d%d", &N, &X, &Y);
    
    fac[0]=1;
    FOR1(i,1,N+1) fac[i]=(ll)fac[i-1]*i%MOD;
    inv[1]=1;
    FOR1(i,2,N+1) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    ifac[0]=1;
    FOR1(i,1,N+1) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

    FOR1(i,1,N+1) mn[i] = 1e9;

    FOR1(i,1,N+1) {
        scanf("%d%d", &c[i], &w[i]);
        if (w[i] < mn[c[i]]) mn[c[i]] = w[i];
    }

    FOR1(i,1,N+1) {
        if (mn[i] < mna.second) {
            mnb = mna;
            mna.first = i;
            mna.second = mn[i];
        }
        else if (mn[i] < mnb.second) {
            mnb.first = i;
            mnb.second = mn[i];
        }
    }

    FOR1(i,1,N+1) {
        if (w[i]+mn[c[i]] <= X)
            same[c[i]]++;

        if (c[i] == mna.first && w[i] + mnb.second <= Y)
            fr[c[i]]++;
        else if (c[i] != mna.first && w[i] + mna.second <= Y)
            fr[c[i]]++;
    }

    int ans = 1, S = 0;
    FOR1(i,1,N+1) {
        if ((i == mna.first && mn[i] + mnb.second <= Y) ||
            (i != mna.first && mn[i] + mna.second <= Y)) {
            same[i] = max(same[i], fr[i]);
            ans = (ll)ans * comb(same[i]+S, same[i]) % MOD;
            S += same[i];
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
