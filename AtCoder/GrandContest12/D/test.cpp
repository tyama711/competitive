#include <stdio.h>

typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN = 200;
const int MOD = 1000000007;

int fac[MAXN+1], inv[MAXN+1], ifac[MAXN+1];

int main(int argc, char *argv[])
{
    fac[0]=1;
    FOR1(i,1,MAXN+1) fac[i]=(ll)fac[i-1]*i%MOD;
    inv[1]=1;
    FOR1(i,2,MAXN+1) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    ifac[0]=1;
    FOR1(i,1,MAXN+1) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

    FOR(i, 100) {
        printf("fac[%d] = %d, ", i, fac[i]);
        printf("inv[%d] = %d, ", i, inv[i]);
        printf("ifac[%d] = %d\n", i, ifac[i]);
    }
    
    return 0;
}

