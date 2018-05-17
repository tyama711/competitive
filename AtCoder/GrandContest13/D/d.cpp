#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=3e3;
const int MOD=1e9+7;
int N, M;
int dp_cache[MAXN+1][MAXN+1][2];

int dp(int m, int n, int k) {
    if (dp_cache[m][n][k] != 0)
        return dp_cache[m][n][k];

    if (k == 0 && m < n)
        return 0;
    if (m == 0)
        return 1;

    int ans;
    if (n == 0)
        ans = ((ll)dp(m-1, 0, 1) + dp(m-1, 1, 1)) % MOD;
    else if (n == 1)
        ans = ((ll)dp(m-1, 0, 1) + dp(m-1, 1, k) + dp(m-1, 1, 1) + dp(m-1, 2, k)) % MOD;
    else if (n == N)
        ans = ((ll)dp(m-1, N-1, k) + dp(m-1, N, k)) % MOD;
    else
        ans = ((ll)dp(m-1, n-1, k) + 2LL*dp(m-1, n, k) + dp(m-1, n+1, k)) % MOD;

    dp_cache[m][n][k] = ans;
    return ans;
}

int main(int argc, char *argv[])
{
    cin >> N >> M;

    int ans = dp(M,0,1);
    FOR1(i,1,N+1)
        ans = ((ll)ans + dp(M,i,0)) % MOD;

    cout << ans << endl;
    
    return 0;
}
