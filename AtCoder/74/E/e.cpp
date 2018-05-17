#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pairInt;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)

const int MAXN = 300;
const int MOD = 1e9 + 7;

int N, M;
int dp[MAXN + 1][MAXN + 1][MAXN + 1];
multimap<pairInt, int> cond;

int main(int argc, char *argv[]) {
  cin >> N >> M;

  FOR(i, M) {
    int l, r, x;
    cin >> l >> r >> x;
    cond.insert(make_pair(make_pair(r, x), l));
  }

  dp[0][0][0] = 1;
  FOR1(i, 1, N + 1) {
    FOR(j, max(1, i - 1)) {
      FOR(k, max(1, j)) {
        for (auto it = cond.find(make_pair(i, 3)); it != cond.end(); it++) {
          if (k < it->second) goto END_OF_LOOP1;
        }
        for (auto it = cond.find(make_pair(i, 2)); it != cond.end(); it++) {
          if (it->second <= k || j < it->second) goto END_OF_LOOP1;
        }
        for (auto it = cond.find(make_pair(i, 1)); it != cond.end(); it++) {
          if (it->second <= j) goto END_OF_LOOP1;
        }

        if (j == 0) {
          dp[i][0][0] = dp[i - 1][0][0];
          dp[0][i][0] = dp[0][i - 1][0];
          dp[0][0][i] = dp[0][0][i - 1];
        } else {
          dp[i][j][k] += dp[i - 1][j][k];
          dp[i][k][j] += dp[i - 1][k][j];
          dp[j][i][k] += dp[j][i - 1][k];
          dp[j][k][i] += dp[j][k][i - 1];
          dp[k][i][j] += dp[k][i - 1][j];
          dp[k][j][i] += dp[k][j][i - 1];
        }
      END_OF_LOOP1:
        ;
      }
    }

    int j = i - 1;
    FOR(k, j) {
      for (auto it = cond.find(make_pair(i, 3)); it != cond.end(); it++) {
        if (k < it->second) goto END_OF_LOOP2;
      }
      for (auto it = cond.find(make_pair(i, 2)); it != cond.end(); it++) {
        if (it->second <= k || j < it->second) goto END_OF_LOOP2;
      }
      for (auto it = cond.find(make_pair(i, 1)); it != cond.end(); it++) {
        if (it->second <= j) goto END_OF_LOOP2;
      }

      FOR(l, j) {
        if (l == k && l != 0) continue;
        dp[i][j][k] = ((ll)dp[i][j][k] + dp[l][j][k]) % MOD;
        dp[i][k][j] = ((ll)dp[i][k][j] + dp[l][k][j]) % MOD;
        dp[j][i][k] = ((ll)dp[j][i][k] + dp[j][l][k]) % MOD;
        dp[j][k][i] = ((ll)dp[j][k][i] + dp[j][k][l]) % MOD;
        dp[k][i][j] = ((ll)dp[k][i][j] + dp[k][l][j]) % MOD;
        dp[k][j][i] = ((ll)dp[k][j][i] + dp[k][j][l]) % MOD;
      }
    END_OF_LOOP2:
      ;
    }
  }

  ll ans = 3 * dp[N][0][0];
  FOR1(j, 1, N) {
    FOR(k, j) {
      ans += dp[N][j][k];
      ans += dp[N][k][j];
      ans += dp[j][N][k];
      ans += dp[j][k][N];
      ans += dp[k][j][N];
      ans += dp[k][N][j];
      ans %= MOD;
    }
  }

  cout << ans << endl;

  return 0;
}
