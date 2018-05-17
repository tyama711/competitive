#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

struct custom_compare {
  bool operator()(const pair<ll, int>& lhs, const pair<ll, int>& rhs) {
    return lhs.first < rhs.first;
  }
};

int main(int argc, char* argv[]) {
  int N;
  vector<ll> part_sum;
  ll ans = LLONG_MAX;

  cin >> N;

  part_sum.resize(N + 1);

  part_sum[0] = 0;
  FOR(i, N) {
    int tmp;

    cin >> tmp;

    part_sum[i + 1] = part_sum[i] + tmp;
  }

  FOR(i, N - 1) { ans = MIN(ans, abs(part_sum[N] - 2 * part_sum[i + 1])); }

  cout << ans << endl;

  return 0;
}
