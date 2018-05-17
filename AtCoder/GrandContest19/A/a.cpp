#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int Q, H, S, D, N;

  cin >> Q >> H >> S >> D;
  cin >> N;

  int price1 = min(4 * Q, 2 * H);
  price1 = min(price1, S);

  int price2 = min(2 * price1, D);

  ll ans = (ll)(N/2) * price2;
  ans += (ll)(N%2) * price1;

  cout << ans << endl;

  return 0;
}
