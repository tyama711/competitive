#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=1e6;
const int MOD=1e9+7;
int n;
vector<ll> A;

int main(int argc, char *argv[])
{
    ll ans = 0;
    cin >> n;
    A.resize(n+1);
    A[1] = A[2] = 1;
    FOR1(i,3,n+1) A[i] = (2*A[i-1] - A[i-2] + A[i-3] + MOD) % MOD;
    FOR(i,n) ans = (ans + (A[i] * (n-1)) % MOD * (n-1)) % MOD;
    FOR(i,n-1) ans = (ans + (i+1)*A[i]) % MOD;
    ans = (ans + (n-1)*A[n-1] + n*A[n]) % MOD;
    cout << ans << endl;

    return 0;
}
