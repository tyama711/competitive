#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

ull comb_mod(int n, int r, int mod) {
  ull ans = 1;

  for (int i = n; i > n - r; i--) {
    ans *= (ull)i;
    ans %= (ull)mod;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  int N, M;
  ull MOD = 1e9 + 7;
  ull ans;

  cin >> N >> M;

  if (abs(N - M) >= 2) {
    ans = 0ULL;
  } else if (abs(N - M) == 1) {
    ull tmp = comb_mod(MIN(N, M), MIN(N, M), MOD);
    ans = ((tmp * tmp) % MOD * MAX(N, M)) % MOD;
  } else {
    ull tmp = comb_mod(N, N, MOD);
    ans = ((tmp * tmp) % MOD * 2ULL) % MOD;
  }

  cout << ans << endl;

  return 0;
}
